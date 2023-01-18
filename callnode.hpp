#ifndef CALLNODE_HPP_INCLUDED
#define CALLNODE_HPP_INCLUDED

#include "call.hpp"

class CallNode {
    private:
        Call data;
        CallNode* next;
    public:
        CallNode();
        CallNode(const Call&);

        Call getData() const;
        CallNode* getNext() const;

        void setData(const Call&);
        void setNext(CallNode*);
    };

#endif // CALLNODE_HPP_INCLUDED
