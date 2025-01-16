#include <gtest/gtest.h>
#include "../include/Date.hpp"

TEST(DateTest, ConstructorTest) {
    Date date(1, 1, 2020);
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getMonth(), 1);
    EXPECT_EQ(date.getYear(), 2020);
}

TEST(DateTest, ParseDateTest) {
    Date date = Date::parseDate("01-01-2020");
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getMonth(), 1);
    EXPECT_EQ(date.getYear(), 2020);
}

TEST(DateTest, GetDayTest) {
    Date date(1, 1, 2020);
    EXPECT_EQ(date.getDay(), 1);
}

TEST(DateTest, GetMonthTest) {
    Date date(1, 1, 2020);
    EXPECT_EQ(date.getMonth(), 1);
}

TEST(DateTest, GetYearTest) {
    Date date(1, 1, 2020);
    EXPECT_EQ(date.getYear(), 2020);
}

TEST(DateTest, PrintDateTest) {
    Date date(1, 1, 2020);
    testing::internal::CaptureStdout();
    date.printDate();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1-1-2020\n");
}
