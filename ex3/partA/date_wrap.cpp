#include "date_wrap.h"
using namespace mtm;

DateWrap::DateWrap(const int day,const int month, const int year)
{
    //if date illegall raise InvalidDate
    date = dateCreate(day,month,year);
}

DateWrap::DateWrap(const int num_of_days)
{
	int year = num_of_days/360 + 1;
	int month = (num_of_days-360*year)/30 + 1;
	int day = (num_of_days-360*year)%30;
	if(day == 0)
	{
		day = 30;
		month--;
		if(month == 0)
		{
			month = 12;
			year--;
		}
	}
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

DateWrap& DateWrap::operator=(const DateWrap& datewrap)
{
	if(this == &datewrap)
		return *this;
	dateDestroy(date);
	date = dateCreate(datewrap.day(),datewrap.month(),datewrap.year());
	return *this;
}

bool DateWrap::getDateParameter(int& day, int& month, int& year) const
{
    return dateGet(date, &day, &month, &year);
}

int toDays(DateWrap date)
{
	return date.day() + date.month()*30 + date.year() * 360; 
}

int DateWrap::day() const
{
    int day = 0, month = 0, year = 0;
	getDateParameter(day, month,year);
	return day;
}

int DateWrap::month() const
{
    int day = 0, month = 0, year = 0;
	getDateParameter(day, month,year);
	return month;
}

int DateWrap::year() const
{
    int day = 0, month = 0, year = 0;
	getDateParameter(day, month,year);
	return year;
}

bool DateWrap::operator==(const DateWrap& datewrap) const
{
	return (dateCompare(date, datewrap.date) == 0);
}

bool DateWrap::operator>(const DateWrap& datewrap) const
{
	return (dateCompare(date, datewrap.date) > 0);
}

bool DateWrap::operator<(const DateWrap& datewrap) const
{
	return (dateCompare(date, datewrap.date) < 0);
}

bool DateWrap::operator<=(const DateWrap& datewrap) const
{
	return (dateCompare(date, datewrap.date) <= 0);
}

bool DateWrap::operator>=(const DateWrap& datewrap) const
{
	return (dateCompare(date, datewrap.date) >= 0);
}

bool DateWrap::operator!=(const DateWrap& datewrap) const
{
	return (dateCompare(date, datewrap.date) != 0);
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
	if (date1.operator>(date2))
		return DateWrap(date1) += toDays(date2);
	return DateWrap(date2) += toDays(date1);
}
	
DateWrap DateWrap::operator++(int)
{
	DateWrap copy(*this);
	dateTick(date);
	return copy;
}
ostream& operator<<(ostream& os, const DateWrap& c)
{
	return os<<c.day()<<"/"<<c.month()<<"/"<<c.year();
}

