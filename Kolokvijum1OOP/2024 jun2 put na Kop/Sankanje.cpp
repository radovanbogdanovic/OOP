#include "Sankanje.h"

Sankanje::Sankanje(const char* i, const char* s, int z, float g)
	: Putnik(i, s), zapremina(z), gustina(g) {}

Sankanje::Sankanje(const Sankanje& s) : Putnik(s)
{
	this->gustina = s.gustina;
	this->zapremina = s.zapremina;

}

Putnik* Sankanje::Kopija() const
{
	return new Sankanje(*this);
}

void Sankanje::print(ostream& os) const
{
	os << "PUTNIK-SANKE:";
	Putnik::print(os);
	os << ", zapremina: " << zapremina
		<< ", gustina: " << gustina << endl;
}
