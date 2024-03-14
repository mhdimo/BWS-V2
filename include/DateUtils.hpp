#ifndef DATEUTILS_HPP
#define DATEUTILS_HPP

#include <vector>
#include "Date.hpp"

void splitDateArrays(const std::vector<Date>& allDates, std::vector<Date>& arrayN1, std::vector<Date>& arrayN2, std::vector<Date>& arrayN3);
Date getCurrentDate();
int calculateMonthsDifference(const Date& date1, const Date& date2);

#endif // DATEUTILS_HPP
