#include "Time.h"
#define HOURFORMATCONVERT 10000
#define MINUTEFORMATCONVERT 100


Time::Time(int aHours, int aMinutes, int aSeconds) {

	if (aHours >= 0 && aHours <= 23) {
		_hours = aHours;
	}
	else {
		throw std::invalid_argument("Invalid hours inserted");

	}

	if (aMinutes >= 0 && aMinutes <= 59) {
		_minutes = aMinutes;
	}
	else {
		throw std::invalid_argument("Invalid minutes inserted");

	}
	if (aSeconds >= 0 && aSeconds <= 59) {
		_seconds = aSeconds;
	}
	else {
		throw std::invalid_argument("Invalid seconds inserted");

	}
};

int Time::compareTo(IComparable* obj) const {
	Time* timeCast = dynamic_cast<Time*>(obj);
	int time1 = (this->_hours * HOURFORMATCONVERT) + (this->_minutes * MINUTEFORMATCONVERT) + this->_seconds;
	int time2 = (timeCast->_hours * HOURFORMATCONVERT) + (timeCast->_minutes * MINUTEFORMATCONVERT) + timeCast->_seconds;
	if (time1 > time2) {
		return 1;
	}
	else if (time1 == time2) {
		return 0;
	}
	else {
		return -1;
	}
}

std::string Time::toString() const {
	return std::to_string(this->_hours) + ":" + std::to_string(this->_minutes) + ":" + std::to_string(this->_seconds);;
}



