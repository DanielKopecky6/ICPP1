#include "Address.h"

std::ostream & operator<<(std::ostream & outputStream, const Address & address)
{
	outputStream << address._city << " " << address._street << " " << address._psc;
	return outputStream;
}

std::istream & operator>>(std::istream & inputStream, Address & address)
{
	inputStream >> address._city;
	inputStream >> address._street;
	inputStream >> address._psc;
	return inputStream;
}

Address::Address(std::string aCity, std::string aStreet, int aPsc) {
	_city = aCity;
	_street = aStreet;
	_psc = aPsc;
}

