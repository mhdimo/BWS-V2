#ifndef DATE_HPP
#define DATE_HPP

#include <string>

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
    Date(int day, int month, int year);

    /**
     * @brief Parses a date string in the format "dd-mm-yyyy" and returns a Date object.
     * @param dateString The date string to parse.
     * @return A Date object representing the parsed date.
     */
    static Date parseDate(const std::string& dateString);

    /**
     * @brief Gets the day of the date.
     * @return The day of the date.
     */
    int getDay() const;

    /**
     * @brief Gets the month of the date.
     * @return The month of the date.
     */
    int getMonth() const;

    /**
     * @brief Gets the year of the date.
     * @return The year of the date.
     */
    int getYear() const;

    /**
     * @brief Prints the date in the format "dd-mm-yyyy".
     */
    void printDate() const;

private:
    int day, month, year;
};

#endif // DATE_HPP
