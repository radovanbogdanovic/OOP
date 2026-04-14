#pragma once
#include "Greska.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Plaza {

private:
	T** matrica;
	int red, kolona;

public:
	Plaza() {
		matrica = nullptr;
		red = 0;
		kolona = 0;
	}

	Plaza(int redd, int kolonaa) {
		red = redd;
		kolona = kolonaa;
		matrica = new T * [red];
		for (int i = 0; i < red; i++)
			matrica[i] = new T[kolona]();
	}

	virtual ~Plaza() {
		if (matrica != nullptr) {
			for (int i = 0; i < red; i++) {
				delete[] matrica[i];
			}
			delete[] matrica;
			matrica = nullptr;
		}
	}

	void Dodaj(int r, int k, T l) {
		if (r < 0 || k < 0 || r >= red || k >= kolona)
			throw GRESKA_INDEKS;

		// Poredimo sa default objektom T() jer matrica[r][k] nije pokazivac
		if (matrica[r][k] == 0)
			matrica[r][k] = l;
		else
			throw ZAUZETA_LEZALJKA;
	}

	void Oslobodi(int r, int k) {
		if (r < 0 || k < 0 || r >= red || k >= kolona)
			throw GRESKA_INDEKS;

		matrica[r][k] = T();
	}

	float Ukupno() {
		float suma = 0;
		for (int i = 0; i < red; i++)
			for (int j = 0; j < kolona; j++)
				suma = suma + matrica[i][j];

		return suma;
	}

	int BrojMesta(int broj) {
		int brojac = 0;
		for (int i = 0; i < red; i++)
			for (int j = 0; j < kolona; j++)
				if (matrica[i][j] == broj)
					brojac++;

		return brojac;
	}

	int RedSaNajvise(int& broj) {
		int rez = 0;
		int max = 0;

		for (int i = 0; i < red; i++) {
			int sumaReda = 0;
			for (int j = 0; j < kolona; j++)
				sumaReda = sumaReda + matrica[i][j];

			if (sumaReda > max) {
				max = sumaReda;
				rez = i;
			}
		}

		broj = max;
		return rez;
	}

	void Sacuvaj(const char* naziv) {
		ofstream f(naziv);
		if (!f.good())
			throw GRESKA_SACUVAJ;

		f << red << " " << kolona << endl;
		for (int i = 0; i < red; i++) {
			for (int j = 0; j < kolona; j++)
				f << matrica[i][j] << " ";
			f << endl;
		}
	}

	void Ucitaj(const char* naziv) {
		ifstream f(naziv);
		if (!f.good())
			throw GRESKA_UCITAJ;

		// Ciscenje memorije ako je matrica vec bila alocirana
		if (matrica != nullptr) {
			for (int i = 0; i < red; i++) delete[] matrica[i];
			delete[] matrica;
		}

		f >> red >> kolona;
		matrica = new T * [red];
		for (int i = 0; i < red; i++) {
			matrica[i] = new T[kolona];
			for (int j = 0; j < kolona; j++)
				f >> matrica[i][j];
		}
	}

	friend ostream& operator<<(ostream& it, const Plaza<T>& p) {
		for (int i = 0; i < p.red; i++) {
			for (int j = 0; j < p.kolona; j++)
				it << p.matrica[i][j] << " ";
			it << endl;
		}
		return it;
	}
};