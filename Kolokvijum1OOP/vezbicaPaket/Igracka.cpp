#define _CRT_SECURE_NO_WARNINGS
#include "Igracka.h"


Igracka::Igracka() : Poklon(), materijal(nullptr)
{
}

Igracka::Igracka(double c, int br, const char* m) : Poklon(c, br)
{
	materijal = new char[strlen(m) + 1];
	strcpy(materijal, m);
}

Igracka::Igracka(const Igracka& i): Poklon(i)
{
	materijal = new char[strlen(i.materijal) + 1];
	strcpy(materijal, i.materijal);
}

Igracka::~Igracka()
{
	if (materijal != 0)
	{
		delete[] materijal;
		materijal = nullptr;
	}
}

void Igracka::print(ostream& o) const
{
	Poklon::print(o);
	o << materijal << endl;
}

int Igracka::BrojMasnica() const
{
	//return Poklon::BrojMasnica() + 2;
	return br_masinca + 2;
}

Poklon* Igracka::clone()
{
	return new Igracka(*this);
}
