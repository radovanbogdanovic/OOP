#include "IspitPriprema.h"
#include "IspitniMaterijal.h"
#include <stdio.h>
#include <iostream>
using namespace std;




IspitPriprema::IspitPriprema()
{
	kolekcija = nullptr;
	zauzeto = 0;
	n = 0;
}

IspitPriprema::IspitPriprema(int _n)
{
	n = _n;
	ZauzmiMemoriju(n);
	zauzeto = 0;
}

IspitPriprema::~IspitPriprema()
{
	if (kolekcija != nullptr) {
		for (int i = 0; i < n; i++) {
			delete kolekcija[i];
		}
		delete[] kolekcija;
	}
}

void IspitPriprema::ZauzmiMemoriju(int x)
{
	kolekcija = new IspitniMaterijal * [n];
	for (int i = 0; i < n; i++) {
		kolekcija[i] = nullptr;
	}
}

void IspitPriprema::Dodaj(IspitniMaterijal * drugi)
{
	if (zauzeto >= n) {
		cout << "Nema dovoljno mesta za novi materijal.";
	}
	else {
		kolekcija[zauzeto] = drugi;
		zauzeto++;
		cout << "Materijal je dodat.";
	}
}

void IspitPriprema::Obrisi(int k)
{
	int a = 0;
	for (int i = 0; i < zauzeto; i++) {
		if (k == kolekcija[i]->vratiOznaku()) {
			if (kolekcija[i]->jelSavladan() == false) {
				a = 1;
				delete kolekcija[i];
				for (int j = i; j < zauzeto - 1; j++) {
					kolekcija[j] = kolekcija[j + 1];
				}
				zauzeto--;
			}
			else {
				cout << "Materijal je savladan, pa tako nije ni obrisan.  " << endl;
				return;
			}
		}
		if (a == 1) {
			cout << "Materijal je obrisan. " << endl;
		}
		else {
			cout << "Nije pronadjen materijal sa datom oznakom. " << endl;
		}

	}
}

void IspitPriprema::Savladaj(int y)
{
	int a = 0;
	for (int i = 0; i < zauzeto; i++) {
		if (y == kolekcija[i]->vratiOznaku()) {
			a++;
			(kolekcija[i]->setSavladan(true));
		}
	}
		if (a == 0) {
			cout << "Nije pronadjen materijal sa datom oznakom " << endl;
		}
		else {
			cout << "Savladan " << endl;
		}
}

int IspitPriprema::UkupnoSavladanih()
{
	int a = 0;
	for (int i = 0; i < zauzeto; i++) {
		if (kolekcija[i]->jelSavladan() == true) {
			a += 1;
		}
	}
	return a;
}

double IspitPriprema::UkupnoVreme(int v)
{
	double vreme = 0;
		if (kolekcija != nullptr) {
			for (int i = 0; i < zauzeto; i++) {
				vreme += kolekcija[i]->potrebnovreme(v);
			}
			return vreme;
		}
	return vreme;
}

void IspitPriprema::VratiNaj(int v, IspitniMaterijal** min, IspitniMaterijal** max)
{
	if (kolekcija == nullptr || zauzeto == 0) {
		*min = nullptr;
		*max = nullptr;
		return;
	}
	*min = kolekcija[0];
	*max = kolekcija[0];
	for (int i = 0; i < zauzeto; i++) {
		if ((*min)->potrebnovreme(v) > kolekcija[i]->potrebnovreme(v))
			*min = kolekcija[i];
	}
	for (int i = 0; i < zauzeto; i++) {
		if ((*max)->potrebnovreme(v) < kolekcija[i] -> potrebnovreme(v)) {
			*max = kolekcija[i];
		}

	}
}

ostream& operator<<(ostream & os, IspitPriprema & i)
{
	os << "Kapacitet ispitnog materijala: " << i.n << endl;
	os << "Broj materijala: " << i.zauzeto << endl;
	for (int j = 0; j < i.zauzeto; j++) {
		os << *i.kolekcija[j] << endl; 
	}
	return os;
}
