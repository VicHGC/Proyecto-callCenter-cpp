#include "date.hpp"

using namespace std;

bool Date::isValidPos(const int& y, const int& m, const int& d) {
    int monthDay[] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31};

    if(y == 0) {
        return false;
        }
    if(m < 1 or m > 12) {
        return false;
        }
    if(y % 4 == 0 and (y % 100 != 0 or y % 400 == 0)) {
        monthDay[2]++;
        }

    if(d < 0 or d > monthDay[m]) {
        return false;
        }

    return true;
    }

int Date::toInt() const {
    return year * 10000 + month * 100 + day;
    }

Date::Date() {
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t tt;
    tt = chrono::system_clock::to_time_t (today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);

    year = timeinfo->tm_year + 1900;
    month = timeinfo->tm_mon;
    day = timeinfo->tm_mday;
    }

Date::Date(const Date& d) : year(d.year), month(d.month), day(d.day) { }

int Date::getYear() const {
    return year;
    }

int Date::getMonth() const {
    return month;
    }

int Date::getDay() const {
    return day;
    }

string Date::toString() const {
    char result[11];

    sprintf(result, "%02i/%02i/%04i", day, month, year);

    return result;
    }

Date& Date::operator=(const Date& d) {
    year = d.year;
    month = d.month;
    day = d.day;

    return *this;
    }

void Date::setYear(const int& y) {
    if(isValidPos(y, month, day)) {
        year = y;
        }
    }

void Date::setMonth(const int& m) {
    if(isValidPos(year, m, day)) {
        month = m;
        }
    }

void Date::setDay(const int& d) {
    if(isValidPos(year, month, d)) {
        day = d;
        }
    }

bool Date::operator == (const Date& d) const {
    return toInt() == d.toInt();
    }

bool Date::operator!=(const Date& d) const {
    return !(*this != d);
    }

bool Date::operator<(const Date& d) const {
    return toInt() < d.toInt();
    }

bool Date::operator<=(const Date& d) const {
    return *this < d or *this == d;
    }

bool Date::operator>(const Date& d) const {
    return !(*this <= d);
    }

bool Date::operator>=(const Date& d) const {
    return !(*this < d);
    }

ostream& operator << (ostream& os, const Date& d) {
    os << d.toString();

    return os;
    }

istream& operator >> (istream& is, Date& d) {
    string myInt;

    getline(is, myInt, '/');
    d.day = atoi(myInt.c_str());
    getline(is, myInt, '/');
    d.month = atoi(myInt.c_str());
    getline(is, myInt);
    d.year = atoi(myInt.c_str());

    return is;
    }
