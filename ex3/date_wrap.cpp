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
	int month = (num_of_days-360*year)/30+1;
	int day = num_of_days%30;
	if(day==0)
		{day=30;
		month--;
		if(month==0)
			{
				year--;
				month=12;
			}
		}
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
	DateWrap date_a(a), date_b(b)  ;
	if (date_a > date_b):
		return date_a += date_b.toDays();
	return date_b += date_a.toDays();
}
	
