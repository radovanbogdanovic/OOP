#define _CRT_SECURE_NO_WARNINGS
#include "Putnik.h"

Putnik::Putnik() : ime(nullptr), sifra(nullptr)
{
}

Putnik::Putnik(const char* i, const char* s)
{
	ime = new char[strlen(i) + 1];
	strcpy(ime, i);

	sifra = new char[strlen(s) + 1];
	strcpy(sifra, s);
}

Putnik::Putnik(const Putnik& p)
{
	ime = new char[strlen(p.ime) + 1];
	strcpy(ime, p.ime);

	sifra = new char[strlen(p.sifra) + 1];
	strcpy(sifra, p.sifra);
}

Putnik::~Putnik()
{
	if (ime != nullptr)
	{
		delete[] ime;
		ime = nullptr;
	}
	if (sifra != nullptr)
	{
		delete[] sifra;
		sifra = nullptr;
	}

}

void Putnik::print(ostream& o) const
{
	o << ime << ", " << sifra << endl;
}

ostream& operator<<(ostream& o,const Putnik& p)
{
	p.print(o);
	return o;
}
