#define _STR_SECURE_NO_WARNINGS
#include "Skijanje.h"

Skijanje::Skijanje() : Putnik(), duzina(), masa_sk(), masa_pan()
{
}

Skijanje::Skijanje(const char* i, const char* s, double d, double m, double mp)
	: Putnik(i, s), duzina(d), masa_sk(m), masa_pan(mp)
{
}

Skijanje::~Skijanje()
{
}

double Skijanje::tezina() const
{
	return masa_sk + masa_pan;
}

void Skijanje::print(ostream& o) const
{
	Putnik::print(o);
	o << duzina << ", " << masa_sk << ", " << masa_pan;
}

Putnik* Skijanje::clone()
{
	return new Skijanje(*this);
}
