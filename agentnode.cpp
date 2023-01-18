#include "agentnode.hpp"

using namespace std;

AgentNode::AgentNode() : dataPtr(nullptr), prev(nullptr), next(nullptr) {}

AgentNode::AgentNode(const Agent& a) {
    dataPtr = new Agent(a);

    if(dataPtr == nullptr) {
        throw AgentException("memoria no disponible, agentNode");
        }
    }

AgentNode::~AgentNode() {
    delete dataPtr;
    }

Agent* AgentNode::getDataPtr() const {
    return dataPtr;
    }

Agent AgentNode::getData() const {
    if(dataPtr == nullptr) {
        throw AgentException("memoria no disponible, getData");
        }
    return *dataPtr;
    }

AgentNode* AgentNode::getPrev() const {
    return prev;
    }

AgentNode* AgentNode::getNext() const {
    return next;
    }

void AgentNode::setDataPtr(Agent* a) {
    dataPtr = a;
    }

void AgentNode::setData(const Agent& a) {
    if(dataPtr == nullptr) {
        dataPtr = new Agent(a);

        if(dataPtr == nullptr) {
            throw AgentException("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr = a;
        }
    }

void AgentNode::setPrev(AgentNode* a) {
    prev = a;
    }

void AgentNode::setNext(AgentNode* a) {
    next = a;
    }
