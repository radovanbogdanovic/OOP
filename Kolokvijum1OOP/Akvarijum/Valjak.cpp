#include "Valjak.h"
#include <cstring>
using namespace std;

Valjak::Valjak() : Akvarijum(), r(), h()
{
}

Valjak::Valjak(double rr, double hh, const char* tip, bool p): r(rr), h(hh), Akvarijum(tip, p)
{
}

Valjak::Valjak(const Valjak& v) : Akvarijum(v), r(v.r), h(v.h)
{
}

Valjak::~Valjak()
{
}

void Valjak::print(ostream& o) const
{
	Akvarijum::print(o);
	o << "Polupreènik valjka je: " << r << ", a njegova visina je: " << h << endl;
}

double Valjak::koeficijent() const
{
	return povrsina() / zapremina();
}

double Valjak::povrsina() const
{
	double rez;
	rez = 2 * r * r * 3.14 + 2 * r * 3.14 * h;
	if (poklopac == 0)
		rez = rez - r * r * 3.14;
	return rez;
}

double Valjak::zapremina() const
{
	double rez;
	rez = r * r * 3.14 * h;
	return rez;
}

