#include "Sit.h"
void Sit::ZpracujPrvky()
{
	Fronta<ASitovyPrvek*> frontaPom = Fronta<ASitovyPrvek*>();
	while (!sitovePrvky.JePrazdna()) {
		ASitovyPrvek* sp = sitovePrvky.Odeber();
		sp->Provadej();
		frontaPom.Vloz(sp);
	}
	while (!frontaPom.JePrazdna()) {
		sitovePrvky.Vloz(frontaPom.Odeber());
	}
}

Sit::Sit()
{
	idZpravy = 0;
	sitovePrvky = Fronta<ASitovyPrvek*>();
}

Sit::~Sit()
{
	sitovePrvky.~Fronta();
}

void Sit::Pripoj(ASitovyPrvek* sp)
{
	if (!sitovePrvky.Obsahuje(sp)) {
		sitovePrvky.Vloz(sp);
	}
}

void Sit::ProvadejVse()
{
	ZpracujPrvky();
}
