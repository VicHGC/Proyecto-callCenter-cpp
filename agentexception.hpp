#ifndef AGENTEXCEPTION_HPP_INCLUDED
#define AGENTEXCEPTION_HPP_INCLUDED

#include <string>
#include <exception>

class AgentException : public std::exception {
    private:
        std::string msg;

    public:
        explicit AgentException(const char* message) : msg(message) { }

        explicit AgentException(const std::string& message) : msg(message) { }

        virtual ~AgentException() throw() { }

        virtual const char* what() const throw() {
            return msg.c_str();
            }
};

#endif // AGENTEXCEPTION_HPP_INCLUDED
