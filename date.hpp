#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

#include <string>
#include <iostream>
#include <chrono>
#include <cstdlib>

class Date {
    private:
        int year;
        int month;
        int day;

        int toInt() const;

        bool isValidPos(const int&, const int&, const int&);

    public:
        Date();
        Date(const Date&);

        int getYear() const;
        int getMonth() const;
        int getDay() const;

        std::string toString() const;

        Date& operator = (const Date&);

        void setYear(const int&);
        void setMonth(const int&);
        void setDay(const int&);

        bool operator == (const Date&) const;
        bool operator != (const Date&) const;
        bool operator < (const Date&) const;
        bool operator <= (const Date&) const;
        bool operator > (const Date&) const;
        bool operator >= (const Date&) const;

        friend std::ostream& operator << (std::ostream&, const Date&);
        friend std::istream& operator >> (std::istream&, Date&);

    };

#endif // DATE_HPP_INCLUDED
