#include "hour.hpp"

using namespace std;

bool Hour::isValid(const int& h, const int& m) const {
    return h >= 0 and h <= 23 and m >= 0 and m <= 59;
    }

int Hour::toInt() const {
    return hour * 100 + minute;
    }

Hour::Hour() {
    chrono::system_clock::time_point today(chrono::system_clock::now());
    time_t tt;
    tt = chrono::system_clock::to_time_t (today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);

    hour = timeinfo->tm_hour;

    minute = timeinfo->tm_min;
    }

Hour::Hour(const Hour& h) : hour(h.hour), minute(h.minute) { }

Hour::Hour(const int& h, const int& m) {
    if(isValid(h, m)) {
        hour = h;
        minute = m;
        }
    }

int Hour::getHour() const {
    return hour;
    }

int Hour::getMinute() const {
    return minute;
    }

string Hour::toString() const {
    char myTime[6];

    sprintf(myTime, "%02i:%02i", hour, minute);

    return myTime;
    }

void Hour::setHour(const int& h) {
    hour = h;
    }

void Hour::setMinute(const int& m) {
    minute = m;
    }

Hour& Hour::operator=(const Hour& h) {
    hour = h.hour;
    minute = h.minute;

    return *this;
    }

bool Hour::operator == (const Hour& h) const{
    return toInt() == h.toInt();
    }

bool Hour::operator != (const Hour& h) const{
    return !(*this == h);
    }

bool Hour::operator < (const Hour& h) const{
    return toInt() < h.toInt();
    }

bool Hour::operator <= (const Hour& h) const{
    return *this < h or *this == h;
    }

bool Hour::operator > (const Hour& h) const{
    return !(*this <= h);
    }

bool Hour::operator >= (const Hour& h) const{
    return !(*this < h);
    }

ostream& operator << (ostream& os, const Hour& h) {
    os << h.toString();

    return os;
    }

istream& operator >> (istream& is, Hour& h) {
    string myStr;

    getline(is, myStr, ':');
    h.hour = atoi(myStr.c_str());

    getline(is, myStr);
    h.minute = atoi(myStr.c_str());

    return is;
    }

