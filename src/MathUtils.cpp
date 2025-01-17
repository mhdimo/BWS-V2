#include "../include/MathUtils.hpp"
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

std::vector<double> calculateDynamicWeights(int noBadges) {
    std::vector<double> weights(3);
    weights[0] = weight1 * (1 + noBadges * 0.1);
    weights[1] = weight2 * (1 + noBadges * 0.1);
    weights[2] = weight3 * (1 + noBadges * 0.1);
    return weights;
}

int calculateBWSrankWithDynamicWeights(int actualRank, int noBadges, int sizeofArrayN1, int sizeofArrayN2, int sizeofArrayN3) {
    if (noBadges == 0) {
        return actualRank;
    } else {
        std::vector<double> weights = calculateDynamicWeights(noBadges);
        return pow(actualRank,
                   pow(const1, noBadges * (const2 + (
                           (sizeofArrayN1 * weights[0]) +
                           (sizeofArrayN2 * weights[1]) +
                           (sizeofArrayN3 * weights[2])))));
    }
}
