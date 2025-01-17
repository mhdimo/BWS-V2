#ifndef WEIGHTGENERATOR_HPP
#define WEIGHTGENERATOR_HPP

#include <vector>
#include <string>
#include <unordered_map>

/**
 * @class WeightGenerator
 * @brief A class for dynamic weight generation using a simple neural network.
 */
class WeightGenerator {
public:
    /**
     * @brief Constructor to initialize the WeightGenerator.
     */
    WeightGenerator();

    /**
     * @brief Trains the neural network with the given data.
     * @param data The training data.
     */
    void train(const std::vector<std::vector<double>>& data);

    /**
     * @brief Predicts the weights based on the input features.
     * @param features The input features.
     * @return A vector of predicted weights.
     */
    std::vector<double> predict(const std::vector<double>& features);

    /**
     * @brief Saves the weights to a cache file.
     * @param filename The name of the cache file.
     */
    void saveCache(const std::string& filename);

    /**
     * @brief Loads the weights from a cache file.
     * @param filename The name of the cache file.
     */
    void loadCache(const std::string& filename);

private:
    std::vector<std::vector<double>> weights;
    std::unordered_map<std::string, std::vector<double>> cache;
};

#endif // WEIGHTGENERATOR_HPP
