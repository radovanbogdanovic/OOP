#include "IspitPriprema.h"

IspitPriprema::IspitPriprema(int m) 
	: maxbroj(m), trenutno(0)
{
	niz = new IspitniMaterijal * [maxbroj];
	for (int i = 0; i < maxbroj; i++)
		niz[i] = nullptr;
}

IspitPriprema::~IspitPriprema()
{
	for (int i = 0; i < maxbroj; i++)
		if (niz[i] != nullptr)
			delete niz[i];
	delete[] niz;
}

void IspitPriprema::Dodaj(IspitniMaterijal* i)
{
	if (maxbroj > trenutno)
		niz[trenutno++] = i;
}

void IspitPriprema::Obrisi(int o)
{
	for (int i = 0; i < trenutno; i++)
		if (niz[i]->GetOznaka() == o)
		{
			niz[i] = nullptr;
			trenutno--;
		}
}

void IspitPriprema::Savladaj(int o)
{
	for (int i = 0; i < maxbroj; i++)
		if (niz[i] != nullptr && niz[i]->GetOznaka() == o)
		{
			niz[i]->Savladano();
		}
}

int IspitPriprema::UkupnoSavladanih()
{
	int ukupno = 0;
	for (int i = 0; i < maxbroj; i++)
		if (niz[i] != nullptr && niz[i]->GetSavladan())
			ukupno++;
	return ukupno;
}

float IspitPriprema::UkupnoVreme(float vreme)
{
	float ukupnoVreme = 0.0;
	for (int i=0;i<maxbroj;i++)
		if (niz[i] != nullptr)
		{
			ukupnoVreme += niz[i]->Vreme() * vreme;
		}
	return ukupnoVreme;
}

void IspitPriprema::VratiNaj(float vreme, IspitniMaterijal** min, IspitniMaterijal** max)
{
	float pretpostavljenomin = niz[0]->Vreme() * vreme; //pp da je prvi i najmanji i najveci
	float pretpostavljenomax = niz[0]->Vreme() * vreme;
	*min = niz[0];
	*max = niz[0];
	for (int i =0;i<maxbroj;i++)
		if (niz[i] != nullptr)
		{
			if (niz[i]->Vreme() * vreme > pretpostavljenomax)
			{
				pretpostavljenomax = niz[i]->Vreme() * vreme;
				*max = niz[i];
			}
			else if (niz[i]->Vreme() * vreme > pretpostavljenomin)
			{
				pretpostavljenomin = niz[i]->Vreme() * vreme;
				*min = niz[i];
			}
		}
}

ostream& operator<<(ostream& os, const IspitPriprema& p)
{
	os << "PRIPREMA ISPITA: maks broj: " << p.maxbroj
		<< ", trenutno: " << p.trenutno << endl;
	for (int i = 0; i < p.maxbroj; i++)
		if (p.niz[i] != nullptr)
			os << "    " << *p.niz[i];
	return os;
}
