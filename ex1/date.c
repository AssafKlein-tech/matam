#include "date.h"
#include <stdbool.h>


//fdgag
typedef enum Monthes {JAN = 1, FEB, MER, APR, MAY , JUN , JUL , AUG , SEP , OCT , NOV , DEC} Month;
#define MIN_DAY 1
#define MAX_DAY 30
#define INVALID_MONTH 0
#define MONTH_NUM 12
#define DAYS_IN_YEAR 365
#define MONTH_STR_LEN 4

struct Date_t
{
    int day;
    Month month;
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
    {
        return NULL;
    }
    return dateCreate(date->day,date->month,date->year);
}

bool dateGet(Date date, int* day, int* month, int* year)
{
    if (!date || !date->day || !date->month || !date->year)
    {
        return false;
    }
    *day = date->day;
    *month = date->month;
    *year = date->year;
    return true;
}

int dateCompare(Date date1, Date date2)
{
    if (!date1 || !date2)
    {
        return 0;
    }
    if (date1->year != date2->year)
    {
        return  date1->year > date2->year;
    }
    if (date1->month != date2->month)
    {
        return  date1->month > date2->month;
    }
    return date1->day > date2->day;
}

static dateToDays(Date date)
{
    return date->day + date->month*MAX_DAY + date->year * DAYS_IN_YEAR;
}

static daysToDate(Date date, int days)
{
    date->year = days / DAYS_IN_YEAR;
    days = days % DAYS_IN_YEAR;
    date->month = days / MAX_DAY;
    date->day = days % MAX_DAY;
}

void dateTick(Date date)
{
    if (!date)
    {
        return NULL;
    }
    int days_after_tick = dateToDays(date) + 1;
    daysToDate(date, days_after_tick);
}

