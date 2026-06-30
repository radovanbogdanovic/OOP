#include "KompletKarata.h"

KompletKarata::KompletKarata() : OsnovnaKarta(), popust(0)
{
}

KompletKarata::KompletKarata(const char* ooznaka, char ssektor, int ccena, float ppopust)
	: OsnovnaKarta(ooznaka, ssektor, ccena), popust(ppopust)
{
}

KompletKarata::KompletKarata(const KompletKarata& kk) : OsnovnaKarta(kk), popust(kk.popust)
{
}

KompletKarata::~KompletKarata()
{
}

KompletKarata& KompletKarata::operator=(const KompletKarata& kk)
{
	if (this != &kk)
	{
		OsnovnaKarta::operator=(kk);
		popust = kk.popust;
	}

	return *this;
}

float KompletKarata::UkupnaCena() const
{
	return GetCena() - GetCena() * popust / 100.0f;
}

float KompletKarata::ZaradaZaDan(int dan, const float* ucesceDana) const
{
	if (ucesceDana == nullptr)
		return 0;

	return UkupnaCena() * ucesceDana[dan - 1] / 100.0f;
}

OsnovnaKarta* KompletKarata::clone() const
{
	return new KompletKarata(*this);
}

void KompletKarata::Ispisi(ostream& o) const
{
	o << "Komplet karata -> ";
	IspisiOsnovno(o);
	o << ", popust: " << popust << ", cena sa popustom: " << UkupnaCena();
}
