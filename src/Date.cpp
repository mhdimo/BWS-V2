#include "../include/Date.hpp"
#include <sstream>
#include <iomanip>

// Constructor with validation
Date::Date(int day, int month, int year) noexcept : day(day), month(month), year(year) {
    validate();
}

// Static method to parse a date string
Date Date::parseDate(const std::string &dateString) {
    std::istringstream dateStream(dateString);
    int day, month, year;
    char delimiter;

    if (!(dateStream >> day >> delimiter >> month >> delimiter >> year) || delimiter != '-') {
        throw std::invalid_argument("Invalid date format. Expected format: dd-mm-yyyy");
    }

    return Date(day, month, year);
}

// Prints the date in the format "dd-mm-yyyy"
void Date::printDate() const noexcept {
    std::cout << std::setw(2) << std::setfill('0') << day << "-"
              << std::setw(2) << std::setfill('0') << month << "-"
              << year << std::endl;
}

// Validates the date
void Date::validate() const {
    if (month < 1 || month > 12) {
        throw std::invalid_argument("Invalid month: " + std::to_string(month));
    }

    if (day < 1 || day > 31 || (month == 2 && day > 29) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        throw std::invalid_argument("Invalid day: " + std::to_string(day));
    }

    if (month == 2 && day == 29) {
        // Leap year check
        if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) {
            throw std::invalid_argument("Invalid day: " + std::to_string(day) + " for February in a non-leap year");
        }
    }
}
