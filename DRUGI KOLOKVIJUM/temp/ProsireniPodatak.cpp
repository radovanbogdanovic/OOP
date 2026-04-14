#include "ProsireniPodatak.h"

ProsireniPodatak::ProsireniPodatak() : temp(), vlaz(), brzina()
{
}

ProsireniPodatak::ProsireniPodatak(float t, float v, float b) : temp(t), vlaz(v), brzina(b)
{
}

ProsireniPodatak::~ProsireniPodatak()
{
}

ProsireniPodatak& ProsireniPodatak::operator=(const ProsireniPodatak& pp)
{
	temp = pp.temp;
	vlaz = pp.vlaz;
	brzina = pp.brzina;

	return *this;
}

ostream& operator<<(ostream& o, const ProsireniPodatak& pp)
{
	o << pp.temp << " " << pp.vlaz << " " << pp.brzina;

	return o;
}

istream& operator>>(istream& i, ProsireniPodatak& pp)
{
	i >> pp.temp >> pp.vlaz >> pp.brzina;
	return i;
}
