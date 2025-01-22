#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/DateUtils.hpp"
#include "../include/MathUtils.hpp"
#include "../include/Player.hpp"
#include "../include/Parser.hpp"
#include "../include/Date.hpp"
#include "../include/WeightGenerator.hpp"

void prepareTrainingData(const std::vector<Player>& players, std::vector<std::vector<double>>& trainingData) {
    for (const Player& player : players) {
        std::vector<Date> arrayN1, arrayN2, arrayN3;
        splitDateArrays(player.getBadgeDates(), arrayN1, arrayN2, arrayN3);

        // Prepare feature vector for training
        std::vector<double> features = {
            static_cast<double>(player.getNumBadges()),
            static_cast<double>(arrayN1.size()),
            static_cast<double>(arrayN2.size()),
            static_cast<double>(arrayN3.size()),
            static_cast<double>(player.getActualRank()) // Add actual rank as target
        };

        trainingData.push_back(features);
    }
}

void updatePlayerBWSRank(std::vector<Player>& players, WeightGenerator& weightGenerator) {
    for (Player& player : players) {
        std::vector<Date> arrayN1, arrayN2, arrayN3;
        splitDateArrays(player.getBadgeDates(), arrayN1, arrayN2, arrayN3);

        // Prepare feature vector for prediction
        std::vector<double> features = {
            static_cast<double>(player.getNumBadges()),
            static_cast<double>(arrayN1.size()),
            static_cast<double>(arrayN2.size()),
            static_cast<double>(arrayN3.size())
        };

        // Get dynamic weights using the predict method
        std::vector<double> dynamicWeights = weightGenerator.predict(player.getUsername(), features);

        // Calculate BWS rank with dynamic weights
        double bwsRank = calculateBWSrankWithDynamicWeights(
            player.getActualRank(),
            player.getNumBadges(),
            arrayN1.size(),
            arrayN2.size(),
            arrayN3.size(),
            dynamicWeights
        );

        player.setBWSRank(bwsRank);

        // Update cache with the new dynamic weights
        weightGenerator.addToCache(player.getUsername(), dynamicWeights);
    }
}

void writeResults(const std::vector<Player>& players) {
    std::ofstream outputFile("results.txt", std::ios::app);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open results file");
    }

    for (const auto& player : players) {
        outputFile << "Username: " << player.getUsername() << std::endl;
        outputFile << "New BWS Rank: " << player.getBWSRank() << std::endl;
        outputFile << std::endl;
    }

    outputFile.close();
}

int main() {
    std::string filename = "player_data.txt";
    WeightGenerator weightGenerator;

    // Load cached weights
    weightGenerator.loadCache("weight_cache.txt");

    // Clear the results file at the beginning
    std::ofstream clearFile("results.txt", std::ios::out);
    clearFile.close();

    try {
        // Parse player data
        std::vector<Player> players = parsePlayerData(filename);
        std::vector<std::vector<double>> trainingData;

        // Prepare training data
        prepareTrainingData(players, trainingData);

        // Train the weight generator with the prepared training data
        weightGenerator.train(trainingData);

        // Predict and update BWS rank for each player
        updatePlayerBWSRank(players, weightGenerator);

        // Write results to the output file
        writeResults(players);

        std::cout << "Data Parsed! Have fun screening =)" << std::endl;

        // Save the updated cache
        weightGenerator.saveCache("weight_cache.txt");

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
