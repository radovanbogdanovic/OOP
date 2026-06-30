#define _CRT_SECURE_NO_WARNINGS
#include "OsnovnaKarta.h"
#include <cstring>

OsnovnaKarta::OsnovnaKarta() : oznaka(nullptr), sektor(' '), cena(0)
{
	oznaka = new char[1];
	strcpy(oznaka, "");
}

OsnovnaKarta::OsnovnaKarta(const char* ooznaka, char ssektor, int ccena) : oznaka(nullptr), sektor(ssektor), cena(ccena)
{
	if (ooznaka == nullptr)
		ooznaka = "";

	oznaka = new char[strlen(ooznaka) + 1];
	strcpy(oznaka, ooznaka);
}

OsnovnaKarta::OsnovnaKarta(const OsnovnaKarta& ok) : oznaka(nullptr), sektor(ok.sektor), cena(ok.cena)
{
	oznaka = new char[strlen(ok.oznaka) + 1];
	strcpy(oznaka, ok.oznaka);
}

OsnovnaKarta::~OsnovnaKarta()
{
	if (oznaka != nullptr)
	{
		delete[] oznaka;
		oznaka = nullptr;
	}
}

OsnovnaKarta& OsnovnaKarta::operator=(const OsnovnaKarta& ok)
{
	if (this != &ok)
	{
		if (oznaka != nullptr)
			delete[] oznaka;

		oznaka = new char[strlen(ok.oznaka) + 1];
		strcpy(oznaka, ok.oznaka);
		sektor = ok.sektor;
		cena = ok.cena;
	}

	return *this;
}

float OsnovnaKarta::UkupnaCena() const
{
	return cena;
}

void OsnovnaKarta::IspisiOsnovno(ostream& o) const
{
	o << "oznaka: " << oznaka << ", sektor: " << sektor << ", cena: " << cena;
}

void OsnovnaKarta::Ispisi(ostream& o) const
{
	IspisiOsnovno(o);
}

ostream& operator<<(ostream& o, const OsnovnaKarta& ok)
{
	ok.Ispisi(o);
	return o;
}
