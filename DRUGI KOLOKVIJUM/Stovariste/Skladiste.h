#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Skladiste {

private:
	T* niz;
	int n, tren;

public:
	Skladiste() {

		niz = nullptr;
		n = 0; tren = 0;

	}
	Skladiste(int nn) {

		n = nn; tren = 0;
		niz = new T[nn];

	}

	virtual ~Skladiste() {

		if (niz != nullptr)
		{
			delete[] niz;
			niz = nullptr;
		}
	}

	void Dodaj(T podatak) {

		if (tren < n)
			niz[tren++] = podatak;
		else
			throw NIZ_PUN;

	}

	void Preuzmi(int indeks, int kolicina) {

		if (indeks < 0 || indeks >= tren)
			throw LOS_INDEKS;
		else {

			if (niz[indeks] >= kolicina)
				niz[indeks] = niz[indeks] - kolicina;
			else
				throw LOSA_KOLICINA;


			if (niz[indeks] == 0)
			{
				for (int i = indeks; i < tren - 1; i++)
				{
					niz[i] = niz[i + 1];
				}
				tren--;
			}
		}
	}

	friend ostream& operator<<(ostream& o, const Skladiste& sk) {

		for (int i = 0; i < sk.tren; i++)
			o << sk.niz[i] << " ";

		return o;
	}

	float UkupnaMasa() {

		float rez = 0;

		for (int i = 0; i < tren; i++)
			rez = rez + niz[i];

		return rez;
	}

	int BrojSaVecomKolicinom(int masa) {

		int brojac = 0;
		for (int i = 0; i < tren; i++)
			if (niz[i] > masa)
				brojac++;

		return brojac;
	}

	void NajViseManje(int pocetak, int kraj, T& minimum, T& maximum) {


		if (pocetak < tren && kraj < tren) {

			T min = niz[pocetak]; T max = niz[pocetak];

			for (int i = pocetak; i <= kraj; i++)
			{
				if (min > niz[i])
					min = niz[i];
				if (niz[i] > max)
					max = niz[i];
			}

			minimum = min;
			maximum = max;

		}

	}
	
	void Sacuvaj(const char* naziv) {

		ofstream f(naziv);
		if (!f.good())
			throw SACUVAJ_GRESKA;

		f << tren << endl;

		for (int i = 0; i < tren; i++)
			f << niz[i] << " ";
	}


	void Ucitaj(const char* naziv) {

		ifstream f(naziv);
		if (!f.good())
			throw UCITAJ_GRESKA;

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
};