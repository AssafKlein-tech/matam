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

        /**
         * @brief checks if the date is valid
         * 
         * @param day the day of the date
         * @param month the month of the date
         * @return true if its valid
         * @return false otherwise
         */
        bool checkDateValidation(const int day,const int month);
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
        bool operator==(const DateWrap& datewrap) const;
        bool operator>(const DateWrap& datewrap) const;
        bool operator<(const DateWrap& datewrap) const;
        bool operator<=(const DateWrap& datewrap) const;
        bool operator>=(const DateWrap& datewrap) const;
        bool operator!=(const DateWrap& datewrap) const;
        DateWrap operator+(const int days);
        DateWrap operator++(int);
        DateWrap& operator+=(const int days_to_add);

        class InvalidDate: public Exception {};
        class NegativeDays: public Exception {};

    private:
        bool getDateParameter(int& day, int& month, int& year) const;
    };

    DateWrap operator+(const int days, const DateWrap& date);
}

#endif