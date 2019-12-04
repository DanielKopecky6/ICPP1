#include "Uzel.h"
#include"Sit.h"
Uzel::Uzel(std::string adresa) :Adresa(adresa)
{
	odchoziZpravy = Fronta<Zprava*>();
}

Uzel::~Uzel()
{
	odchoziZpravy.~Fronta();
	pripojenyPrvek->~ASitovyPrvek();
}

void Uzel::Pripoj(ASitovyPrvek* sitovyPrvek)
{
	pripojenyPrvek = sitovyPrvek;
}

void Uzel::Provadej()
{
	while (!odchoziZpravy.JePrazdna()) {
		Zprava* zpravaOdeslani = odchoziZpravy.Odeber();
		pripojenyPrvek->VlozPrichoziZpravu(zpravaOdeslani, this);
	}
	while (!prichoziZpravy.JePrazdna()) {
		ZpravaPort zp = prichoziZpravy.Odeber();
		ZpracujPrichoziZpravu(zp);
	}
}

void Uzel::ZpracujPrichoziZpravu(ZpravaPort zp)
{
	if (zp.zprava->adrCil != Adresa) {
		return;
	}
	Zprava* z = zp.zprava;
	std::cout << "Cil: " << z->adrCil << ", idZpravy:" << z->id << ",zdroj: " << z->adrZdroj << ", obsah: " << z->obsah << std::endl;
	if (z->obsah == "ping") {
		PripravZpravuKOdeslani(z->adrZdroj, "pong");
	}
}

void Uzel::PripravZpravuKOdeslani(std::string cil, std::string obsah)
{
	Zprava *z = new Zprava(Sit::DejNoveId(), Adresa, cil, obsah);
	odchoziZpravy.Vloz(z);
}
