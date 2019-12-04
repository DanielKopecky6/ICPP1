#ifndef HUB_H
#define HUB_H
#include"ASitovyPrvek.h"

struct Hub : ASitovyPrvek {
private:
	int maximumPripojenychPortu;
	ASitovyPrvek** pripojenePrvky;
	Fronta <Zprava*> zpracovaneZpravy;
	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) override;
public:
	Hub(int maxPocetPripojenychPortu);
	~Hub();
	virtual void Pripoj(ASitovyPrvek* sp) override;
	virtual void Provadej() override;
};
#endif // !HUB_H

