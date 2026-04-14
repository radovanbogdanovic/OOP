#include "Krug.h"

Krug::Krug() : Figura(), r()
{
}

Krug::Krug(const char* naziv, double rr) : Figura(naziv), r(rr)
{
}

Krug::~Krug()
{
}

double Krug::koeficijent() const
{
	return povrsina() / obim();
}

double Krug::obim() const
{
	return 2 * r * 3.14;
}

double Krug::povrsina() const
{
	return r * r * 3.14;
}

Figura* Krug::clone() const
{
	return new Krug(*this);
}
