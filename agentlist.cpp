#include "agentlist.hpp"

using namespace std;

void AgentList::copyAll(const AgentList& a) {
    AgentNode* aux(a.header->getNext());
    AgentNode* newNode;

    while(aux != a.header) {
        try {
            if((newNode = new AgentNode(aux->getData())) == nullptr) {
                throw AgentException("memoria no disponible, copyAll");
                }
            }
        catch (AgentException ex) {
            throw AgentException(ex.what());
            }
        if(newNode == nullptr) {
            throw AgentException("memoria no disponible, copyAll");
            }
        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
        }
    }

bool AgentList::isValidPos(AgentNode* a) const {
    AgentNode* aux(header->getNext());

    while(aux != header) {
        if(aux == a) {
            return true;
            }

        aux = aux->getNext();
        }
    return false;
    }

AgentList::AgentList() : header(new AgentNode) {
    if(header == nullptr) {
        throw AgentException("Memoria no disponible, constructor");
        }

    header->setPrev(header);
    header->setNext(header);
    }

AgentList::AgentList(const AgentList& a) : AgentList() {
    copyAll(a);
    }

AgentList::~AgentList() {
    deleteAll();

    delete header;
    }

bool AgentList::isEmpty() const {
    return header->getNext() == header;
    }

void AgentList::insertData(AgentNode* p, const Agent& a) {
    if(p != nullptr and !isValidPos(p)) {
        throw AgentException("posicion invalida, insertData");
        }

    AgentNode* aux;
    try {
        aux = new AgentNode(a);
        }
    catch(AgentException ex) {
        throw AgentException(ex.what());
        }
    if(aux == nullptr) {
        throw AgentException("memoria no disponible, insertData");
        }

    if(p == nullptr) {
        p = header;
        }

    aux->setPrev(p);
    aux->setNext(p->getNext());

    p->getNext()->setPrev(aux);
    p->setNext(aux);
    }

void AgentList::deleteData(AgentNode* a) {
    if(!isValidPos(a)) {
        throw AgentException("posicion invalida, deleteData");
        }

    a->getPrev()->setNext(a->getNext());
    a->getNext()->setPrev(a->getPrev());

    delete a;
    }

AgentNode* AgentList::getFirstPos() const {
    if(isEmpty()) {
        return nullptr;
        }

    return header->getNext();
    }

AgentNode* AgentList::getLastPos() const {
    if(isEmpty()) {
        return nullptr;
        }

    return header->getPrev();
    }

AgentNode* AgentList::getPrevPos(AgentNode* a) const {
    if(!isValidPos(a) or a == header->getNext()) {
        return nullptr;
        }

    return a->getPrev();
    }

AgentNode* AgentList::getNextPos(AgentNode* a) const {
    if(!isValidPos(a) or a == header->getPrev()) {
        return nullptr;
        }

    return a->getNext();
    }

AgentNode* AgentList::findData(const Agent& a) {
    AgentNode* aux(header->getNext());

    while(aux != header) {
        if(aux->getData().getAgentName() == a.getAgentName()) {
            return aux;
            }

        aux = aux->getNext();
        }

    return nullptr;
    }

Agent AgentList::retrieve(AgentNode* a) const {
    if(!isValidPos(a)) {
        throw AgentException("posicion invalida, retrieve");
        }

    return a->getData();
    }

string AgentList::toString(const int& a) const {
    string resultado;
    AgentNode* aux(header->getNext());

    while(aux != header) {
        resultado += "\t\t| " + aux->getData().toString(a) + "\n";
        aux = aux->getNext();
        }

    return resultado;
    }

string AgentList::toStringFilt(const string& f, const int& a) const {
    string resultado;
    AgentNode* aux(header->getNext());

    while(aux != header) {
        if(aux->getData().getSpecialty() == f) {
            resultado += "\t\t| " + aux->getData().toString(a) + "\n";
            }
        aux = aux->getNext();
        }
    return resultado;
    }

void AgentList::swapPtr(AgentNode* a, AgentNode* b) {
    Agent* aux(a->getDataPtr());

    a->setDataPtr(b->getDataPtr());
    b->setDataPtr(aux);
    }


