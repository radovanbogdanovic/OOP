#include "JednodnevnaKarta.h"

JednodnevnaKarta::JednodnevnaKarta() : OsnovnaKarta(), redniBrojDana(0)
{
}

JednodnevnaKarta::JednodnevnaKarta(const char* ooznaka, char ssektor, int ccena, int rredniBrojDana)
	: OsnovnaKarta(ooznaka, ssektor, ccena), redniBrojDana(rredniBrojDana)
{
}

JednodnevnaKarta::JednodnevnaKarta(const JednodnevnaKarta& jk) : OsnovnaKarta(jk), redniBrojDana(jk.redniBrojDana)
{
}

JednodnevnaKarta::~JednodnevnaKarta()
{
}

JednodnevnaKarta& JednodnevnaKarta::operator=(const JednodnevnaKarta& jk)
{
	if (this != &jk)
	{
		OsnovnaKarta::operator=(jk);
		redniBrojDana = jk.redniBrojDana;
	}

	return *this;
}

float JednodnevnaKarta::ZaradaZaDan(int dan, const float*) const
{
	if (dan == redniBrojDana)
		return UkupnaCena();

	return 0;
}

OsnovnaKarta* JednodnevnaKarta::clone() const
{
	return new JednodnevnaKarta(*this);
}

void JednodnevnaKarta::Ispisi(ostream& o) const
{
	o << "Jednodnevna karta -> ";
	IspisiOsnovno(o);
	o << ", dan: " << redniBrojDana;
}
