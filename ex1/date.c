#include "date.h"
#include <stdbool.h>

typedef enum Monthes {JAN = 1, FEB, MER, APR, MAY , JUN , JUL , AUG , SEP , OCT , NOV , DEC} Month;
#define MIN_DAY 1
#define MAX_DAY 30
#define INVALID_MONTH 0
#define MONTH_NUM 12
#define DAYS_IN_YEAR 365
#define MONTH_STR_LEN 4

struct Date_t
{
    int date;
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
	strcpy(date->month, months[month-1]);
	date->year = year;
	return date;

}

/**
* dateDestroy: Deallocates an existing Date.
*
* @param date - Target date to be deallocated. If priority queue is NULL nothing will be done
*/
void dateDestroy(Date date);

/**
* dateCopy: Creates a copy of target Date.
*
* @param date - Target Date.
* @return
* 	NULL if a NULL was sent or a memory allocation failed.
* 	A Date containing the same elements as date otherwise.
*/
Date dateCopy(Date date);

/**
* dateGet: Returns the day, month and year of a date
*
* @param date - Target Date
* @param day - the pointer to assign to day of the date into.
* @param month - the pointer to assign to month of the date into.
* @param year - the pointer to assign to year of the date into.
*
* @return
* 	false if one of pointers is NULL.
* 	Otherwise true and the date is assigned to the pointers.
*/
bool dateGet(Date date, int* day, int* month, int* year);

/**
* dateCompare: compares to dates and return which comes first
*
* @return
* 		A negative integer if date1 occurs first;
* 		0 if they're equal or one of the given dates is NULL;
*		A positive integer if date1 arrives after date2.
*/
int dateCompare(Date date1, Date date2);

/**
* dateTick: increases the date by one day, if date is NULL should do nothing.
*
* @param date - Target Date
*
*/
void dateTick(Date date);

#endif //DATE_H_
