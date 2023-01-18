#ifndef AGENTNODE_HPP_INCLUDED
#define AGENTNODE_HPP_INCLUDED

#include "agente.hpp"
#include "agentexception.hpp"

class AgentNode{
private:
    Agent* dataPtr;
    AgentNode* prev;
    AgentNode* next;
public:
    AgentNode();
    AgentNode(const Agent&);

    ~AgentNode();

    Agent* getDataPtr() const;
    Agent getData() const;
    AgentNode* getPrev() const;
    AgentNode* getNext() const;

    void setDataPtr(Agent*);
    void setData(const Agent&);
    void setPrev(AgentNode*);
    void setNext(AgentNode*);
};

#endif // AGENTNODE_HPP_INCLUDED
