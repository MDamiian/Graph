#ifndef LISTEXCEPTION_HPP_INCLUDED
#define LISTEXCEPTION_HPP_INCLUDED

#include <exception>
#include <string>

class GraphException : public std::exception {
    private:
        std::string msg;

    public:
        explicit GraphException(const char* message) : msg(message) { }

        explicit GraphException(const std::string& message) : msg(message) { }

        virtual ~GraphException() throw () { }

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

#endif // LISTEXCEPTION_HPP_INCLUDED
