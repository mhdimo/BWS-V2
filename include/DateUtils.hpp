#ifndef DATEUTILS_HPP
#define DATEUTILS_HPP

#include <vector>
#include "Date.hpp"

/**
 * @brief Splits a vector of dates into three separate arrays based on the difference in months from the current date.
 * @param allDates The vector of all dates to be split.
 * @param arrayN1 The vector to store dates within 0 to 6 months difference.
 * @param arrayN2 The vector to store dates within 6 to 12 months difference.
 * @param arrayN3 The vector to store dates with more than 12 months difference.
 */
void splitDateArrays(const std::vector<Date>& allDates, std::vector<Date>& arrayN1, std::vector<Date>& arrayN2, std::vector<Date>& arrayN3);

/**
 * @brief Gets the current date.
 * @return A Date object representing the current date.
 */
Date getCurrentDate();

/**
 * @brief Calculates the difference in months between two dates.
 * @param date1 The first date.
 * @param date2 The second date.
 * @return The difference in months between the two dates.
 */
int calculateMonthsDifference(const Date& date1, const Date& date2);

#endif // DATEUTILS_HPP
