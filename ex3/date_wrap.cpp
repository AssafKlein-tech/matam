#include "date_wrap.h"
usu
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

"""
write c'tor for 1 int argument

"""



DateWrap DateWrap::operator+=(const Complex& c) {
	re += c.re;
	im += c.im;
	return *this;
}
 
Complex& DateWrap::operator-=(const Complex& c) {
	return *this += -c;
}
 
Complex DateWrap::operator-() const {
	return Complex(-re, -im);
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

DateWrap operator+(const Complex& a, const Complex& b) {
	//check which is bigger and using += with the lesser converted to int
	return Complex(a) += b;
	}
	