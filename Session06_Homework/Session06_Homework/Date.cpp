#include "Date.h"

std::ostream& operator<<(std::ostream& outputStream, const Date& date) {
	outputStream << date._day << " " << date._month << " " << date._year << "  ";
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Date& date) {
	inputStream >> date._day;
	inputStream >> date._month;
	inputStream >> date._year;
	return inputStream;
}

Date::Date(int aDay, int aMonth, int aYear)
{
	_day = aDay;
	_month = aMonth;
	_year = aYear;
}

void saveBinary(std::ofstream& outputStream, const Date& date) {
	outputStream.write((const char*)& date._day, sizeof(int));
	outputStream.write((const char*)& date._month, sizeof(int));
	outputStream.write((const char*)& date._year, sizeof(int));
}

void loadBinary(std::ifstream& inputStream, Date& date) {
	inputStream.read((char*) & (date._day), sizeof(int));
	inputStream.read((char*) & (date._month), sizeof(int));
	inputStream.read((char*) & (date._year), sizeof(int));
}
