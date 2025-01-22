#ifndef WEIGHTGENERATOR_HPP
#define WEIGHTGENERATOR_HPP

#include "common.h"


class WeightGenerator {
public:
    WeightGenerator();

    /**
     * @brief Trains the weight generator using a given dataset.
     * @param data The training dataset where each sample includes input features and a target value.
     */
    void train(const std::vector<std::vector<double>>& data);

    /**
     * @brief Predicts the weights for a given key and features.
     * @param key The key to look up in the cache.
     * @param features The input features used to predict weights.
     * @return A vector of predicted weights.
     */
    std::vector<double> predict(const std::string& key, const std::vector<double>& features);

    /**
     * @brief Saves the cache to a file.
     * @param filename The filename where the cache is saved.
     */
    void saveCache(const std::string& filename) const;

    /**
     * @brief Loads the cache from a file.
     * @param filename The filename where the cache is loaded from.
     */
    void loadCache(const std::string& filename);

    /**
     * @brief Adds a new entry to the cache.
     * @param key The key associated with the weights.
     * @param weightsVec The weights to store in the cache.
     */
    void addToCache(const std::string& key, const std::vector<double>& weightsVec);

    /**
     * @brief Retrieves the entire cache.
     * @return A reference to the cache containing key-weight pairs.
     */
    const std::unordered_map<std::string, std::vector<double>>& getCache() const;

private:
    void updateWeights(const std::vector<double>& inputs, double target, double learningRate);

    std::vector<double> weights;
    std::unordered_map<std::string, std::vector<double>> cache;
};

#endif // WEIGHTGENERATOR_HPP
