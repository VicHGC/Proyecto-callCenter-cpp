#include "name.hpp"

using namespace std;

Name::Name() { }

Name::Name(const Name& n) : last(n.last), first(n.first) { }

string Name::getLast() const {
    return last;
    }

string Name::getFirst() const {
    return first;
    }

string Name::toString() const {
    return last + ", " + first;
    }

void Name::setLast(const std::string& l) {
    last = l;
    }

void Name::setFirst(const std::string& f) {
    first = f;
    }

Name& Name::operator=(const Name& n) {
    first = n.first;
    last = n.last;

    return *this;
    }

bool Name::operator == (const Name& n) {
    return toString() == n.toString();
    }

bool Name::operator != (const Name& n) {
    return toString() != n.toString();
    }

bool Name::operator < (const Name& n) {
    return toString() < n.toString();
    }

bool Name::operator <= (const Name& n) {
    return toString() <= n.toString();
    }

bool Name::operator > (const Name& n) {
    return toString() > n.toString();
    }

bool Name::operator >= (const Name& n) {
    return toString() >= n.toString();
    }

ostream& operator << (ostream& os, const Name& n) {
    os << n.last << '|' << n.first;

    return os;
    }

istream& operator >> (istream& is, Name& n) {
    getline(is, n.last, '|');
    getline(is, n.first);

    return is;
    }
