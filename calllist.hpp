#ifndef CALLLIST_HPP_INCLUDED
#define CALLLIST_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>

#include "callnode.hpp"
#include "callexception.hpp"

class CallList{
private:
    CallNode* anchor;

    void copyAll(const CallList&);

    bool isValidPos(CallNode*) const;

public:
    CallList();
    CallList(const CallList&);

    ~CallList();

    bool isEmpty() const;

    bool isOrder(const Call&, const Call&) const;

    void insertData(CallNode*, const Call&);

    void insertSorteData(const Call&);

    void deleteData(CallNode*);

    CallNode* getFirstPos() const;
    CallNode* getLastPos() const;
    CallNode* getPrevPos(CallNode*) const;
    CallNode* getNextPos(CallNode*) const;

    CallNode* findData(const Call&) const;

    Call retrieve(CallNode*) const;

    std::string toString() const;

    void deleteAll();

    CallList& operator = (const CallList&);

    void writeToDisk(const std::string&);
    void readToDisk(const std::string&);
};

#endif // CALLLIST_HPP_INCLUDED
