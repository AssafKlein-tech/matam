#include "date_wrap.h"
//using namespace mtm

DateWrap::DateWrap(const int day,const int month, const int year)
{
    //if date illegall raise InvalidDate
    date = dateCreate(day,month,year);
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

<<<<<<< HEAD
"""
write c'tor for 1 int argument

"""

friend ostream& operator<<(ostream& os, const DateWrap& c)
{
	
	


}

DateWrap DateWrap::operator+=(const Complex& c) {
	re += c.re;
	im += c.im;
=======
DateWrap& DateWrap::operator+=(const int days_to_add) 
{
	for(int i = 0; i < days_to_add; i++)
	{
		dateTick(date);
	}
>>>>>>> 30d152547f66d275b662e4ef38ce4aab4d1717e3
	return *this;
}

DateWrap operator+(const DateWrap& a, const DateWrap& b) 
{
	DateWrap date_a(a), date_b(b)  ;
	if (date_a > date_b):
		return date_a += date_b.toDays();
	return date_b += date_a.toDays();
}
	