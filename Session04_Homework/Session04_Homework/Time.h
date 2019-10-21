#pragma once
#ifndef TIME_H
#define TIME_H
#include <stdexcept>
#include <string>
#include "IComparable.h"

struct Time : IComparable {
private:
		int _hours;
		int _minutes;
		int _seconds;
public:
	Time(int aHours, int aMinutes, int _aSeconds);
	int compareTo(IComparable * obj);
	std::string toString();
	void ArraySort(IComparable** aArray, int aArraySize);
	


};


#endif // !TIME_H
