/* How many Sundays fell on the first of the month 
 * during the twentieth century (1 Jan 1901 to 31 Dec 2000)? */

#include <stdio.h>
enum weekd {monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday};
enum month {january = 1, february, march, april, may, june, july, august,
	september, october, november, december};
struct date {
	unsigned char day;
	unsigned char month;
	unsigned short year;
	enum weekd weekday;
	
};

int numbersundays = 0;
int getnumdaysinmonthandyear(enum month month, int year)
{
	if (month == february) {
			if (year % 4 == 0 &&
				((year % 100) != 0 || year % 400 == 0))
				return 29;
			else
				return 28;
	}
	switch (month) {
		case april: return 30;
		case june: return 30;
		case september: return 30;
		case november: return 30;
		default: return 31;
	}
}
struct date iterateyear(struct date currentdate)
{
	int daysinmonth = getnumdaysinmonthandyear(currentdate.month, currentdate.year);
	for(; currentdate.month <= december; ++currentdate.month) {
		for (int i = 0; i < daysinmonth; ++i) {
			if (currentdate.weekday == sunday) {
				++numbersundays;
				currentdate.weekday = monday;
			} else {
				++currentdate.weekday;
			}
			currentdate.day += 1;
		}
	}
	return currentdate;
}

int main()
{
	struct date currentdate; 
	currentdate.day = 1;
	currentdate.month = january;
	currentdate.year = 1900;
	currentdate.weekday = 1;

	currentdate = iterateyear(currentdate);
	for (;currentdate.year <= 2000;
	 	 ++currentdate.year, currentdate.month = 1, currentdate.day = 1) {
		iterateyear(currentdate);
	}
	printf("There are %d sundays during the twentieth century.", numbersundays);
	return 0;
}
