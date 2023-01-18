#include "calllist.hpp"

using namespace std;

void CallList::copyAll(const CallList& l) {
    CallNode* aux(l.anchor);
    CallNode* last(nullptr);
    CallNode* newNode;

    while(aux != nullptr) {
        newNode = new CallNode(aux->getData());

        if(last == nullptr) {
            anchor = newNode;
            }
        else {
            last->setNext(newNode);
            }
        last = newNode;

        aux = aux->getNext();
        }
    }

bool CallList::isValidPos(CallNode* p) const {
    CallNode* aux(anchor);

    while(aux != nullptr) {
        if(aux == p) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

CallList::CallList() : anchor(nullptr) {}

CallList::CallList(const CallList& l) : anchor(nullptr) {
    copyAll(l);
    }

CallList::~CallList() {
    deleteAll();
    }

bool CallList::isEmpty() const {
    return anchor == nullptr;
    }

void CallList::insertData(CallNode* p, const Call& e) {
    if(p != nullptr and !isValidPos(p)) {
        throw ExceptionCall("posicion invalida, insertData");
        }

    CallNode* aux(new CallNode(e));

    if(aux == nullptr) {
        throw ExceptionCall("memoria no disponible, insertData");
        }

    if(p == nullptr) {
        aux->setNext(anchor);
        anchor = aux;
        }
    else {
        aux->setNext(p->getNext());
        p->setNext(aux);
        }
    }

bool CallList::isOrder(const Call& c, const Call& x) const {
    return c.getStartHour() < x.getStartHour();
    }

void CallList::insertSorteData(const Call& e) {
    CallNode* prev(nullptr);
    CallNode* aux(anchor);

    while(aux != nullptr and isOrder(aux->getData(), e)) {
        prev = aux;
        aux = aux->getNext();
        }
    insertData(prev, e);
    }

void CallList::deleteData(CallNode* p) {
    if(!isValidPos(p)) {
        throw ExceptionCall("posicion invalida, deleteData");
        }

    if(p == anchor) {
        anchor = p->getNext();
        }
    else {
        getPrevPos(p)->setNext(p->getNext());
        }
    delete p;
    }

CallNode* CallList::getFirstPos() const {
    return anchor;
    }

CallNode* CallList::getLastPos() const {
    if(isEmpty()) {
        return nullptr;
        }

    CallNode* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
        }
    return aux;
    }

CallNode* CallList::getPrevPos(CallNode* p) const {
    if(p == anchor) {
        return nullptr;
        }

    CallNode* aux(anchor);

    while(aux != nullptr and aux->getNext() != p) {
        aux = aux->getNext();
        }
    return aux;
    }

CallNode* CallList::getNextPos(CallNode* p) const {
    if(!isValidPos(p)) {
        return nullptr;
        }

    return p->getNext();
    }

CallNode* CallList::findData(const Call& e) const {
    CallNode* aux(anchor);

    while(aux != nullptr) {
        if(aux->getData() == e) {
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
    }

Call CallList::retrieve(CallNode* p) const {
    if(!isValidPos(p)) {
        throw ExceptionCall("posicion invalida, retrieve");
        }

    return p->getData();
    }

string CallList::toString() const {
    string resultado;

    CallNode* aux(anchor);

    while(aux != nullptr) {
        resultado += "\t\t| " + aux->getData().toString() + "   \t       |" + "\n";

        aux = aux->getNext();
        }
    return resultado;
    }

void CallList::deleteAll() {
    CallNode* aux;

    while(anchor != nullptr) {
        aux = anchor;

        anchor = anchor->getNext();

        delete aux;
        }
    }

CallList& CallList::operator = (const CallList& l) {
    deleteAll();

    copyAll(l);

    return *this;
    }


void CallList::writeToDisk(const string& fileName) {
    ofstream myFile;

    myFile.open(fileName, ios_base::trunc);

    if(!myFile.is_open()) {
        string msg;

        msg = "El archivo " + fileName + " no se pudo abrir para escritura";

        throw ExceptionCall(msg);
        }

    CallNode* aux(anchor);

    while(aux != nullptr) {
        myFile << aux->getData() << endl;

        aux = aux->getNext();
        }

    myFile.close();
    }

void CallList::readToDisk(const string& fileName) {
    ifstream myFile;

    myFile.open(fileName);

    if(!myFile.is_open()) {
        throw ExceptionCall("no se pudo abrir el archivo, readToDisk");
        }

    deleteAll();

    Call myData;
    CallNode* lastInserted(nullptr);
    CallNode* newNode;

    while(myFile >> myData) {
        if((newNode = new CallNode(myData)) == nullptr) {
            myFile.close();

            throw ExceptionCall("memoria no disponible, readToDisk");
            }

        if(lastInserted == nullptr) {
            anchor = newNode;
            }
        else {
            lastInserted->setNext(newNode);
            }

        lastInserted = newNode;
        }

    myFile.close();
    }
