#include <gtest/gtest.h>
#include "../include/WeightGenerator.hpp"

TEST(WeightGeneratorTest, TrainTest) {
    WeightGenerator weightGenerator;
    std::vector<std::vector<double>> data = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    weightGenerator.train(data);
    // Add assertions to verify the training process
}

TEST(WeightGeneratorTest, PredictTest) {
    WeightGenerator weightGenerator;
    std::vector<double> features = {1.0, 2.0, 3.0};
    std::vector<double> predictedWeights = weightGenerator.predict(features);
    EXPECT_EQ(predictedWeights.size(), 3);
    // Add more assertions to verify the predicted weights
}

TEST(WeightGeneratorTest, SaveCacheTest) {
    WeightGenerator weightGenerator;
    std::vector<double> features = {1.0, 2.0, 3.0};
    weightGenerator.predict(features);
    weightGenerator.saveCache("test_cache.txt");
    // Add assertions to verify the cache file is saved correctly
}

TEST(WeightGeneratorTest, LoadCacheTest) {
    WeightGenerator weightGenerator;
    weightGenerator.loadCache("test_cache.txt");
    std::vector<double> features = {1.0, 2.0, 3.0};
    std::vector<double> predictedWeights = weightGenerator.predict(features);
    EXPECT_EQ(predictedWeights.size(), 3);
    // Add more assertions to verify the loaded cache
}
