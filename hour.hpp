#ifndef HOUR_HPP_INCLUDED
#define HOUR_HPP_INCLUDED

#include <string>
#include <chrono>
#include <cstdlib>
#include <iostream>

class Hour {
    private:
        int hour;
        int minute;

        bool isValid(const int&, const int&) const;

        int toInt() const;
    public:
        Hour();
        Hour(const Hour&);
        Hour(const int&, const int&);

        int getHour() const;
        int getMinute() const;

        std::string toString() const;

        void setHour(const int&);
        void setMinute(const int&);

        Hour& operator = (const Hour&);

        bool operator == (const Hour&) const;
        bool operator != (const Hour&) const;
        bool operator < (const Hour&) const;
        bool operator <= (const Hour&) const;
        bool operator > (const Hour&) const;
        bool operator >= (const Hour&) const;

        friend std::ostream& operator << (std::ostream&, const Hour&);
        friend std::istream& operator >> (std::istream&, Hour&);

    };

#endif // HOUR_HPP_INCLUDED
