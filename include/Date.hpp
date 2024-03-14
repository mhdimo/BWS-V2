#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
public:
    Date(int day, int month, int year);
    static Date parseDate(const std::string& dateString);

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void printDate() const;
private:
    int day, month, year;
};

#endif // DATE_HPP
