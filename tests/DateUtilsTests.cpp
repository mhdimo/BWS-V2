#include <gtest/gtest.h>
#include "../include/DateUtils.hpp"

TEST(DateUtilsTest, SplitDateArraysTest) {
    std::vector<Date> allDates = {Date(1, 1, 2020), Date(1, 7, 2020), Date(1, 1, 2021)};
    std::vector<Date> arrayN1, arrayN2, arrayN3;

    splitDateArrays(allDates, arrayN1, arrayN2, arrayN3);

    EXPECT_EQ(arrayN1.size(), 1);
    EXPECT_EQ(arrayN2.size(), 1);
    EXPECT_EQ(arrayN3.size(), 1);
}

TEST(DateUtilsTest, GetCurrentDateTest) {
    Date currentDate = getCurrentDate();
    time_t now = time(0);
    tm* ltm = localtime(&now);

    EXPECT_EQ(currentDate.getDay(), ltm->tm_mday);
    EXPECT_EQ(currentDate.getMonth(), 1 + ltm->tm_mon);
    EXPECT_EQ(currentDate.getYear(), 1900 + ltm->tm_year);
}

TEST(DateUtilsTest, CalculateMonthsDifferenceTest) {
    Date date1(1, 1, 2020);
    Date date2(1, 7, 2020);

    int monthsDifference = calculateMonthsDifference(date1, date2);

    EXPECT_EQ(monthsDifference, 6);
}
