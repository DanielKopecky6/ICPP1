#include "Pokladna.h"
#include "Uctenka.h"

#include <iostream>

using namespace std;

int main() {
	Pokladna Pokladna{};

	Uctenka uctenka1 = Pokladna.vystavUctenku(1000, 0.21);
	Uctenka uctenka2 = Pokladna.vystavUctenku(2000, 0.15);
	Uctenka uctenka3 = Pokladna.vystavUctenku(500, 0.21);

	Uctenka dejUctenku = Pokladna.dejUctenku(1001);
	cout << "Nactena uctenka: " << dejUctenku.getCisloUctenky() << " s hodnoutou: " << dejUctenku.getCastka() << " a DPH: " << dejUctenku.getDph() << endl;

	cout << "Celkova castka: " << Pokladna.dejCastku() << " vcetne DPH: " << Pokladna.dejCastkuVcDph() <<   endl;

	std::cin.get();
	return 0;

}