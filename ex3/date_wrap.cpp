#include "date_wrap.h"

DateWrap::DateWrap(const int day,const int month, const int year)
{
    //if date illegall raise InvalidDate
    date(dateCreate(day,month,year));
}

DateWrap::DateWrap(const int num_of_days)
{
	int year = num_of_days/360;
	int month = (num_of_days-360*year)/30;
	int day = (num_of_days-360*year)%30;
    //if date illegall raise InvalidDate
    date = dateCreate(day,month,year);
}

bool getDateParameter(int& day, int& month, int& year)
{
    return dateGet(date, &day, &month, &year);
}

int toDays()
{
	int day = 0, month = 0, year = 0;
	getDateParameter(day, month,year);
	return day + month*30 + year * 360; 
}

int DateWrap::day()
{
    int day = 0, month = 0, year = 0;
	getDateParameter(day, month,year);
	return day;
}

int DateWrap::month()
{
    int day = 0, month = 0, year = 0;
	getDateParameter(day, month,year);
	return month;
}

int DateWrap::year()
{
    int day = 0, month = 0, year = 0;
	getDateParameter(day, month,year);
	return year;
}

bool DateWrap::operator==(const DateWrap& datewrap)
{
	return (dateCompare(date, datewrap->date) == 0)
}

bool DateWrap::operator>(const DateWrap& datewrap)
{
	return (dateCompare(date, datewrap->date) > 0)
}

bool DateWrap::operator<(const DateWrap& datewrap)
{
	return (dateCompare(date, datewrap->date) < 0)
}

bool DateWrap::operator<=(const DateWrap& datewrap)
{
	return (dateCompare(date, datewrap->date) == 0)
}

bool DateWrap::operator>=(const DateWrap& datewrap)
{

}

bool DateWrap::operator!=(const DateWrap& datewrap)
{

}

DateWrap& DateWrap::operator+=(const int days_to_add) 
{
	for(int i = 0; i < days_to_add; i++)
	{
		dateTick(date);
	}
	return *this;
}

DateWrap operator+(const DateWrap& a, const DateWrap& b) 
{
	if (date_a > date_b):
		return DateWrap(date_a) += date_b.toDays();
	return DateWrap(date_b) += date_a.toDays();
}
	
DateWrap operator++(int)
{
	DateWrap copy=this;
	dateTick(date);
	return copy;
}
