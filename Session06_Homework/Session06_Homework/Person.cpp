#include "Person.h"

std::ostream & operator<<(std::ostream & outputStream, const Person & person)
{
	outputStream << person._name << " " << person._surname << "  " << person._birthDate << " " << person._livingAddress << std::endl;
	return outputStream;
}

std::istream & operator>>(std::istream & inputStream, Person & person)
{
	inputStream >> person._name;
	inputStream >> person._surname;
	inputStream >> person._birthDate;
	inputStream >> person._livingAddress;
	return inputStream;
}

Person::Person(std::string aName, std::string aSurname, Date aBirthDate, Address aLivingAddress)
{
	_name = aName;
	_surname = aSurname;
	_birthDate = aBirthDate;
	_livingAddress = aLivingAddress;
}
