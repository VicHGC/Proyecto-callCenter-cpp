#include "callnode.hpp"

using namespace std;

CallNode::CallNode() : next(nullptr) { }

CallNode::CallNode(const Call& e) : data(e), next(nullptr) { }

Call CallNode::getData() const {
    return data;
    }

CallNode* CallNode::getNext() const {
    return next;
    }

void CallNode::setData(const Call& c) {
    data = c;
    }

void CallNode::setNext(CallNode* p) {
    next = p;
    }
