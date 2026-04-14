#pragma once
#include <iostream>
#include "IspitniMaterijal.h"
using namespace std;

class IspitPriprema {
	int maxbroj;
	int trenutno;
	IspitniMaterijal** niz;
public:
	IspitPriprema(int m);
	~IspitPriprema();

	void Dodaj(IspitniMaterijal* i);
	void Obrisi(int o);
	void Savladaj(int o);
	int UkupnoSavladanih();
	float UkupnoVreme(float vreme);
	void VratiNaj(float vreme, IspitniMaterijal** min, IspitniMaterijal** max);

	friend ostream& operator<<(ostream& os, const IspitPriprema& p);
};