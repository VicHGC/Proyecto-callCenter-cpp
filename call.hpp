#ifndef CALL_HPP_INCLUDED
#define CALL_HPP_INCLUDED

#include <string>
#include <iostream>

#include "name.hpp"
#include "date.hpp"
#include "hour.hpp"

class Call{
private:
    Name name;
    std::string number;
    std::string extencion;
    Hour startHour;
    Hour endHour;
    Date date;
public:
    Call();
    Call(const Call&);

    Name getName() const;
    std::string getNumber() const;
    std::string getExtencion() const;
    Hour getStartHour() const;
    Hour getEndHour() const;
    Date getDate() const;

    std::string toString() const;

    void setName(const Name&);
    void setNumber(const std::string&);
    void setExtencion(const std::string&);
    void setStartHour(const Hour&);
    void setEndHour(const Hour&);
    void setDate(const Date&);

    Call& operator = (const Call&);

    bool operator == (const Call&) const;
    bool operator != (const Call&) const;
    bool operator < (const Call&) const;
    bool operator <= (const Call&) const;
    bool operator > (const Call&) const;
    bool operator >= (const Call&) const;

    friend std::ostream& operator << (std::ostream&, const Call&);
    friend std::istream& operator >> (std::istream&, Call&);

};

#endif // CALL_HPP_INCLUDED
