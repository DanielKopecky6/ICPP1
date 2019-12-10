#include "Matice.h"
#include<iostream>

int main()
{
	Matice<int> m{ 3,3 };
	int jednodpole[] = { 0,1,2,3,4,5,6,7,8 };
	m.NastavZ(jednodpole);
	m.Vypis();
	Matice<int> mt = m.Transpozice();
	mt.Vypis();
	Matice<int> mmt = m.Soucin(mt);
	mmt.Vypis();
	Matice<double> mmt_d = mmt.Pretypuj<double>();
	mmt_d.Vypis();
	std::cout << "" << std::endl;
	Matice<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.NastavZ(jednodpole_d);
	n_d.Vypis();
	std::cout << "" << std::endl;
	Matice<double> mmtn_d = mmt_d.Soucin(n_d);
	mmtn_d.Vypis();
	std::cout << "" << std::endl;
	Matice<int> r = mmtn_d.Pretypuj<int>();
	Matice<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.NastavZ(tpole);
	t.Vypis();
	std::cout << "" << std::endl;
	std::cout << "r==t ? " << (r.JeShodna(t) ? "true" : "false") << std::endl;
	std::cin.get();
	return 0;
}
