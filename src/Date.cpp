#include "../include/Date.hpp"
#include <sstream>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

Date Date::parseDate(const std::string &dateString) {
    std::istringstream dateStream(dateString);
    int day, month, year;
    char discard;
    dateStream >> day >> discard >> month >> discard >> year;
    return Date(day, month, year);
}
