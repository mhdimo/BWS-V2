#ifndef WEIGHTGENERATOR_HPP
#define WEIGHTGENERATOR_HPP

#include <vector>
#include <unordered_map>
#include <string>

class WeightGenerator {
public:
    WeightGenerator();
    void train(const std::vector<std::vector<double>>& data);
    std::vector<double> predict(const std::vector<double>& features);
    void saveCache(const std::string& filename);
    void loadCache(const std::string& filename);

private:
    std::vector<double> weights;
    std::unordered_map<std::string, std::vector<double>> cache;
};

#endif // WEIGHTGENERATOR_HPP