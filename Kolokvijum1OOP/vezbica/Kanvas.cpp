#include "Kanvas.h"

Kanvas::Kanvas() : niz(nullptr), n(), tren()
{
}

Kanvas::Kanvas(int nn): n(nn), tren(0)
{
	niz = new Figura * [nn] {};
}

Kanvas::Kanvas(const Kanvas& k) : n(k.n), tren(k.tren)
{
	niz = new Figura * [k.n] {};
	for (int i = 0; i < k.tren; i++)
		niz[i] = k.niz[i]->clone();
}

Kanvas::~Kanvas()
{
	for (int i = 0; i < tren; i++)
	{
		if (niz[i] != nullptr)
		{
			delete niz[i];
			niz[i] = nullptr;
		}
	}
	if (niz != nullptr)
	{
		delete[] niz;
		niz = nullptr;
	}
	

}

void Kanvas::Add(Figura* f)
{
	if (tren == n)
		delete f;
	niz[tren] = f;
	tren++;
}

void Kanvas::print(ostream& o) const
{
	for (int i = 0; i < tren; i++)
		o << *niz[i] << endl;
}

double Kanvas::UkupnaPovrsina() const
{
	double rez = 0;
	for (int i = 0; i < tren; i++)
		rez += niz[i]->povrsina();
	return rez;
}

double Kanvas::UkupanObim() const
{
	double rez = 0;
	for (int i = 0; i < tren; i++)
		rez += niz[i]->obim();
	return rez;
}

Kanvas* Kanvas::PrebaciPoBoji(const char* nazivboje)
{
	Kanvas* rez = new Kanvas(n);

	for (int i = 0; i < tren; i++)
	{
		if (strcmp(niz[i]->getBoja(), nazivboje) == 0)
			rez->Add(niz[i]);

		for (int j = i; j < tren - 1; j++)
			niz[j] = niz[j + 1];
		niz[tren - 1] = nullptr;
		tren--;
	}

	return rez;
}

void Kanvas::Max(Figura** el, int* indeks)
{
	int ind = 0;
	Figura* f = niz[0];

	for (int i = 0; i < tren; i++)
	{
		if (niz[i]->koeficijent() > f->koeficijent())
		{
			ind = i;
			f = niz[i];
		}
	}
	*indeks = ind;
	*el = f;
}
