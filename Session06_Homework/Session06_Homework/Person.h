#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

#include "Address.h"
#include "Date.h"

struct Person {
	Person() {};
	Person(std::string aName, std::string aSurname, Date aBirthDate, Address aLivingAddress);
	~Person() {};
	std::string _name;
	std::string _surname;
	Address _livingAddress;
	Date _birthDate;

};

std::ostream& operator<<(std::ostream& outputStream, const Person& person);
std::istream& operator>>(std::istream& inputStream, Person& person);

#endif // !PERSON_H

