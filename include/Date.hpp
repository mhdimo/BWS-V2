#ifndef DATE_HPP
#define DATE_HPP

#include "common.h"

/**
 * @class Date
 * @brief A class to represent a date with day, month, and year.
 */
class Date {
public:
    /**
     * @brief Constructor to initialize a Date object.
     * @param day The day of the date.
     * @param month The month of the date.
     * @param year The year of the date.
     */
    Date(int day, int month, int year) noexcept;

    /**
     * @brief Parses a date string in the format "dd-mm-yyyy" and returns a Date object.
     * @param dateString The date string to parse.
     * @return A Date object representing the parsed date.
     * @throws std::invalid_argument if the format is invalid.
     */
    static Date parseDate(const std::string &dateString);

    /**
     * @brief Gets the day of the date.
     * @return The day of the date.
     */
    int getDay() const noexcept { return day; }

    /**
     * @brief Gets the month of the date.
     * @return The month of the date.
     */
    int getMonth() const noexcept { return month; }

    /**
     * @brief Gets the year of the date.
     * @return The year of the date.
     */
    int getYear() const noexcept { return year; }

    /**
     * @brief Prints the date in the format "dd-mm-yyyy".
     */
    void printDate() const noexcept;

private:
    int day, month, year;

    /**
     * @brief Validates if the provided date is valid.
     * @throws std::invalid_argument if the date is invalid.
     */
    void validate() const;
};

#endif // DATE_HPP