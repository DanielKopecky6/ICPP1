#pragma once
#ifndef _UCTENKA_H

#include <iostream>
#include <string>
class Uctenka
{
private:
	int cisloUctenky;
	double castka;
	double dph;
public:
	void setCisloUctenky(int cisloUcctenky);
	int getCisloUctenky();
	void setCastka(double castka);
	double getCastka();
	void setDph(double dph);
	double getDph();
};

#endif