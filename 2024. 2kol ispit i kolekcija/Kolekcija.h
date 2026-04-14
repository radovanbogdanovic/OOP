#pragma once
#include <iostream>
#include <fstream>
#include "Greska.h"
#include "Ispit.h"
using namespace std;

template <class T>
class Kolekcija {
public:
	int maxbroj;
	int trenutno;
	T* objekti;
public:
	Kolekcija();
	Kolekcija(int m);
	~Kolekcija();
	void DodajPodatak(T t);
	void Obrisi(int j);
	float OdrediProsek();
	T NajveciPodatak();

	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);

	template <class T>
	friend ostream& operator<<(ostream& os, const Kolekcija<T>& k);
};

template <class T>
Kolekcija<T>::Kolekcija() {
	maxbroj = 0;
	trenutno = 0;
	objekti = nullptr;
}

template <class T>
Kolekcija<T>::Kolekcija(int m) : maxbroj(m), trenutno(0)
{
	objekti = new T[maxbroj];
}

template <class T>
Kolekcija<T>::~Kolekcija() 
{
	delete[] objekti;
}

template <class T>
void Kolekcija<T>::DodajPodatak(T t)
{
	if (maxbroj <= trenutno)
		throw KOLEKCIJA_PUNA;
	objekti[trenutno++] = t;
}

template<class T>
void Kolekcija<T>::Obrisi(int j)
{
	if (j < 0 || j >= trenutno)
		throw NEISPRAVAN_INDEKS;
	for (int i = j; i < trenutno - 1; i++)
		objekti[i] = objekti[i + 1];
	trenutno--;	
}

template <> //mora da bude bez class T jer je dole int
float Kolekcija<int>::OdrediProsek() {
	if (trenutno == 0)
		throw PRAZNA_KOLEKCIJA;

	float suma = 0;
	for (int i = 0; i < trenutno; i++)
		suma += objekti[i];

	return suma / trenutno;
}

template <class T>
float Kolekcija<T>::OdrediProsek() {
	if (trenutno == 0)
		throw PRAZNA_KOLEKCIJA;

	float suma = 0;
	for (int i = 0; i < trenutno; i++)
		suma += objekti[i].GetOcena();

	return suma / trenutno;
}

template <>
int Kolekcija<int>::NajveciPodatak()
{
	int naj = objekti[0];
	for (int i = 1; i < trenutno; i++)
		if (objekti[i] > naj)
		{
			naj = objekti[i];
		}
	return naj;
}

template <>
Ispit Kolekcija<Ispit>::NajveciPodatak()
{
	int indeks = 0;
	int najvr = objekti[0].GetEspb();
	for (int i = 1; i < trenutno; i++)
		if (objekti[i].GetEspb() > najvr)
		{
			najvr = objekti[i].GetEspb();
			indeks = i;
		}
	return objekti[indeks];
}

template<class T>
void Kolekcija<T>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz)
		throw FAJL_GRESKA_SACUVAJ;
	izlaz << trenutno << endl;
	for (int i = 0; i < trenutno; i++)
		izlaz << objekti[i] << " ";
	izlaz.close();
}

template<class T>
void Kolekcija<T>::Ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (!ulaz)
		throw FAJL_GRESKA_UCITAJ;
	ulaz >> trenutno;
	if (trenutno > maxbroj)
		throw KOLEKCIJA_PUNA;
	for (int i = 0; i < trenutno; i++)
		ulaz >> objekti[i];
	ulaz.close();
}

template<class T>
ostream& operator<<(ostream& os, const Kolekcija<T>& k) {
	os << "KOLEKCIJA: max broj: " << k.maxbroj
		<< ", trenutno: " << k.trenutno << "\n";
	for (int i = 0; i < k.trenutno; i++)
		os << "    " << k.objekti[i] << "\n";
	return os;
}




