#include "date_wrap.h"
//using namespace mtm

DateWrap::DateWrap(const int day,const int month, const int year)
{
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

/*
* create c'tor for 1 
* += using 
*/

DateWrap& DateWrap::operator+=(const int days_to_add) 
{
	for(int i = 0; i < days_to_add; i++)
	{
		dateTick(date);
	}
	return *this;
}


Complex operator-(const Complex& a, const Complex& b) {
	return Complex(a) -= b;
}
 
ostream& operator<<(ostream& os, const Complex& c) {
	const char* sign = c.im < 0 ? "-" : "+";
	return os << c.re << sign << c.im << "i";
}
 
istream& operator>>(istream& is, Complex& c) {
	return is >> c.re >> c.im;
}

bool operator==(const Complex& a, const Complex& b) {
	return a.re == b.re && a.im == b.im;
}

DateWrap operator+(const DateWrap& a, const DateWrap& b) 
{
	DateWrap date_a(a), date_b(b)  ;
	if (date_a > date_b):
		return date_a += date_b.toDays();
	return date_b += date_a.toDays();
}
	