#include "date_wrap.h"

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

DateWrap::~DateWrap()
{
	dateDestroy(date);
}

DateWrap::DateWrap(const DateWrap& datewrap)
{
	date = dateCopy(date);
}

DateWrap::DateWrap& operator=(const DateWrap& datewrap)
{
	if(this == &datewrap)
		return *this;
	dateDestroy() date;
	date = dateCreate(datewrap->day(),datewrap->month(),datewrap->year())
	return *this;
}

bool getDateParameter(int& day, int& month, int& year)
{
    return dateGet(date, &day, &month, &year);
}

int toDays()
{
	return day() + month()*30 + year() * 360; 
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
	return (dateCompare(date, datewrap->date) <= 0)
}

bool DateWrap::operator>=(const DateWrap& datewrap)
{
	return (dateCompare(date, datewrap->date) >= 0)
}

bool DateWrap::operator!=(const DateWrap& datewrap)
{
	return (dateCompare(date, datewrap->date) != 0)
}

DateWrap& DateWrap::operator+=(const int days_to_add) 
{
	for(int i = 0; i < days_to_add; i++)
	{
		dateTick(date);
	}
	return *this;
}

DateWrap operator+(const DateWrap& date1, const DateWrap& date2) 
{
	if (date1 > date2)
		return DateWrap(date1) += date2.toDays();
	return DateWrap(date2) += date1.toDays();
}
	
DateWrap DateWrap::operator++(int)
{
	DateWrap copy(*this);
	dateTick(date);
	return copy;
}
friend ostream& operator<<(ostream& os, const DateWrap& c)
{

	return os<<date.day<<"/"<<date.month<<"/"<<date.year;


}


 }
