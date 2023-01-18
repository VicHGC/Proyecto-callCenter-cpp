#include "agente.hpp"

using namespace std;

Agent::Agent() { }

Agent::Agent(const Agent& a) : agentName(a.agentName), agentNumber(a.agentNumber), specialty(a.specialty), extencion(a.extencion), startHourAgent(a.startHourAgent), endHourAgent(a.endHourAgent), extraHours(a.extraHours), agentDate(a.agentDate), agentCallList(a.agentCallList) { }

Name Agent::getAgentName() const {
    return agentName;
    }

string Agent::getSpecialty() const {
    return specialty;
    }

string Agent::getAgentNumber() const {
    return agentNumber;
    }

string Agent::getAgentExtencion() const {
    return extencion;
    }

Hour Agent::getStartHourAgent() const {
    return startHourAgent;
    }

Hour Agent::getEndHourAgent() const {
    return endHourAgent;
    }

int Agent::getExtraHours() const {
    return extraHours;
    }

Date Agent::getAgentDate() const {
    return agentDate;
    }

CallList& Agent::getCallList(){
    return agentCallList;
    }

void Agent::setAgentName(const Name& n) {
    agentName = n;
    }

void Agent::setSpecialty(const std::string& s) {
    specialty = s;
    }

void Agent::setAgentExtencion(const std::string& e) {
    extencion = e;
    }

void Agent::setAgentNumber(const std::string& n) {
    agentNumber = n;
    }

void Agent::setStartHour(const Hour& s) {
    startHourAgent = s;
    }

void Agent::setEndHour(const Hour& e) {
    endHourAgent = e;
    }

void Agent::setExtraHours(const int& e) {
    extraHours = e;
    }

void Agent::setAgentDate(const Date& d) {
    agentDate = d;
    }

void Agent::setAgentCallList(const CallList& c) {
    agentCallList = c;
    }

string Agent::toString(const int& a) const {
    string resultado;

    resultado += agentName.toString();
    resultado.resize(16, ' ');
    resultado += " | ";
    resultado += "+" + extencion + " " + agentNumber;
    resultado += " | ";
    resultado += specialty;
    resultado += " | ";
    resultado += startHourAgent.toString();
    resultado += " | ";
    resultado += endHourAgent.toString();
    resultado += " | ";
    resultado += to_string(extraHours);
    resultado += " | ";
    resultado += agentDate.toString();
    resultado += "        |";

    if(a == 1){
        resultado += "\n";
        resultado += "\t\t|--------------------------------------------------------------------------------------|\n";
        resultado += "\t\t|                                    Sus llamadas                                      |\n";
        resultado += "\t\t|                                                                                      |\n";
        resultado += agentCallList.toString();
        resultado += "\t\t|______________________________________________________________________________________|";
    }

    return resultado;
    }

Agent& Agent::operator=(const Agent& a) {
    agentName = a.agentName;
    agentNumber = a.agentNumber;
    specialty = a.specialty;
    extencion = a.extencion;
    startHourAgent = a.startHourAgent;
    endHourAgent = a.endHourAgent;
    extraHours = a.extraHours;
    agentDate = a.agentDate;
    agentCallList = a.agentCallList;

    return *this;
    }

bool Agent::operator==(const Agent& a) {
    return agentNumber == a.agentNumber;
    }

bool Agent::operator!=(const Agent& a) {
    return agentNumber != a.agentNumber;
    }

bool Agent::operator<(const Agent& a) {
    return agentNumber < a.agentNumber;
    }

bool Agent::operator<=(const Agent& a) {
    return agentNumber <= a.agentNumber;
    }

bool Agent::operator>(const Agent& a) {
    return agentNumber > a.agentNumber;
    }

bool Agent::operator>=(const Agent& a) {
    return agentNumber >= a.agentNumber;
    }

ostream& operator << (ostream& os, const Agent& a){
    os << a.agentName << endl;
    os << a.agentNumber << endl;
    os << a.specialty << endl;
    os << a.extencion << endl;
    os << a.startHourAgent << endl;
    os << a.endHourAgent << endl;
    os << to_string(a.extraHours) << endl;
    os << a.agentDate;

    return os;
    }
istream& operator >> (istream& is, Agent& a){
    string myStr;

    is >> a.agentName;
    getline(is, a.agentNumber);
    getline(is, a.specialty);
    getline(is, a.extencion);
    is >> a.startHourAgent;
    is >> a.endHourAgent;
    getline(is, myStr);
    a.extraHours = atoi(myStr.c_str());
    is >> a.agentDate;

    return is;

    }
