#include "../include/DateUtils.hpp"
#include <chrono>
#include <string>
#include <iostream>

void splitDateArrays(const std::vector<Date>& allDates, std::vector<Date>& arrayN1, std::vector<Date>& arrayN2, std::vector<Date>& arrayN3) {
    // Obtain the current date
    Date currentDate = getCurrentDate(); // substitue the real function to get the current date

    for (const auto& date : allDates) {
        // calculate the difference in months from the current date and the badge date
        int monthsDifference = calculateMonthsDifference(date, currentDate);
        // add the data on the array corresponding to the difference in months
        if (monthsDifference >= 0 && monthsDifference <= 6) {
            arrayN1.push_back(date);
        } else if (monthsDifference > 6 && monthsDifference <= 12) {
            arrayN2.push_back(date);
        } else {
            arrayN3.push_back(date);
        }
    }
}

Date getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    time_t now_time = std::chrono::system_clock::to_time_t(now);
    struct tm* timeinfo = localtime(&now_time);

    int year = timeinfo->tm_year + 1900; // tm_year represents yyyy - 1900
    int month = timeinfo->tm_mon + 1;    // tm_mon goes from 0 to 11
    int day = timeinfo->tm_mday;         // day of the month

    return Date(day, month, year);
}

int calculateMonthsDifference(const Date& date1, const Date& date2) {
    int monthsDifference = (date2.getYear() - date1.getYear()) * 12;
    monthsDifference += date2.getMonth() - date1.getMonth();
    return monthsDifference;
}

void Date::printDate() const {
    std::cout << day << "-" << month << "-" << year << std::endl;
}