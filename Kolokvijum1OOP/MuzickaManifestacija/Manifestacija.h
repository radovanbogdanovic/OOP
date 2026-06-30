#pragma once
#include "OsnovnaKarta.h"

class Manifestacija
{
private:
	OsnovnaKarta** niz;
	int n;
	int tren;

	int brSektora;
	char* sektori;

	int brDana;
	float* ucesceDana;

	void Oslobodi();
	void Kopiraj(const Manifestacija& m);
	void PostaviSektore(int bbrSektora, const char* ssektori);
	void PostaviDane(int bbrDana, const float* uucesceDana);
	int IndeksSektora(char sektor) const;

public:
	Manifestacija();
	Manifestacija(int nn);
	Manifestacija(int nn, int bbrSektora, const char* ssektori, int bbrDana, const float* uucesceDana);
	Manifestacija(const Manifestacija& m);
	~Manifestacija();

	Manifestacija& operator=(const Manifestacija& m);

	void Dodaj(OsnovnaKarta* karta);
	void VratiKarte(int indeks, int broj);
	float UkupnaZarada() const;
	char SektorSaNajviseKarata() const;
	int DanSaNajvecomZaradom(int& zarada) const;
	void NajskupljeKarte(OsnovnaKarta** max, OsnovnaKarta** afterMax) const;

	friend ostream& operator<<(ostream& o, const Manifestacija& m);
};
