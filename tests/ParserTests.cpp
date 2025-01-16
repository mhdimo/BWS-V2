#include <gtest/gtest.h>
#include "../include/Parser.hpp"
#include "../include/Player.hpp"
#include "../include/Date.hpp"

TEST(ParserTest, ParsePlayerDataTest) {
    std::string filename = "test_player_data.txt";
    std::ofstream file(filename);
    file << "player1; 1000; 2; 01-01-2020; 01-02-2020\n";
    file << "player2; 2000; 1; 01-03-2020\n";
    file.close();

    std::vector<Player> players = parsePlayerData(filename);

    EXPECT_EQ(players.size(), 2);
    EXPECT_EQ(players[0].getUsername(), "player1");
    EXPECT_EQ(players[0].getActualRank(), 1000);
    EXPECT_EQ(players[0].getNumBadges(), 2);
    EXPECT_EQ(players[0].getBadgeDates().size(), 2);
    EXPECT_EQ(players[0].getBadgeDates()[0].getDay(), 1);
    EXPECT_EQ(players[0].getBadgeDates()[0].getMonth(), 1);
    EXPECT_EQ(players[0].getBadgeDates()[0].getYear(), 2020);

    EXPECT_EQ(players[1].getUsername(), "player2");
    EXPECT_EQ(players[1].getActualRank(), 2000);
    EXPECT_EQ(players[1].getNumBadges(), 1);
    EXPECT_EQ(players[1].getBadgeDates().size(), 1);
    EXPECT_EQ(players[1].getBadgeDates()[0].getDay(), 1);
    EXPECT_EQ(players[1].getBadgeDates()[0].getMonth(), 3);
    EXPECT_EQ(players[1].getBadgeDates()[0].getYear(), 2020);
}

TEST(ParserTest, ConvertStringToDateTest) {
    Date date = convertStringToDate("01-01-2020");
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getMonth(), 1);
    EXPECT_EQ(date.getYear(), 2020);
}

TEST(ParserTest, InvalidDateFormatTest) {
    EXPECT_THROW(convertStringToDate("invalid-date"), std::runtime_error);
}
