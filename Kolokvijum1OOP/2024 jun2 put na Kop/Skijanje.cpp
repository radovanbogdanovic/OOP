#include "Skijanje.h"

Skijanje::Skijanje(const char* i, const char* s, int d, int m, int p)
	: Putnik(i, s), duzina(d), masa(m), pancericem(p) {
}

Skijanje::Skijanje(const Skijanje& s) : Putnik(s)
{
	this->duzina = s.duzina;
	this->masa = s.masa;
	this->pancericem = s.pancericem;
}

Putnik* Skijanje::Kopija() const
{
	return new Skijanje(*this);
}

void Skijanje::print(ostream& os) const
{
	os << "PUTNIK-SKIJE:";
	Putnik::print(os);
	os << ", duzina: " << duzina
		<< ", masa: " << masa << "g"
		<< ", pancerice: " << pancericem << "g" << endl;
}