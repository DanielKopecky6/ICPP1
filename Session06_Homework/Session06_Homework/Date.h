#ifndef DATE_H
#define DATE_H

#include <iostream>

struct Date {
	Date() {};
	Date(int aDay, int aMonth, int aYear);
	~Date() {};
	int _day;
	int _month;
	int _year;

};

std::ostream& operator<<(std::ostream& os, const Date& date);
std::istream& operator>>(std::istream& is, Date& date);





#endif // !DATE_H

