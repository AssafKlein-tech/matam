#ifndef EXCEPTION_H_
#define EXCEPTION_H_

using std::exception;

namespace mtm{
    class Exception: public exception {};
    
    //DateWrap exceptions
    class InvalidDate: public Exception {};
    class NegativeDays: public Exception {};

    //Events exceptions
    class AlreadyRegistered: public Exception {};
    class RegistrationBlocked: public Exception {};
    class NotRegistered: public Exception {};
    class AlreadyInvited: public Exception {};

    //EventContainers exceptions
    class NotSupported: public Exception {};
    class DateMismatch: public Exception {};
    class InvalidNumber: public Exception {};
    class InvalidInterval: public Exception {};

    //schedule exceptions
    class EventAlreadyExists: public Exception {};
    class EventDoesNotExist: public Exception {};
}

#endif