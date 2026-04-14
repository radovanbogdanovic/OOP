#define _CRT_SECURE_NO_WARNINGS
#include "Ispit.h"

Ispit::Ispit() : naziv(nullptr), ocena(0), espb(0)
{
}

Ispit::Ispit(const char* n, int o, int e) : ocena(o), espb(e)
{
	naziv = new char[strlen(n)+1];
	strcpy(naziv, n);

}

Ispit::Ispit(const Ispit& i) : ocena(i.ocena), espb(i.espb)
{
	naziv = new char[strlen(i.naziv)+1];
	strcpy(naziv, i.naziv);

}

Ispit::~Ispit()
{
	if (naziv != nullptr)
		delete[] naziv;
}

Ispit& Ispit::operator=(const Ispit& i)
{
	if (this != &i)
	{
		if (naziv != nullptr)
			delete[] naziv;

		naziv = new char[strlen(i.naziv)+1];
		strcpy(naziv, i.naziv);

		espb = i.espb;
		ocena = i.ocena;
	}
	return *this;
}

ostream& operator<<(ostream& o, const Ispit& i)
{
	o << i.naziv << " " << i.ocena << " " << i.espb;
	return o;
}

istream& operator>>(istream& ii, Ispit& i) {
	char temp[100];
	ii >> temp >> i.ocena >> i.espb;  // sada radi jer je friend
	delete[] i.naziv;                  // oslobodi staru memoriju
	i.naziv = new char[strlen(temp) + 1];
	strcpy(i.naziv, temp);
	return ii;
}


