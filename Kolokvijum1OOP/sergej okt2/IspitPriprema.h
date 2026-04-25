#pragma once
#include "IspitniMaterijal.h"

class IspitPriprema
{
private:
	IspitniMaterijal** kolekcija;
	int zauzeto;
	int n;
public:
	IspitPriprema();
	IspitPriprema(int _n);
	~IspitPriprema();

	void ZauzmiMemoriju(int x);
	
	void Dodaj(IspitniMaterijal * drugi);

	void Obrisi(int k);

	friend ostream& operator<<(ostream& os, IspitPriprema& i);

	void Savladaj(int y);

	int UkupnoSavladanih();

	double UkupnoVreme(int V);

	void VratiNaj(int v, IspitniMaterijal** min, IspitniMaterijal** max);
};

