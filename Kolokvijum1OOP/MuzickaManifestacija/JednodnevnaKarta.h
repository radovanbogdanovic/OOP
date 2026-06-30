#pragma once
#include "OsnovnaKarta.h"

class JednodnevnaKarta : public OsnovnaKarta
{
private:
	int redniBrojDana;

public:
	JednodnevnaKarta();
	JednodnevnaKarta(const char* ooznaka, char ssektor, int ccena, int rredniBrojDana);
	JednodnevnaKarta(const JednodnevnaKarta& jk);
	~JednodnevnaKarta();

	JednodnevnaKarta& operator=(const JednodnevnaKarta& jk);

	int GetRedniBrojDana() const { return redniBrojDana; }

	float ZaradaZaDan(int dan, const float* ucesceDana) const;
	OsnovnaKarta* clone() const;
	void Ispisi(ostream& o) const;
};
