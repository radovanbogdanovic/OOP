#pragma once
#include "Greske.h"
#include <fstream>
#include <iostream>

template <class T>
class Kolekcija {
private:
	T* niz;
	int n;
	int tren;
public:
	Kolekcija()
	{
		n = 0;
		tren = 0;
		niz = nullptr;
	};
	Kolekcija(int nn) {

		n = nn;
		tren = 0;
		niz = new T[nn];

	};
	virtual ~Kolekcija() {

		if (niz != nullptr) {
			delete[] niz;
		}

	};

	void DodajPodatak(T novi) {

		if (tren < n)
			niz[tren++] = novi;
		else
			throw KOLEKCIJA_PUNA;
	};

	void Obrisi(int nn) {

		if (nn < 0 || nn >= tren)
			throw POGRESAN_INDEKS;
		else
		{
			for (int i = nn; i < tren - 1; i++)
			{
				niz[i] = niz[i + 1];
			}
			tren--;
		}
	};

	float OdrediProsek() {

	 float rez = 0;

	if (tren == 0)
		throw PRAZNA_KOLEKCIJA;

	for (int i = 0; i < tren; i++)
		rez = rez + niz[i];

	return rez / (float)tren;

	};

	T NajveciPodatak() {

		if (tren == 0)
			throw PRAZNA_KOLEKCIJA;

		T max = niz[0];
		for (int i = 0; i < tren; i++)
			if (niz[i] > max)
				max = niz[i];

		return max;
	};

	void Sacuvaj(const char* naziv) {

		ofstream f(naziv);
		if (f.good())
		{
			f << tren << endl;
			for (int i = 0; i < tren; i++)
				f << niz[i] << " ";
		}
		else
			throw FAJL_GRESKA_SACUVAJ;

	};

	void Ucitaj(const char* naziv) {
		ifstream f(naziv);
		if (!f.good())
			throw FAJL_GRESKA_UCITAJ;

		f >> tren;

		if (tren > n) {
			delete[] niz;
			n = tren;
			niz = new T[n];
		}

		for (int i = 0; i < tren; i++)
			f >> niz[i];
	}


	friend ostream& operator<<(ostream& o, const Kolekcija<T>& tip) {

		for (int i = 0; i < tip.tren; i++)
			o << tip.niz[i] << " ";

		return o;
	};
};