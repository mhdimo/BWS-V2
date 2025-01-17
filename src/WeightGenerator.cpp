#include "../include/WeightGenerator.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

WeightGenerator::WeightGenerator() {
    // Initialize weights and cache
}

void WeightGenerator::train(const std::vector<std::vector<double>>& data) {
    // Implement a simple training algorithm for the neural network
}

std::vector<double> WeightGenerator::predict(const std::vector<double>& features) {
    // Implement a simple neural network prediction algorithm
    std::vector<double> predictedWeights(3);
    // Example prediction logic
    for (size_t i = 0; i < predictedWeights.size(); ++i) {
        predictedWeights[i] = features[i] * 0.1; // Dummy logic
    }
    return predictedWeights;
}

void WeightGenerator::saveCache(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open cache file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& entry : cache) {
        file << entry.first << " ";
        for (const auto& weight : entry.second) {
            file << weight << " ";
        }
        file << std::endl;
    }

    file.close();
}

void WeightGenerator::loadCache(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open cache file for reading: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        iss >> key;
        std::vector<double> weights(3);
        for (auto& weight : weights) {
            iss >> weight;
        }
        cache[key] = weights;
    }

    file.close();
}
