#include "../include/WeightGenerator.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <cmath>

WeightGenerator::WeightGenerator() {
    // Initialize weights with random values between -1.0 and 1.0
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    weights = {dis(gen), dis(gen), dis(gen)};
}

void WeightGenerator::train(const std::vector<std::vector<double>>& data) {
    double learningRate = 0.01;
    
    // Process each sample in the training data
    for (const auto& sample : data) {
        std::vector<double> inputs = sample;
        double target = inputs.back();
        inputs.pop_back(); // Remove target from inputs

        updateWeights(inputs, target, learningRate);
    }
}

void WeightGenerator::updateWeights(const std::vector<double>& inputs, double target, double learningRate) {
    // Forward pass
    double output = 0.0;
    for (size_t i = 0; i < weights.size(); ++i) {
        output += inputs[i] * weights[i];
    }

    // Calculate error
    double error = target - output;

    // Adjust weights
    for (size_t i = 0; i < weights.size(); ++i) {
        weights[i] += learningRate * error * inputs[i];
    }
}

std::vector<double> WeightGenerator::predict(const std::string& key, const std::vector<double>& features) {
    // Check if weights for this key are already in the cache
    auto it = cache.find(key);
    if (it != cache.end()) {
        return it->second;
    }

    // If not cached, calculate new weights
    std::vector<double> predictedWeights(weights.size());
    for (size_t i = 0; i < weights.size(); ++i) {
        predictedWeights[i] = features[i] * weights[i];
    }

    // Add the new weights to the cache
    cache[key] = predictedWeights;
    return predictedWeights;
}

void WeightGenerator::saveCache(const std::string& filename) const {
    std::ofstream file(filename); // Open in write mode to overwrite existing cache
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open cache file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& entry : cache) {
        file << entry.first;
        for (const auto& weight : entry.second) {
            file << " " << weight;
        }
        file << std::endl;
    }
}

void WeightGenerator::loadCache(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open cache file for reading: " << filename << "...Creating one..." << std::endl;
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
}

void WeightGenerator::addToCache(const std::string& key, const std::vector<double>& weightsVec) {
    cache[key] = weightsVec;
}

const std::unordered_map<std::string, std::vector<double>>& WeightGenerator::getCache() const {
    return cache;
}
