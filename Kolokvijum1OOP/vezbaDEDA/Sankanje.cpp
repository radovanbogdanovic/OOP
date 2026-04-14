#define _STR_SECURE_NO_WARNINGS
#include "Sankanje.h"

Sankanje::Sankanje() : Putnik(), zapremina(), gustina()
{
}

Sankanje::Sankanje(const char* i, const char* s, double z, double g) : Putnik(i, s), zapremina(z), gustina(g)
{
}

double Sankanje::tezina() const
{
	return zapremina * gustina;
}

void Sankanje::print(ostream& o) const
{
	Putnik::print(o);
	o << zapremina << ", " << gustina << endl;
}

Putnik* Sankanje::clone()
{
	return new Sankanje(*this);
}
