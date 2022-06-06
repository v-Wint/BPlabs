#define _CRT_SECURE_NO_WARNINGS
#include "classes.h"
#include <ctime>

Date Date::operator+(int days) {
	tm tmp = tm();
	tmp.tm_mday = day;
	tmp.tm_mon = month - 1;
	tmp.tm_year = year - 1900;

	time_t time = mktime(&tmp);
	const time_t DAY = 60 * 60 * 24;
	time_t sec = time + days * DAY;

	tmp = *localtime(&sec);

	return  { 1900 + tmp.tm_year, tmp.tm_mon + 1, tmp.tm_mday };
}

bool Product::compareDates(Date date1, Date date2) {
	if (date1.year > date2.year)
		return true;
	if (date1.year < date2.year)
		return false;
	if (date1.month > date2.month)
		return true;
	if (date1.month < date2.month)
		return false;
	if (date1.day > date2.day)
		return true;
	if (date1.day <= date2.day)
		return false;
}

bool FoodProduct::isOutdated() {
	time_t time = std::time(0);
	tm* tmp = std::localtime(&time);
	Date now = { tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday };
	return compareDates(now, expieryDate);
}
