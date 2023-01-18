#ifndef CALLEXCEPTION_HPP_INCLUDED
#define CALLEXCEPTION_HPP_INCLUDED

#include <string>
#include <exception>

class ExceptionCall : public std::exception {
    private:
        std::string msg;

    public:
        explicit ExceptionCall(const char* message) : msg(message) { }

        explicit ExceptionCall(const std::string& message) : msg(message) { }

        virtual ~ExceptionCall() throw() { }

        virtual const char* what() const throw() {
            return msg.c_str();
            }
    };

#endif // CALLEXCEPTION_HPP_INCLUDED
