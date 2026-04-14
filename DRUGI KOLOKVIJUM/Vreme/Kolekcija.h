#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Kolekcija
{
private:
	T* niz;
	int n, tren;

public:
	Kolekcija() {
	
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
	
		if (niz != 0)
		{
			delete[] niz;
			niz = nullptr;

		}
	
	};

	void DodajPodatak(T podatak) {

		if (tren >= n)
			throw NEMA_MESTA;

		niz[tren++] = podatak;
	}

	void Obrisi(int indeks) {

		if (indeks < 0 || indeks >= tren)
			throw POGRESAN_INDEKS;

		for (int i = indeks; i < tren - 1; i++)
			niz[i] = niz[i + 1];

			tren--;

	}

	float OdrediProsek() {

		if (tren == 0)
			throw PRAZAN_NIZ;

		float rez = 0;

		for (int i = 0; i < tren; i++)
			rez = rez + niz[i];

		return rez / float(tren);
	}


	T NajveciPodatak() {

		if (tren == 0)
			throw PRAZAN_NIZ;

		T rez = niz[0];

			for (int i = 1; i < tren; i++)
				if (rez < niz[i])
					rez = niz[i];

		return rez;
	}

	void Sacuvaj(const char* tekst) {

		ofstream f(tekst);

		if (!f.good())
			throw PROBLEM_SA_FAJLOM;


		f << tren << endl;
		for (int i = 0; i < tren; i++)
			f << niz[i] << " ";

	}

	void Ucitaj(const char* tekst) {

		ifstream f(tekst);

		if (!f.good())
			throw PROBLEM_SA_FAJLOM;


		f >> tren;

		if (tren < n)
		{
			for (int i = 0; i < tren; i++)
				f >> niz[i];
		}
		else
		{
			delete[] niz;
			n = tren;
			niz = new T[tren];

			for (int i = 0; i < tren; i++)
				f >> niz[i];
		}

	}

	friend ostream& operator<<(ostream& o, const Kolekcija<T>& t) {

		for(int i=0; i<t.tren; i++)
		o << t.niz[i] << ", ";

		return o;
	}

};

