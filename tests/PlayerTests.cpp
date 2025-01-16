#include <gtest/gtest.h>
#include "../include/Player.hpp"

TEST(PlayerTest, ConstructorTest) {
    Player player("test_user", 1000, 5);
    EXPECT_EQ(player.getUsername(), "test_user");
    EXPECT_EQ(player.getActualRank(), 1000);
    EXPECT_EQ(player.getNumBadges(), 5);
}

TEST(PlayerTest, GetUsernameTest) {
    Player player("test_user", 1000, 5);
    EXPECT_EQ(player.getUsername(), "test_user");
}

TEST(PlayerTest, GetActualRankTest) {
    Player player("test_user", 1000, 5);
    EXPECT_EQ(player.getActualRank(), 1000);
}

TEST(PlayerTest, GetNumBadgesTest) {
    Player player("test_user", 1000, 5);
    EXPECT_EQ(player.getNumBadges(), 5);
}

TEST(PlayerTest, GetBadgeDatesTest) {
    Player player("test_user", 1000, 5);
    Date date(1, 1, 2020);
    player.addBadgeDate(date);
    std::vector<Date> badgeDates = player.getBadgeDates();
    EXPECT_EQ(badgeDates.size(), 1);
    EXPECT_EQ(badgeDates[0].getDay(), 1);
    EXPECT_EQ(badgeDates[0].getMonth(), 1);
    EXPECT_EQ(badgeDates[0].getYear(), 2020);
}

TEST(PlayerTest, AddBadgeDateTest) {
    Player player("test_user", 1000, 5);
    Date date(1, 1, 2020);
    player.addBadgeDate(date);
    std::vector<Date> badgeDates = player.getBadgeDates();
    EXPECT_EQ(badgeDates.size(), 1);
    EXPECT_EQ(badgeDates[0].getDay(), 1);
    EXPECT_EQ(badgeDates[0].getMonth(), 1);
    EXPECT_EQ(badgeDates[0].getYear(), 2020);
}

TEST(PlayerTest, SetBWSRankTest) {
    Player player("test_user", 1000, 5);
    player.setBWSRank(500);
    EXPECT_EQ(player.getBWSRank(), 500);
}

TEST(PlayerTest, GetBWSRankTest) {
    Player player("test_user", 1000, 5);
    player.setBWSRank(500);
    EXPECT_EQ(player.getBWSRank(), 500);
}
