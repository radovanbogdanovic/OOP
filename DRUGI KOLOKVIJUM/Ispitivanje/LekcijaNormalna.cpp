#define _CRT_SECURE_NO_WARNINGS
#include "LekcijaNormalna.h"

LekcijaNormalna::LekcijaNormalna() : naziv(nullptr), duzina(), tezina()
{
}

LekcijaNormalna::LekcijaNormalna(const char* n, float d, float t) : duzina(d), tezina(t)
{
	naziv = new char[strlen(n) + 1];
	strcpy(naziv, n);
}

LekcijaNormalna::LekcijaNormalna(const LekcijaNormalna& le) : duzina(le.duzina), tezina(le.tezina)
{
	naziv = new char[strlen(le.naziv) + 1];
	strcpy(naziv, le.naziv);
}

LekcijaNormalna::~LekcijaNormalna()
{
	if (naziv != nullptr)
	{
		delete[] naziv;
		naziv = nullptr;
	}
}

LekcijaNormalna& LekcijaNormalna::operator=(const LekcijaNormalna& le)
{
	if (this != &le)
	{
		delete[] naziv;
		naziv = new char[strlen(le.naziv) + 1];
		strcpy(naziv, le.naziv);
	}
	duzina = le.duzina; tezina = le.tezina;

	return *this;
}

ostream& operator<<(ostream& o, const LekcijaNormalna& a)
{
	o << a.naziv << " " << a.duzina << " " << a.tezina;
	return o;
}

istream& operator>>(istream& i, LekcijaNormalna& a)
{
	char buffer[100];
	
	i >> buffer >> a.duzina >> a.tezina;
	
	delete[] a.naziv;
	a.naziv = new char[strlen(buffer) + 1];
	strcpy(a.naziv, buffer);
	
	return i;
}
