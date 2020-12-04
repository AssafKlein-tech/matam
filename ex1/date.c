#include "date.h"
#include <stdbool.h>
#include <stdlib.h>

typedef enum Monthes {JAN = 1, FEB, MER, APR, MAY , JUN , JUL , AUG , SEP , OCT , NOV , DEC} Month;
#define MIN_DAY 1
#define MAX_DAY 30
#define INVALID_MONTH 0
#define MONTH_NUM 12
#define DAYS_IN_YEAR 360
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
        return NULL;
    return dateCreate(date->day,date->month,date->year);
}

bool dateGet(Date date, int* day, int* month, int* year)
{
    if (!date || !day || !month || !year)
        return false;
    *day = date->day;
    *month = date->month;
    *year = date->year;
    return true;
}

static int dateToDays(Date date)
{
    return date->day + (date->month - 1)*MAX_DAY + date->year * DAYS_IN_YEAR;
}

int dateCompare(Date date1, Date date2)
{
    if (!date1 || !date2)
        return 0;
    return dateToDays(date1) - dateToDays(date2);
}

static void daysToDate(Date date, int days)
{
    date->year = days / DAYS_IN_YEAR;
    days = days % DAYS_IN_YEAR;
    date->month = days / MAX_DAY + 1;
    date->day = days % MAX_DAY;
}

void dateTick(Date date)
{
    if (date)
    {
        int days_after_tick = dateToDays(date) + 1;
        daysToDate(date, days_after_tick);
    }
}

