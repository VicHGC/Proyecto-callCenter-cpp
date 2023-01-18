#include <iostream>
#include "hour.hpp"
#include "name.hpp"
#include "date.hpp"
#include "call.hpp"

#include "calllist.hpp"
#include "agentmenu.hpp"
#include "agentlist.hpp"

#include "callmenu.hpp"

using namespace std;

int main()
{
    AgentList myAgentList;
    AgentMenu myMenu(myAgentList);
    return 0;
}
