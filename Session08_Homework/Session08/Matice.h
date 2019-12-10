#ifndef MATICE_H
#define MATICE_H
#include <stdexcept>
#include <iostream>
template <typename T>
class Matice {
public:
	T** prvky;
	int radky;
	int sloupce;

	Matice(int aRadky, int aSloupce);
	Matice(const Matice<T>& m);
	~Matice();
	void Nastav(int aRadek, int aSloupek, T aHodnota);
	void NastavZ(T* pole);
	T& Dej(int aRadek, int aSloupec);
	const T& Dej(int aRadek, int aSloupec) const;

	template<typename R>
	Matice<R> Pretypuj()const;

	Matice<T> Transpozice() const;
	Matice<T> Soucin(const Matice& m)const;
	Matice<T> Soucin(T skalar) const;
	Matice<T> Soucet(const Matice& m) const;
	Matice<T> Soucet(T skalar)const;
	bool JeShodna(const Matice& m) const;
	void Vypis();

};

template<typename T>
Matice<T>::Matice(int aRadky, int aSloupce) :radky(aRadky), sloupce(aSloupce)
{
	prvky = new T *[radky];

	for (int i = 0; i < sloupce; i++) {
		prvky[i] = new T[sloupce];
	}
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			prvky[i][j] = 0;
		}
	}
}

template<typename T>
Matice<T>::Matice(const Matice<T>& m)
{
	radky = m.radky;
	sloupce = m.sloupce;
	prvky = new T *[radky];

	for (int i = 0; i < sloupce; i++) {
		prvky[i] = new T[sloupce];
	}
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			prvky[i][j] = m.prvky[i][j];
		}
	}
}

template<typename T>
Matice<T>::~Matice()
{
	for (int i = 0; i < sloupce; i++) {
		delete[] prvky[i];
	}
	delete prvky;
}

template<typename T>
void Matice<T>::Nastav(int aRadek, int aSloupek, T aHodnota)
{
	if (radky >= aRadek && aRadek >= 0 && sloupce >= aSloupek && aSloupek >= 0) {
		prvky[aRadek][aSloupek] = aHodnota;
	}
	else {
		throw std::out_of_range("Neplatny index.");
	}
}

template<typename T>
void Matice<T>::NastavZ(T* pole)
{
	int pocet = 0;
		for (int i = 0; i < radky; i++) {
			for (int j = 0; j < sloupce; j++) {
					prvky[i][j] = pole[pocet++];
			}
		}
}

template<typename T>
T& Matice<T>::Dej(int aRadek, int aSloupec)
{
	if (aRadek <= radky && aRadek >= 0  && aSloupec <= sloupce &&  aSloupec >= 0) {
		return prvky[aRadek][aSloupec];
	}
	else {
		throw std::out_of_range("Neplatn index");	
	}
}

template<typename T>
const T& Matice<T>::Dej(int aRadek, int aSloupec) const
{
	if (aRadek <= radky && aRadek >= 0 && aSloupec <= sloupce &&  aSloupec >= 0) {
		return prvky[aRadek][aSloupec];
	}
	else {
		throw std::out_of_range("Neplatn index");
	}
}

template<typename T>
template<typename R>
Matice<R> Matice<T>::Pretypuj() const
{
	Matice<R> novaMatice = Matice<R>(radky, sloupce);
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			novaMatice.prvky[j][i] = static_cast<R>(prvky[j][i]);
		}
	}
	return novaMatice;
}



template<typename T>
Matice<T> Matice<T>::Transpozice() const
{
	Matice<T> novaMatice = Matice(sloupce, radky);
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			novaMatice.prvky[i][j] = prvky[j][i];
		}
	}
	return novaMatice;
}

template<typename T>
Matice<T> Matice<T>::Soucin(const Matice& m) const
{
	if (sloupce == m.radky) {
		Matice<T> novaMatice = Matice(radky, m.sloupce);
		for (int i = 0; i < radky; i++) {
			for (int j = 0; j < novaMatice.sloupce; j++) {
				for (int k = 0; k < sloupce; k++) {
					novaMatice.prvky[i][j] += prvky[i][k] * m.prvky[k][j];
				}
			}
		}
		return novaMatice;
	}
	else {
		throw std::out_of_range("Nelze nasobit");
	}

}

template<typename T>
Matice<T> Matice<T>::Soucin(T skalar) const
{
	Matice<T> novaMatice = new Matice(this);
	for (int i = 0; i < novaMatice.radky; i++) {
		for (int j = 0; j < novaMatice.sloupce; j++) {
			novaMatice[i][j] = novaMatice[i][j] * skalar;
		}
	}
	return novaMatice;
}

template<typename T>
Matice<T> Matice<T>::Soucet(const Matice& m) const
{
	Matice<T> novaMatice = new Matice(this);
	if (m.radky == radky && m.sloupce == sloupce) {
		for (int i = 0; i < novaMatice.radky; i++) {
			for (int j = 0; j < novaMatice.sloupce; j++) {
				novaMatice[i][j] = novaMatice[i][j] + m[i][j];
			}
		}
		return novaMatice;
	}
	else {
		throw std::out_of_range("Nelze scitat");
	}

}

template<typename T>
Matice<T> Matice<T>::Soucet(T skalar) const
{
	Matice<T> novaMatice = new Matice(this);
	for (int i = 0; i < novaMatice.radky; i++) {
		for (int j = 0; j < novaMatice.sloupce; j++) {
			novaMatice[i][j] = novaMatice[i][j] + skalar;
		}
	}
	return novaMatice;
}

template<typename T>
bool Matice<T>::JeShodna(const Matice& m) const
{
	if (m.radky == radky && m.sloupce == sloupce) {
		for (int i = 0; i < radky; i++) {
			for (int j = 0; j < sloupce; j++) {
				if (prvky[i][j] != m.prvky[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}

}

template<typename T>
void Matice<T>::Vypis()
{
	for (int j = 0; j < sloupce; j++) {
		for (int i = 0; i < radky; i++) {
			std::cout << prvky[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

#endif // !MATICE_H
