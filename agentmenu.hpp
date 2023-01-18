#ifndef AGENTMENU_HPP_INCLUDED
#define AGENTMENU_HPP_INCLUDED

#include <iostream>
#include <string>

#include "agentlist.hpp"
#include "callmenu.hpp"
#include "calllist.hpp"
#include "agente.hpp"
#include "call.hpp"
#include "hour.hpp"
#include "name.hpp"
#include "date.hpp"

class AgentMenu {
    private:
        void mainMenu(AgentList&);

        void addAgent(AgentList&);

        void delAgent(AgentList&);

        void searchAgent(AgentList&);

        void delAllAgent(AgentList&);

        void showAgents(AgentList&);

        void writeToDisk(AgentList&);

        void readFromDisk(AgentList&);

        void enterToContinue();

    public:
        AgentMenu(AgentList&);
    };

#endif // AGENTMENU_HPP_INCLUDED
