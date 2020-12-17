#include "date.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MIN_DAY 1
#define MAX_DAY 30
#define INVALID_MONTH 0
#define MONTH_NUM 12
#define DAYS_IN_YEAR 360
#define MONTH_STR_LEN 4

struct Date_t
{
    int day;
    int month;
    int year;
};

/** Checks if the day given is valid
*@param day  - the day of the date
*@return 
    true if day is valid (1-30), else otherwise
**/
static bool isDayValid(int day)
{
    return day >= MIN_DAY && day <= MAX_DAY;
}

/** Checks if the month given is valid
*@param month  - the month of the date
*@return 
    true if day is valid (1-30), else otherwise
**/
static bool isMonthNumberValid(int month)
{
   return month > INVALID_MONTH && month <= MONTH_NUM; 
}

Date dateCreate(int day, int month, int year)
{
    if (!isDayValid(day) || !isMonthNumberValid(month)) {
		return NULL;
	}
	Date date = malloc(sizeof(*date));
	if (!date) {
		return NULL;
	}
	date->day = day;
	date->month = month;
	date->year = year;
	return date;
}

void dateDestroy(Date date)
{
    free(date);
}

Date dateCopy(Date date)
{
    if (!date)
        return NULL;
    return dateCreate(date->day,date->month,date->year);
}

bool dateGet(Date date, int* day, int* month, int* year)
{
    if (date && day && month && year)
    {
        *day = date->day;
        *month = date->month;
        *year = date->year;
        return true;
    }
    return false;
}

static int dateToDays(Date date)
{
    return (date->day - 1) + (date->month - 1)*MAX_DAY + (date->year-1) * DAYS_IN_YEAR;
}

int dateCompare(Date date1, Date date2)
{
    if (!date1 || !date2)
        return 0;
    return dateToDays(date1) - dateToDays(date2);
}

void dateTick(Date date)
{
    if (date)
    {
        if(date->day == MAX_DAY)
        {
            date->day = 1;
            if (date->month == MONTH_NUM)
            {
                date->month = 1;
                date->year += 1;
            }
            else
                date->month += 1;
        }
        else
            date->day += 1;      
    }
}

