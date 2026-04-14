#include "Cokolada.h"

Cokolada::Cokolada()  : Poklon(), kakao()
{}

Cokolada::Cokolada(double c, int br, float k) : Poklon(c, br), kakao(k)
{
}

Cokolada::Cokolada(const Cokolada& c) : Poklon(c), kakao(c.kakao)
{
}

Cokolada::~Cokolada()
{
}

void Cokolada::print(ostream& o) const
{
	Poklon::print(o);
	o << kakao << endl;
}

int Cokolada::BrojMasnica() const
{
	return Poklon::BrojMasnica() * 2;
}

Poklon* Cokolada::clone()
{
	return new Cokolada(*this);
}
