#include "Pokladna.h"


int Pokladna::citacId = 1000;
int static pocetUctenek = 10;

Pokladna::Pokladna()
{

	pocetVydanychUctenek = 0;
	poleUctenek = new Uctenka[pocetUctenek];
}


Pokladna::~Pokladna()
{
	delete[] poleUctenek;
}

Uctenka & Pokladna::vystavUctenku(double castka, double dph)
{
	
		if (pocetVydanychUctenek < 10) {
			poleUctenek[pocetVydanychUctenek].setCastka(castka);
			poleUctenek[pocetVydanychUctenek].setCisloUctenky(citacId);
			poleUctenek[pocetVydanychUctenek].setDph(dph);
			pocetVydanychUctenek++;
			citacId++;
			
		}
		return poleUctenek[pocetVydanychUctenek];

}

Uctenka & Pokladna::dejUctenku(int id)
{

		for (int i = 0; i < pocetVydanychUctenek; i++) {
			if (poleUctenek[i].getCisloUctenky() == id) {
				return poleUctenek[i];
			}
		}
		return poleUctenek[0];

}

double Pokladna::dejCastku() const
{
	double castka = 0;
	for (int i = 0; i < pocetVydanychUctenek; i++) {
		castka += poleUctenek[i].getCastka();
	}
	return castka;
}

double Pokladna::dejCastkuVcDph() const
{
	double castka = 0;
	for (int i = 0; i < pocetVydanychUctenek; i++) {
		castka += poleUctenek[i].getCastka() * (1 + (poleUctenek[i].getDph()));
	}
	return castka;
}