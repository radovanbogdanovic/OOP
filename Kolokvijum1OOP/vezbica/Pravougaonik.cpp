#include "Pravougaonik.h"

Pravougaonik::Pravougaonik() : Figura(), a(), b()
{
}

Pravougaonik::Pravougaonik(const char* n, double aa, double bb): Figura(n), a(aa), b(bb)
{
}

Pravougaonik::~Pravougaonik()
{
}

double Pravougaonik::koeficijent() const
{
	return povrsina() / obim() ;
}

double Pravougaonik::obim() const
{
	return a + a + b + b;
}

double Pravougaonik::povrsina() const
{
	return a*b;
}

Figura* Pravougaonik::clone() const
{
	return new Pravougaonik(*this);
}