void AgentList::sortBySpecialty() {
    sortBySpecialty(header->getNext(), header->getPrev());
    }

void AgentList::sortByName() {
    sortByName(header->getNext(), header->getPrev());
    }


void AgentList::sortBySpecialty(AgentNode* leftEdge, AgentNode* rightEdge) {
    if(leftEdge == rightEdge) {
        return;
        }

    if(leftEdge->getNext() == rightEdge) {
        if(leftEdge->getData().getSpecialty() > rightEdge->getData().getSpecialty()) {
            swapPtr(leftEdge, rightEdge);
            }
        return;
        }

    AgentNode* i(leftEdge);
    AgentNode* j(rightEdge);

    while(i != j) {
        while(i != j and i->getData().getSpecialty() <= rightEdge->getData().getSpecialty()) {
            i = i->getNext();
            }

        while(i != j and j->getData().getSpecialty() >= rightEdge->getData().getSpecialty()) {
            j = j->getPrev();
            }

        if(i != j) {
            swapPtr(i, j);
            }
        }

    if(i != rightEdge) {
        swapPtr(i, rightEdge);
        }

    if(leftEdge != i) {
        sortBySpecialty(leftEdge, i->getPrev());
        }

    if(i != rightEdge) {
        sortBySpecialty(i->getNext(), rightEdge);
        }
    }

void AgentList::sortByName(AgentNode* leftEdge, AgentNode* rightEdge) {
    if(leftEdge == rightEdge) {
        return;
        }

    if(leftEdge->getNext() == rightEdge) {
        if(leftEdge->getData().getAgentName() > rightEdge->getData().getAgentName()) {
            swapPtr(leftEdge, rightEdge);
            }
        return;
        }

    AgentNode* i(leftEdge);
    AgentNode* j(rightEdge);

    while(i != j) {
        while(i != j and i->getData().getAgentName() <= rightEdge->getData().getAgentName()) {
            i = i->getNext();
            }
        while(i != j and j->getData().getAgentName() >= rightEdge->getData().getAgentName()) {
            j = j->getPrev();
        }

        if(i != j) {
            swapPtr(i, j);
            }
        }

    if(i != rightEdge) {
        swapPtr(i, rightEdge);
        }

    if(leftEdge != i) {
        sortByName(leftEdge, i->getPrev());
        }

    if(i != rightEdge) {
        sortByName(i->getNext(), rightEdge);
        }
    }

void AgentList::deleteAll() {
    AgentNode* aux;

    while(header->getNext() != header) {
        aux = header->getNext();

        header->setNext(aux->getNext());

        delete aux;
        }

    header->setPrev(header);
    }

AgentList& AgentList::operator=(const AgentList& a) {
    deleteAll();

    copyAll(a);

    return *this;
    }

void AgentList::writeToDisk(const std::string& fileName) {
    ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open()) {
        string msg;

        msg = "el archivo " + fileName + " no se pudo abrir para escritura";

        throw AgentException(msg);
        }

    AgentNode* aux(header->getNext());

    while(aux != header) {
        myFile << aux->getData() << endl;

        aux->getData().getCallList().writeToDisk(aux->getData().getAgentNumber() + ".txt");

        aux = aux->getNext();
        }

    myFile.close();
    }

void AgentList::readFromDisk(const std::string& fileName) {
    ifstream myFile;

    myFile.open(fileName);

    if(!myFile.is_open()) {
        throw AgentException("no se pudo abrir el archivo de lectura");
        }

    deleteAll();

    Agent myData;
    AgentNode* newNode;

    try {
        while(myFile >> myData) {
            try {
                myData.getCallList().readToDisk(myData.getAgentNumber() + ".txt");
                }
            catch(ExceptionCall ex) {
                throw AgentException(ex.what());
                }
            if((newNode = new AgentNode(myData)) == nullptr) {
                myFile.close();

                throw AgentException("memoria no disponible ");
                }

            newNode->setPrev(header->getPrev());
            newNode->setNext(header);

            header->getPrev()->setNext(newNode);
            header->setPrev(newNode);
            }
        }
    catch(AgentException ex) {
        myFile.close();

        throw AgentException(ex.what());
        }
    myFile.close();
    }
