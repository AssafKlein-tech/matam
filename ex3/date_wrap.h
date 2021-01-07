#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_
#include <iostream>
using std::ostream 
#include <stdbool.h>

extern "C" {
 #include "date.h"
}

class DateWrap{
    Date date;

public:

    DateWrap(const int day,const int month, const int year);
    DateWrap(int date);

    int day();
    int month();
    int year();
    friend ostream& operator<<(ostream& os, const DateWrap& c);
    bool operator==(const DateWrap& datewrap1, const DateWrap& datewrap2);
    bool operator>(const DateWrap& datewrap1, const DateWrap& datewrap2);
    bool operator<(>const DateWrap& datewrap1, const DateWrap& datewrap2);
    bool operator<=(const DateWrap& datewrap1, const DateWrap& datewrap2);
    bool operator>=(const DateWrap& datewrap1, const DateWrap& datewrap2);
    bool operator!=(const DateWrap& datewrap1, const DateWrap& datewrap2);
    bool operator++(const DateWrap& datewrap);
    DateWrap& operator++(const DateWrap& datewrap);
    DateWrap& operator+=(const DateWrap& datewrap, int days_to_add);
    DateWrap operator+(const DateWrap& datewrap);
};

