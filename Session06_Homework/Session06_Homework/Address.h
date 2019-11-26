#ifndef ADDRESS_H
#define ADDRESS_H

#include <fstream>
#include <iostream>
#include <string>
struct Address {
	Address() {};
	Address(std::string aCity, std::string aStreet, int aPsc);
	~Address() {};
	std::string _street;
	std::string _city;
	int _psc;
};

std::ostream& operator<<(std::ostream& outputStream, const Address& address);
std::istream& operator>>(std::istream& inputStream, Address& Address);


void saveBinary(std::ofstream& outputStream, const Address& adr);
void loadBinary(std::ifstream& inputStream, Address& adr);



#endif // !ADDRESS_H
