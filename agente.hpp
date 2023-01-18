#ifndef AGENTE_HPP_INCLUDED
#define AGENTE_HPP_INCLUDED

#include <string>
#include <iostream>

#include "calllist.hpp"
#include "name.hpp"
#include "date.hpp"
#include "hour.hpp"

class Agent {
    private:
        Name agentName;
        std::string agentNumber;
        std::string specialty;
        std::string extencion;
        Hour startHourAgent;
        Hour endHourAgent;
        int extraHours;
        Date agentDate;

        CallList agentCallList;

    public:
        Agent();
        Agent(const Agent&);

        Name getAgentName() const;
        std::string getSpecialty() const;
        std::string getAgentNumber() const;
        std::string getAgentExtencion() const;
        Hour getStartHourAgent() const;
        Hour getEndHourAgent() const;
        int getExtraHours() const;
        Date getAgentDate() const;

        CallList& getCallList();

        std::string toString(const int&) const;

        void setAgentName(const Name&);
        void setSpecialty(const std::string&);
        void setAgentExtencion(const std::string&);
        void setAgentNumber(const std::string&);
        void setStartHour(const Hour&);
        void setEndHour(const Hour&);
        void setExtraHours(const int&);
        void setAgentDate(const Date&);
        void setAgentCallList(const CallList&);

        Agent& operator = (const Agent&);

        bool operator == (const Agent&);
        bool operator != (const Agent&);
        bool operator < (const Agent&);
        bool operator <= (const Agent&);
        bool operator > (const Agent&);
        bool operator >= (const Agent&);

        friend std::ostream& operator << (std::ostream&, const Agent&);
        friend std::istream& operator >> (std::istream&, Agent&);

    };

#endif // AGENTE_HPP_INCLUDED
