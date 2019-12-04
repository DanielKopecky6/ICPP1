#ifndef A_SITOVY_PRVEK_H
#define A_SITOVY_PRVEK_H
#include "Fronta.h"
#include "Zprava.h"
#include "ZpravaPort.h"

struct ASitovyPrvek {
public:
	virtual ~ASitovyPrvek() {}
	void VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port);
	virtual void Provadej() = 0;
	virtual void Pripoj(ASitovyPrvek* sp) = 0;
	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) = 0;
	Fronta<ZpravaPort> prichoziZpravy;
};

#endif // !A_SITOVY_PRVEK_H
