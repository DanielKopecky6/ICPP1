#include "Hub.h"

Hub::Hub(int maxPocetPripojenychPortu)
{
	prichoziZpravy = Fronta<ZpravaPort>();
	pripojenePrvky = new ASitovyPrvek *[maxPocetPripojenychPortu];
	maximumPripojenychPortu = maxPocetPripojenychPortu;
	for (int i = 0; i < maxPocetPripojenychPortu; i++) {
		pripojenePrvky[i] = nullptr;
	}
}

Hub::~Hub()
{
	delete[]pripojenePrvky;
}

void Hub::Pripoj(ASitovyPrvek* sp)
{
	for (int i = 0; i < maximumPripojenychPortu; i++) {
		if (pripojenePrvky[i] == nullptr) {
			pripojenePrvky[i] = sp;
			break;
		}
	}
}

void Hub::Provadej()
{
	while (!prichoziZpravy.JePrazdna()) {
		ZpravaPort zp = prichoziZpravy.Odeber();
		ZpracujPrichoziZpravu(zp);
	}
}

void Hub::ZpracujPrichoziZpravu(ZpravaPort zp)
{
	if (zpracovaneZpravy.Obsahuje(zp.zprava)) {
		return;
	}
	for (int i = 0; i < maximumPripojenychPortu; i++) {
		if (pripojenePrvky[i] != nullptr) {
			if (pripojenePrvky[i] != zp.port) {
				pripojenePrvky[i]->VlozPrichoziZpravu(zp.zprava, this);
			}
		}
		zpracovaneZpravy.Vloz(zp.zprava);
	}
}
