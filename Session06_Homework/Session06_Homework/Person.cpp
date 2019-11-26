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

void saveBinary(std::ofstream& outputStream, const Person& person) {
	int size = person._name.size() + 1;
	outputStream.write((const char*)& size, sizeof(int));
	outputStream.write(reinterpret_cast<char*>(&size), sizeof(int));
	outputStream.write(person._name.c_str(), size);

	size = person._surname.size() + 1;
	outputStream.write((const char*)& size, sizeof(int));
	outputStream.write(reinterpret_cast<char*>(&size), sizeof(int));
	outputStream.write(person._surname.c_str(), size);

	saveBinary(outputStream, person._livingAddress);
	saveBinary(outputStream, person._birthDate);
}

void loadBinary(std::ifstream& inputStream, Person& person) {
	char* buffer;
	int s = 0;

	inputStream.read((char*) & (s), sizeof(int));
	inputStream.read(reinterpret_cast<char*>(&s), sizeof(int));
	buffer = new char[s];
	inputStream.read(buffer, s);
	person._name.append(buffer, s);

	inputStream.read((char*) & (s), sizeof(int));
	inputStream.read(reinterpret_cast<char*>(&s), sizeof(int));
	buffer = new char[s];
	inputStream.read(buffer, s);
	person._surname.append(buffer, s);

	loadBinary(inputStream, person._livingAddress);
	loadBinary(inputStream, person._birthDate);
}
