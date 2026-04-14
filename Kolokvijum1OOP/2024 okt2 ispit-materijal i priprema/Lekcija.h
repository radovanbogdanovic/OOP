#pragma once
#include "IspitniMaterijal.h"

class Lekcija : public IspitniMaterijal {
	float stranice;
public:
	Lekcija(int o, float t, float s);

	float Vreme() const { return stranice * tezina; }
	const char* GetNaziv() { return "Lekcija"; }

	void print(ostream& os) const;
};
