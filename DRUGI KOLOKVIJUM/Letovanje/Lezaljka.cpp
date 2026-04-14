#include "Lezaljka.h"

Lezaljka::Lezaljka() : broj(), cena()
{
}

Lezaljka::Lezaljka(int b, int c) : broj(b), cena(c)
{
}

Lezaljka::~Lezaljka()
{
}

Lezaljka& Lezaljka::operator=(const Lezaljka& le)
{
	if (this != &le)
	{
		broj = le.broj; cena = le.cena;
	}
	return *this;
}

ostream& operator<<(ostream& o, const Lezaljka& le)
{
	o << le.broj << " " << le.cena;
	
	return o;
}

istream& operator>>(istream& i, Lezaljka& le)
{
	i >> le.broj >> le.cena;
	
	return i;
}
