#include "../include/MathUtils.hpp"
#include <cmath>
#include <vector>
#include <iostream>

#define const1 0.99321
#define const2 1.9947

int calculateBWSrankWithDynamicWeights(int actualRank, int noBadges, int sizeofArrayN1, int sizeofArrayN2, int sizeofArrayN3, const std::vector<double>& weights) {
    if (noBadges == 0) {
        return actualRank;
    } else {
        double weightedSum = (sizeofArrayN1 * weights[0]) + (sizeofArrayN2 * weights[1]) + (sizeofArrayN3 * weights[2]);
        double exponent = pow(const1, noBadges * (const2 + weightedSum));
        double bwsRank = pow(actualRank, exponent);

        // Debug: Print calculation details
        std::cout << "Calculating BWS Rank:" << std::endl;
        std::cout << "Actual Rank: " << actualRank << std::endl;
        std::cout << "No Badges: " << noBadges << std::endl;
        std::cout << "Size of Array N1: " << sizeofArrayN1 << std::endl;
        std::cout << "Size of Array N2: " << sizeofArrayN2 << std::endl;
        std::cout << "Size of Array N3: " << sizeofArrayN3 << std::endl;
        std::cout << "Weights: " << weights[0] << ", " << weights[1] << ", " << weights[2] << std::endl;
        std::cout << "Weighted Sum: " << weightedSum << std::endl;
        std::cout << "Exponent: " << exponent << std::endl;
        std::cout << "BWS Rank: " << bwsRank << std::endl;

        return bwsRank;
    }
}