#pragma once
#include "IspitniMaterijal.h"

class Zadatak : public IspitniMaterijal {
	int br_linija;
public:
	Zadatak(int o, float t, int b);

	float Vreme() const { return (float)br_linija * tezina * 0.05; }
	const char* GetNaziv() { return "Zadatak"; }

	void print(ostream& os) const;
};
