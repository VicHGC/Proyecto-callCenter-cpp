#include "call.hpp"

using namespace std;

Call::Call() {}

Call::Call(const Call& c) : name(c.name), number(c.number), extencion(c.extencion), startHour(c.startHour), endHour(c.endHour), date(c.date) { }

Name Call::getName() const {
    return name;
    }

string Call::getNumber() const {
    return number;
    }

string Call::getExtencion() const {
    return extencion;
    }

Hour Call::getStartHour() const {
    return startHour;
    }

Hour Call::getEndHour() const {
    return endHour;
    }

Date Call::getDate() const {
    return date;
    }

string Call::toString() const {
    string resultado;

    resultado += name.toString();
    resultado.resize(17, ' ');
    resultado += " | ";
    resultado += "+" + extencion + " " + number;
    resultado += " | ";
    resultado += startHour.toString();
    resultado += " | ";
    resultado += endHour.toString();
    resultado += " | ";
    resultado += date.toString();

    return resultado;
    }

void Call::setName(const Name& n) {
    name = n;
    }

void Call::setNumber(const std::string& n) {
    number = n;
    }

void Call::setExtencion(const string& e) {
    extencion = e;
    }

void Call::setStartHour(const Hour& s) {
    startHour = s;
    }

void Call::setEndHour(const Hour& e) {
    endHour = e;
    }

void Call::setDate(const Date& d) {
    date = d;
    }

Call& Call::operator=(const Call& c) {
    name = c.name;
    number = c.number;
    extencion = c.extencion;
    startHour = c.startHour;
    endHour = c.endHour;
    date = c.date;

    return *this;
    }

bool Call::operator==(const Call& c) const {
    return number == c.number;
    }

bool Call::operator!=(const Call& c) const {
    return number != c.number;
    }

bool Call::operator<(const Call& c) const {
    return number < c.number;
    }

bool Call::operator<=(const Call& c) const {
    return number <= c.number;
    }

bool Call::operator>(const Call& c) const {
    return number > c.number;
    }

bool Call::operator>=(const Call& c) const {
    return number >= c.number;
    }

ostream& operator << (ostream& os, const Call& c){
    os << c.name << endl;
    os << c.extencion << endl;
    os << c.number << endl;
    os << c.startHour << endl;
    os << c.endHour << endl;
    os << c.date;

    return os;
    }

istream& operator >> (istream& is, Call& c){
    is >> c.name;
    getline(is, c.extencion);
    getline(is, c.number);
    is >> c.startHour;
    is >> c.endHour;
    is >> c.date;

    return is;
    }
