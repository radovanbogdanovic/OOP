#pragma once
#include "Greska.h"
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class Ispit {

private:
	T* niz;
	int n, tren;
public:
	Ispit() {

		niz = nullptr;
		n = 0; tren = 0;
	}
	Ispit(int nn) {

		niz = new T[nn];
		n = nn; tren = 0;
	}
	virtual ~Ispit() {

		if (niz != nullptr)
		{
			delete[] niz;
			niz = nullptr;
		}

	}
	void Dodaj(T podatak) {

		if (tren >= n)
			throw NIZ_PUN;

		niz[tren++] = podatak;

	}

	void Izbaci(int indeks, int broj) {

		if (indeks < 0 || indeks >= tren)
			throw LOS_INDEKS;

		int brojac = 0;
		while (brojac != broj)
		{
			for (int i = indeks; i < tren-1; i++)
				niz[i] = niz[i + 1];
			tren--;
			brojac++;
		}
	}

	float Ukupno() {
		float s = 0;
		for (int i = 0; i < tren; i++)
			s = s + niz[i];
		return s;
	}


	int UkupniBrojVrednost(float& vrednost, float& ukupnaVrednost) {

		int brojac = 0; float ukupna = 0;
		for (int i = 0; i < tren; i++)
			if (niz[i] > vrednost)
			{
				brojac++;
				ukupna = ukupna + niz[i];
			}
		ukupnaVrednost = ukupna;
			return brojac;
	}

	void minMax(int poc, int kraj, T &min, T &max) {

		if (poc < 0 || poc >= tren || kraj < 0 || kraj >= tren || kraj < poc)
			throw LOS_INDEKS;

		T mini = niz[poc];
		T maxi = niz[poc];

		for (int i = poc; i < kraj; i++)
		{
			if (mini > niz[i])
				mini = niz[i];

			if (niz[i] > maxi)
				maxi = niz[i];
		}

		min = mini;
		max = maxi;
	}

	void Sacuvaj(const char* naziv) {

		ofstream f(naziv);
		if (!f.good())
			throw GRESKA_SACUVAJ;

		f << tren << endl;

		for (int i = 0; i < tren; i++)
			f << niz[i] << " ";

	}

	void Ucitaj(const char* naziv) {

		ifstream f(naziv);
		if (!f.good())
			throw GRESKA_UCITAJ;

		f >> tren;

		if (tren > n)
		{
			delete[] niz;
			n = tren;
			niz = new T[tren];
		}
		for (int i = 0; i < tren; i++)
			f >> niz[i];

	}

	friend ostream& operator<<(ostream& o, const Ispit<T>& is) {

		for (int i = 0; i < is.tren; i++)
		o << is.niz[i] << " ";
		return o;
	}
};