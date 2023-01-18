#ifndef NAME_HPP_INCLUDED
#define NAME_HPP_INCLUDED

#include <string>
#include <iostream>


class Name{
private:
    std::string last;
    std::string first;
public:
    Name();
    Name(const Name&);

    std::string getLast() const;
    std::string getFirst() const;

    std::string toString() const;

    void setLast(const std::string&);
    void setFirst(const std::string&);

    Name& operator = (const Name&);

    bool operator == (const Name&);
    bool operator != (const Name&);
    bool operator < (const Name&);
    bool operator <= (const Name&);
    bool operator > (const Name&);
    bool operator >= (const Name&);

    friend std::ostream& operator << (std::ostream&, const Name&);
    friend std::istream& operator >> (std::istream&, Name&);

};

#endif // NAME_HPP_INCLUDED
