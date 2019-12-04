#ifndef UZEL_H
#define UZEL_H
#include"ASitovyPrvek.h"


struct Uzel : ASitovyPrvek {
private:
	std::string Adresa;
	ASitovyPrvek* pripojenyPrvek;
	Fronta<Zprava*> odchoziZpravy;
	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) override;
public:
	Uzel(std::string adresa);
	~Uzel();
	virtual void Pripoj(ASitovyPrvek* sp) override;
	virtual void Provadej() override;
	void PripravZpravuKOdeslani(std::string cil, std::string obsah);
};
#endif // UZEL_H
