#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_
#include <iostream>
using std::ostream;
#include <stdbool.h>


extern "C"{
    #include "date.h"
}

namespace mtm{
    class DateWrap{
        Date date;

    public:

        DateWrap(int day,int month,int year);
        DateWrap(int date);
        ~DateWrap();
        DateWrap(const DateWrap& datewrap);
        DateWrap& operator=(const DateWrap& datewrap);

        int day() const;
        int month() const;
        int year() const;
        friend ostream& operator<<(ostream& os, const DateWrap& c);
        bool operator==(const DateWrap& datewrap);
        bool operator>(const DateWrap& datewrap);
        bool operator<(const DateWrap& datewrap);
        bool operator<=(const DateWrap& datewrap);
        bool operator>=(const DateWrap& datewrap);
        bool operator!=(const DateWrap& datewrap);
        DateWrap operator++(int);
        DateWrap& operator+=(const int days_to_add);

    private:
        int toDays();
        bool getDateParameter(int& day, int& month, int& year) const;
    };

    DateWrap operator+(const DateWrap& datewrap1, const DateWrap& datewrap2);
}

#endif