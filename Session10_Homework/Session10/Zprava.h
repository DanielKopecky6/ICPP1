#ifndef ZPRAVA_H
#define ZPRAVA_H
#include <iostream>
#include <string>

struct Zprava {
	int id;
	std::string adrZdroj;
	std::string adrCil;
	std::string obsah;
	Zprava() :id(0) {}
	Zprava(int id, std::string adrZdroj, std::string adrCil, std::string obsah) :
		id(id), adrZdroj(adrZdroj), adrCil(adrCil), obsah(obsah) {}
	~Zprava() {}
};
#endif // !ZPRAVA_H
