#pragma once
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class Kolekcija
{
private:
	T* niz;
	int n, tren;
public:
	Kolekcija() {

		niz = nullptr;
		n = 0; tren = 0;
	}
	Kolekcija(int nn) {

		niz = new T[nn];
		n = nn; tren = 0;

	}
	virtual ~Kolekcija() {

		if (niz != nullptr)
		{
			delete[] niz;
			niz = nullptr;
		}
	}
	void DodajPodatak(T podatak) {

		if (tren < n)
		{
			niz[tren++] = podatak;
		}
		else
			throw NIZ_PUN;
	}
	void Obrisi(int indeks) {

		if (indeks < 0 || indeks >= tren)
			throw POGRESAN_INDEKS;
		else
		{
			for (int i = indeks; i < tren - 1; i++)
				niz[i] = niz[i + 1];
			tren--;
		}

	}
	
	float OdrediProsek() {

		float s = 0;
		for (int i = 0; i < tren; i++)
			s = s + niz[i];

		return s / tren;
	}

	T NajveciPodatak() {

		T s = niz[0];

		for (int i = 1; i < tren; i++)
			if (s < niz[i])
				s = niz[i];

		return s;
	}
	void Sacuvaj(const char* naziv) {

		ofstream f(naziv);
		if (f.good())
		{
			f << tren << endl;

			for (int i = 0; i < tren; i++)
				f << niz[i] << " ";
		}
		else
			throw GRESKA_SACUVAJ;

	}

	void Ucitaj(const char* naziv) {

		ifstream f(naziv);
		if (f.good())
		{
			f >> tren;

			if (tren > n) {

				delete[] niz;
				n = tren;
				niz = new T[tren];
			}

			for (int i = 0; i < tren; i++)
				f >> niz[i];
		}
		else
			throw GRESKA_UCITAJ;
	}

	friend ostream& operator<<(ostream& o, const Kolekcija<T>& kol) {

		for (int i = 0; i < kol.tren; i++)
			o << kol.niz[i] << " ";

		return o;
	}
};

