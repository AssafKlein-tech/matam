#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
using std::exception;

namespace mtm{
    class Exception: public exception {};
    class InvalidDate: public Exception {};
    class NegativeDays: public Exception {};
    class NotSupported: public Exception {};
}

#endif