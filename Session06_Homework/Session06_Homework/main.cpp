#include <fstream>
#include <string>

#include "Person.h"

#define ARRAY_SIZE 5

void save() {
	Person* personArray = new Person[ARRAY_SIZE];

	personArray[0] = Person(std::string("Jan"), std::string("Novak"), Date(1, 1, 2000), Address ("Pardubice", "17.Listopadu", 55532));
	personArray[1] = Person(std::string("Tomas"), std::string("Budina"), Date(2, 2, 1996), Address("Holice", "Ulice", 11111));
	personArray[2] = Person(std::string("Lukas"), std::string("Zeman"), Date(3, 3, 2001), Address("Mesto1", "Ulice", 12345));
	personArray[3] = Person(std::string("Jana"), std::string("Novakova"), Date(4, 4, 2002), Address("Mesto2", "Ulice", 67890));
	personArray[4] = Person(std::string("Martina"), std::string("Konecna"), Date(5, 5, 2003), Address("Mesto3", "Ulice", 54321));

	std::ofstream file;
	file.open("file.txt");

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		file << personArray[i];
	}
	file.close();
	delete[] personArray;
}
void load() {
	Person* personArray = new Person[ARRAY_SIZE];
	std::ifstream file;
	file.open("file.txt");

	for (int i = 0; i < ARRAY_SIZE; i++) {
		file >> personArray[i];
		std::cout << personArray[i];
	}
	delete[] personArray;
}

int main(void) {
	save();
	load();

	std::cin.get();
	return 0;
}