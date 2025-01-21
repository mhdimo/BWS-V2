#include "../include/MathUtils.hpp"
#include "../include/WeightGenerator.hpp"
#include <cmath>
#include <vector>

#define const1 0.99321
#define const2 1.9947

#define weight1 1.35 // 0 to 6 months
#define weight2 0.85 // 6 to 12 months
#define weight3 0.45 // 12 to any months

int calculateBWSrank(int actualRank, int noBadges, int sizeofArrayN1, int sizeofArrayN2, int sizeofArrayN3) {
    return calculateBWSrankWithDynamicWeights(actualRank, noBadges, sizeofArrayN1, sizeofArrayN2, sizeofArrayN3);
}

int calculateBWSrankWithDynamicWeights(int actualRank, int noBadges, int sizeofArrayN1, int sizeofArrayN2, int sizeofArrayN3) {
    if (noBadges == 0) {
        return actualRank;
    } else {
        WeightGenerator weightGenerator;
        std::vector<double> weights = weightGenerator.predict({static_cast<double>(noBadges), static_cast<double>(sizeofArrayN1), static_cast<double>(sizeofArrayN2), static_cast<double>(sizeofArrayN3)});
        
        return pow(actualRank,
                   pow(const1, noBadges * (const2 + (
                           (sizeofArrayN1 * weights[0]) +
                           (sizeofArrayN2 * weights[1]) +
                           (sizeofArrayN3 * weights[2])))));
    }
}
