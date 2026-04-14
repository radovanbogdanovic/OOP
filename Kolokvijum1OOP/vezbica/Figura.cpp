#include "Figura.h"
#include <cstring>

Figura::Figura() : naziv_boje(nullptr)
{
}

Figura::Figura(const char* n)
{
	naziv_boje = new char[strlen(n) + 1];
	strcpy(naziv_boje, n);
}

Figura::Figura(const Figura& f)
{
	naziv_boje = new char[strlen(f.naziv_boje) + 1];
	strcpy(naziv_boje, f.naziv_boje);
}

Figura::~Figura()
{
	if (naziv_boje != 0)
	{
		delete[] naziv_boje;
		naziv_boje = 0;
	}
}

void Figura::print(ostream& o) const
{
	o << naziv_boje << endl;
}

ostream& operator<<(ostream& o, const Figura& f)
{
	
	f.print(o);
	return o;
}
