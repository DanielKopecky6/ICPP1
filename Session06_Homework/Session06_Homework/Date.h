#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <fstream>

struct Date {
	Date() {};
	Date(int aDay, int aMonth, int aYear);
	~Date() {};
	int _day;
	int _month;
	int _year;

};

std::ostream& operator<<(std::ostream& outputStream, const Date& date);
std::istream& operator>>(std::istream& is, Date& date);

void saveBinary(std::ofstream& outputStream, const Date& date);
void loadBinary(std::ifstream& inputStream, Date& date);




#endif // !DATE_H

