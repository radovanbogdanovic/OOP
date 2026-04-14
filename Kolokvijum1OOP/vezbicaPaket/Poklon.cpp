#include "Poklon.h"

Poklon::Poklon() : cena(), br_masinca()
{
}

Poklon::Poklon(double c, int br) : cena(c), br_masinca(br)
{
}

Poklon::Poklon(const Poklon& p): cena(p.cena), br_masinca(p.br_masinca)
{
}

Poklon::~Poklon()
{
}

void Poklon::print(ostream& o) const
{
	o << cena << ", " << br_masinca << endl;
}

ostream& operator<<(ostream& o, const Poklon& p)
{
	p.print(o);
	return o;
}

int Poklon::BrojMasnica() const
{
	return br_masinca;
}
