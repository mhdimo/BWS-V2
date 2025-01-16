#include <gtest/gtest.h>
#include "../include/MathUtils.hpp"

TEST(MathUtilsTest, CalculateBWSrankNoBadges) {
    int actualRank = 1000;
    int noBadges = 0;
    int sizeofArrayN1 = 0;
    int sizeofArrayN2 = 0;
    int sizeofArrayN3 = 0;

    int bwsRank = calculateBWSrank(actualRank, noBadges, sizeofArrayN1, sizeofArrayN2, sizeofArrayN3);

    EXPECT_EQ(bwsRank, actualRank);
}

TEST(MathUtilsTest, CalculateBWSrankWithBadges) {
    int actualRank = 1000;
    int noBadges = 5;
    int sizeofArrayN1 = 3;
    int sizeofArrayN2 = 1;
    int sizeofArrayN3 = 1;

    int bwsRank = calculateBWSrank(actualRank, noBadges, sizeofArrayN1, sizeofArrayN2, sizeofArrayN3);

    EXPECT_NEAR(bwsRank, 1000, 1); // Adjust the expected value based on the formula
}
