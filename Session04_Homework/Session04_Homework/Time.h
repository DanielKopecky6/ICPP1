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
	virtual int IComparable::compareTo(IComparable * obj) const override;
	virtual std::string IComparable::toString() const override;
};


#endif // !TIME_H
