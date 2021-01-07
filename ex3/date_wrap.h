#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

#include <stdbool.h>

class DateWrap{
    Date date;
};
public:

DateWrap::DateWrap(int day, int month, int year);
DateWrap::DateWrap(int date);

int day();
int month();
int year();
printDateWarp();
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



