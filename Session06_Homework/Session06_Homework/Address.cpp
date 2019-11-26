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


void saveBinary(std::ofstream& outputStream, const Address& adr) {
	int size = adr._street.size() + 1;
	outputStream.write((const char*)& size, sizeof(int));
	outputStream.write(reinterpret_cast<char*>(&size), sizeof(int));
	outputStream.write(adr._street.c_str(), size);

	size = adr._city.size() + 1;
	outputStream.write((const char*)& size, sizeof(int));
	outputStream.write(reinterpret_cast<char*>(&size), sizeof(int));
	outputStream.write(adr._city.c_str(), size);

	outputStream.write((const char*)& adr._psc, sizeof(int));
}

void loadBinary(std::ifstream& inputStream, Address& adr) {
	char* buffer;
	int size = 0;

	inputStream.read((char*) & (size), sizeof(int));
	inputStream.read(reinterpret_cast<char*>(&size), sizeof(int));
	buffer = new char[size];
	inputStream.read(buffer, size);
	adr._street.append(buffer, size);

	inputStream.read((char*) & (size), sizeof(int));
	inputStream.read(reinterpret_cast<char*>(&size), sizeof(int));
	buffer = new char[size];
	inputStream.read(buffer, size);
	adr._city.append(buffer, size);

	inputStream.read((char*) & (adr._psc), sizeof(int));
}

