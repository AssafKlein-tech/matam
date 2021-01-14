#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
using std::exception;

namespace mtm{
    class Exception: public exception {};
    //DateWrap exceptions
    class InvalidDate: public Exception {};
    class NegativeDays: public Exception {};

    //EventContainer exceptions
    class NotSupported: public Exception {};
    class DateMismatch: public Exception {};
    class InvalidNumber: public Exception {};
    class InvalidInterval: public Exception {};
}

#endif