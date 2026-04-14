#include "ProsireniPodatak.h"

ProsireniPodatak::ProsireniPodatak() : t(0), e(0), v(0)
{
}

ProsireniPodatak::ProsireniPodatak(float ff, float ee, float vv): t(ff), e(ee), v(vv)
{
}

ProsireniPodatak::~ProsireniPodatak()
{
}

ProsireniPodatak& ProsireniPodatak::operator=(const ProsireniPodatak& pp)
{
	if (this != &pp)
	{
		t = pp.t;
		e = pp.e;
		v = pp.v;
	}

	return *this;
}

bool ProsireniPodatak::operator<(const ProsireniPodatak& pp) const
{

	float ts = t + 0.33 * e - 0.7 * v - 4.0;
	float ts2 = pp.t + 0.33 * pp.e - 0.7 * pp.v - 4.0;

	return ts < ts2;
}

float operator+(float rez, const ProsireniPodatak& pp)
{
	return pp.t + rez;
}

ostream& operator<<(ostream& o, const ProsireniPodatak& pp)
{
	
	o << pp.t << " " << pp.e << " " << pp.v;
	
	return o;
}

istream& operator>>(istream& i, ProsireniPodatak& pp)
{
	i >> pp.t >> pp.e >> pp.v;
	
	return i;
}
