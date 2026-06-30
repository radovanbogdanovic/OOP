#pragma once
#include "OsnovnaKarta.h"

class KompletKarata : public OsnovnaKarta
{
private:
	float popust;

public:
	KompletKarata();
	KompletKarata(const char* ooznaka, char ssektor, int ccena, float ppopust);
	KompletKarata(const KompletKarata& kk);
	~KompletKarata();

	KompletKarata& operator=(const KompletKarata& kk);

	float GetPopust() const { return popust; }

	float UkupnaCena() const;
	float ZaradaZaDan(int dan, const float* ucesceDana) const;
	OsnovnaKarta* clone() const;
	void Ispisi(ostream& o) const;
};
