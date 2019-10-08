#include "Uctenka.h"


void Uctenka::setCisloUctenky(int cislo) {
	this->cisloUctenky = cislo;
}
void Uctenka::setCastka(double castka) {
	this->castka = castka;
}
void Uctenka::setDph(double dph) {
	this->dph = dph;
}

double Uctenka::getDph() {
	return dph;
}
int Uctenka::getCisloUctenky() {
	return cisloUctenky;
}
double Uctenka::getCastka() {
	return castka;
}

