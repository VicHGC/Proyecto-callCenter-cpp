#ifndef AGENTLIST_HPP_INCLUDED
#define AGENTLIST_HPP_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

#include "agentnode.hpp"
#include "agente.hpp"
#include "agentexception.hpp"

class AgentList{
private:
    AgentNode* header;

    void copyAll(const AgentList&);

    bool isValidPos(AgentNode*) const;

    void swapPtr(AgentNode*, AgentNode*);

    void sortBySpecialty(AgentNode*, AgentNode*);
    void sortByName(AgentNode*, AgentNode*);

public:
    AgentList();
    AgentList(const AgentList&);

    ~AgentList();

    bool isEmpty() const;

    void insertData(AgentNode*, const Agent&);

    void deleteData(AgentNode*);

    AgentNode* getFirstPos() const;
    AgentNode* getLastPos() const;
    AgentNode* getPrevPos(AgentNode*) const;
    AgentNode* getNextPos(AgentNode*) const;

    AgentNode* findData(const Agent&);

    Agent retrieve(AgentNode*) const;

    std::string toString(const int&) const;
    std::string toStringFilt(const std::string&, const int&) const;

    void sortBySpecialty();
    void sortByName();

    void deleteAll();

    AgentList& operator = (const AgentList&);

    void writeToDisk(const std::string&);
    void readFromDisk(const std::string&);

};

#endif // AGENTLIST_HPP_INCLUDED
