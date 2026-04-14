#define _CRT_SECURE_NO_WARNINGS
#include "Putnik.h"
#include <cstring>

Putnik::Putnik(const char* i, const char* s)
{
	ime = new char[strlen(i) + 1];
	strcpy(ime, i);

	sediste = new char[strlen(s) + 1];
	strcpy(sediste, s);
}

Putnik::~Putnik()
{
	delete[] ime;
	delete[] sediste;
}

Putnik::Putnik(const Putnik& p)
{
	this->ime = new char[strlen(p.ime) + 1];
	strcpy(this->ime, p.ime);

	sediste = new char[strlen(p.sediste) + 1];
	strcpy(this->sediste, p.sediste);
}

Putnik* Putnik::Kopija() const
{
	return new Putnik(*this);
}

void Putnik::print(ostream& os) const
{
	os << " ime: " << ime
		<< ", sediste: " << sediste;
}

ostream& operator<<(ostream& os, Putnik& p)
{
	p.print(os);
	return os;
	// TODO: insert return statement here
}
