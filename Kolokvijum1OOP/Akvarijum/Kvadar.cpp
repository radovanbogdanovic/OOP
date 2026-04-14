#include "Kvadar.h"
#include <cstring>
#include <iostream>
using namespace std;

Kvadar::Kvadar() : Akvarijum(), a(), b(), c()
{
}

Kvadar::Kvadar(double aa, double bb, double cc, const char* t, bool p) : Akvarijum(t, p), a(aa), b(bb), c(cc)
{
}

Kvadar::Kvadar(const Kvadar& k) : a(k.a), b(k.b), c(k.c), Akvarijum(k)
{
}

Kvadar::~Kvadar()
{
}

void Kvadar::print(ostream& o) const
{
	Akvarijum::print(o);
	o << "Straniac kvadra: "<< a << ", druga stranica:  " << b << ", " << c << endl;
}

double Kvadar::koeficijent() const
{
	return povrsina() / zapremina();
}

double Kvadar::povrsina() const
{
	double rez;
	rez = 2 * (a * b + b * c + a * c);
	if (poklopac == 0)
		rez = rez - a * b;
	return rez;
}

double Kvadar::zapremina() const
{
	return a * b * c;
}
