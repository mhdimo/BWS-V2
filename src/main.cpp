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

int main() {
    std::string filename = "player_data.txt";

    WeightGenerator weightGenerator;
    weightGenerator.loadCache("weight_cache.txt");

    // Clear the results file at the beginning
    std::ofstream clearFile("results.txt", std::ios::out);
    clearFile.close();

    try {
        std::vector<Player> players = parsePlayerData(filename);
        std::vector<std::vector<double>> trainingData;

        // Prepare training data
        for (Player& player : players) {
            std::vector<Date> arrayN1, arrayN2, arrayN3;
            splitDateArrays(player.getBadgeDates(), arrayN1, arrayN2, arrayN3);

            int sizeofArrayN1 = arrayN1.size();
            int sizeofArrayN2 = arrayN2.size();
            int sizeofArrayN3 = arrayN3.size();

            std::vector<double> features = {
                static_cast<double>(player.getNumBadges()),
                static_cast<double>(sizeofArrayN1),
                static_cast<double>(sizeofArrayN2),
                static_cast<double>(sizeofArrayN3)
            };

            // Add features and actual rank to training data
            features.push_back(static_cast<double>(player.getActualRank()));
            trainingData.push_back(features);
        }

        // Train the weight generator with the prepared training data
        weightGenerator.train(trainingData);

        // Predict and update BWS rank for each player
        for (Player& player : players) {
            std::vector<Date> arrayN1, arrayN2, arrayN3;
            splitDateArrays(player.getBadgeDates(), arrayN1, arrayN2, arrayN3);

            int sizeofArrayN1 = arrayN1.size();
            int sizeofArrayN2 = arrayN2.size();
            int sizeofArrayN3 = arrayN3.size();

            std::vector<double> features = {
                static_cast<double>(player.getNumBadges()),
                static_cast<double>(sizeofArrayN1),
                static_cast<double>(sizeofArrayN2),
                static_cast<double>(sizeofArrayN3)
            };

            // Get dynamic weights using the predict method
            std::vector<double> dynamicWeights = weightGenerator.predict(player.getUsername(), features);

            // Calculate BWS rank with dynamic weights
            double bwsRank = calculateBWSrankWithDynamicWeights(
                player.getActualRank(),
                player.getNumBadges(),
                sizeofArrayN1,
                sizeofArrayN2,
                sizeofArrayN3,
                dynamicWeights
            );

            player.setBWSRank(bwsRank);
            weightGenerator.addToCache(player.getUsername(), dynamicWeights);
        }

        // Write results to the output file
        std::ofstream outputFile("results.txt", std::ios::app);
        if (!outputFile.is_open()) {
            throw std::runtime_error("Unable to open results file");
        }

        for (const auto& player : players) {
            outputFile << "Username: " << player.getUsername() << std::endl;
            outputFile << "New BWS Rank: " << player.getBWSRank() << std::endl;
            outputFile << std::endl;
        }
        std::cout << "Data Parsed! Have fun screening =)" << std::endl;
        outputFile.close();

        // Save the updated cache and log entries
        weightGenerator.saveCache("weight_cache.txt");

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}