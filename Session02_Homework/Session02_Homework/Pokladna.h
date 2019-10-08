#pragma once
#ifndef _POKLADNA_H

#include "Uctenka.h"
class Pokladna
{
private:
	Uctenka * poleUctenek;
	int pocetVydanychUctenek;
	static int citacId;
public:
	Pokladna();
	~Pokladna();
	Uctenka& vystavUctenku(double castka, double dph);
	Uctenka& dejUctenku(int cisloUctenky);
	double dejCastku();
	double dejCastkuVcDph();
};
#endif;
