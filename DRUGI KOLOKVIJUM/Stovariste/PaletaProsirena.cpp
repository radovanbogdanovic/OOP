#include "PaletaProsirena.h"

PaletaProsirena::PaletaProsirena() : masa(), broj(), sirina()
{
}

PaletaProsirena::PaletaProsirena(float m, float b, float s) : masa(m), broj(b), sirina(s)
{
}

PaletaProsirena::~PaletaProsirena()
{
}

PaletaProsirena& PaletaProsirena::operator=(const PaletaProsirena& pa)
{
	masa = pa.masa;
	broj = pa.broj; sirina = pa.sirina;
	
	return *this;
}

ostream& operator<<(ostream& o, const PaletaProsirena& pa)
{
	o << pa.masa << " " << pa.broj << " " << pa.sirina;
	return o;
}

istream& operator>>(istream& i, PaletaProsirena& pa)
{
	i >> pa.masa >> pa.broj >> pa.sirina;
	return i;
}
