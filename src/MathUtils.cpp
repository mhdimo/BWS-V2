#include "../include/MathUtils.hpp"
#include <cmath>
#include <vector>

constexpr double CONST1 = 0.99321;
constexpr double CONST2 = 1.9947;

int calculateBWSrankWithDynamicWeights(int actualRank, 
                                       int noBadges, 
                                       int sizeofArrayN1, 
                                       int sizeofArrayN2, 
                                       int sizeofArrayN3, 
                                       const std::vector<double>& weights) noexcept {
    if (noBadges == 0) {
        return actualRank;
    }

    double weightedSum = (sizeofArrayN1 * weights[0]) + 
                         (sizeofArrayN2 * weights[1]) + 
                         (sizeofArrayN3 * weights[2]);

    double exponent = std::pow(CONST1, noBadges * (CONST2 + weightedSum));
    double bwsRank = std::pow(actualRank, exponent);

    return static_cast<int>(bwsRank);
}
