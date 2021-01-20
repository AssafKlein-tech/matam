#include "date_wrap.h"
namespace mtm{
	const int MIN_DAY = 1;
	const int MAX_DAY = 30;
	const int MIN_MONTH = 1;
	const int MAX_MONTH = 12;

	bool DateWrap::checkDateValidation(const int day,const int month)
	{
		if (day < MIN_DAY || day > MAX_DAY || month < MIN_MONTH || month > MAX_MONTH)
		{
			return false;
		}
		return true;
	}

	DateWrap::DateWrap(const int day,const int month, const int year)
	{
		if (!checkDateValidation(day,month))	
		{
			throw InvalidDate();
		}
		date = dateCreate(day,month,year);
	}

	DateWrap::DateWrap(const int num_of_days)
	{
		int year = num_of_days/360 + 1;
		int month = (num_of_days)/30 + 1;
		int day = (num_of_days)%30;
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
		date = dateCopy(datewrap.date);
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
		if(days_to_add < 0)
		{
			throw NegativeDays();
		}
		for(int i = 0; i < days_to_add; i++)
		{
			dateTick(date);
		}
		return *this;
	}

	DateWrap DateWrap::operator+(const int days)
	{
		return DateWrap(*this) += days;
	}

	DateWrap operator+(const int days, const DateWrap& date) 
	{
		return DateWrap(date) += days;
	}
		
	DateWrap DateWrap::operator++(int)
	{
		DateWrap copy(*this);
		dateTick(date);
		return copy;
	}

	ostream& operator<<(ostream& os, const DateWrap& date)
	{
		return os<<date.day()<<"/"<<date.month()<<"/"<<date.year();
	}
}
