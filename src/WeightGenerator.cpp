#include "../include/WeightGenerator.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <random>

WeightGenerator::WeightGenerator() {
    // Initialize weights and cache
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    // Initialize weights with random values
    weights = {dis(gen), dis(gen), dis(gen)};
}

void WeightGenerator::train(const std::vector<std::vector<double>>& data) {
    // Implement a simple training algorithm for the neural network
    double learningRate = 0.01;
    for (const auto& sample : data) {
        std::vector<double> inputs = sample;
        inputs.pop_back(); // Remove the last element which is the target value
        double target = sample.back();

        // Forward pass
        double output = 0.0;
        for (size_t i = 0; i < weights.size(); ++i) {
            output += inputs[i] * weights[i];
        }

        // Calculate error
        double error = target - output;

        // Backpropagation
        for (size_t i = 0; i < weights.size(); ++i) {
            weights[i] += learningRate * error * inputs[i];
        }
    }
}

std::vector<double> WeightGenerator::predict(const std::vector<double>& features) {
    // Implement a simple neural network prediction algorithm
    std::vector<double> predictedWeights(3);
    // Example prediction logic
    for (size_t i = 0; i < predictedWeights.size(); ++i) {
        predictedWeights[i] = features[i] * weights[i]; // Dummy logic
    }

    // Populate the cache with the predicted weights
    std::ostringstream keyStream;
    for (const auto& feature : features) {
        keyStream << feature << "_";
    }
    std::string key = keyStream.str();
    cache[key] = predictedWeights;

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