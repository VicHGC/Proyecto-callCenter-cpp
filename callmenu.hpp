#ifndef CALLMENU_HPP_INCLUDED
#define CALLMENU_HPP_INCLUDED

#include <string>
#include <iostream>

#include "call.hpp"
#include "calllist.hpp"
#include "callexception.hpp"
#include "hour.hpp"
#include "name.hpp"
#include "date.hpp"

class CallMenu{
private:
    void addCall(CallList&);

    void delCall(CallList&);

    void modCall(CallList&);

    void delAllCall(CallList&);

    void showCall(CallList&);

    void enterToContinue();

    void mainMenu(CallList&);

public:
    CallMenu(CallList&);

};






#endif // CALLMENU_HPP_INCLUDED
