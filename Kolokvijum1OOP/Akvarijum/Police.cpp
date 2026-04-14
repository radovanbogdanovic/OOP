#include "Police.h"
#include <cstring>

Polica::Polica() : niz(nullptr), n(), tren()
{
}

Polica::Polica(int nn): n(nn), tren(0)
{
	niz = new Akvarijum * [nn] {};
}

Polica::~Polica()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < tren; i++)
		{
			delete niz[i];
			niz[i] = nullptr;
		}
		delete[] niz;
		niz = nullptr;
	}
}

void Polica::print(ostream& o) const
{
	o << "ODAVDE KRECE POLICA" << endl;
	o << "Kapacitet police je " << n << " akvarijuma, a trenutno je zauzeto " << tren << endl;
	for (int i = 0; i < tren; i++)
		o << *niz[i] << "\n";
}

void Polica::Add(Akvarijum* a)
{
	if (tren == n)
		delete a;
	else
	{
		niz[tren] = a;
		tren++;
	}
}

double Polica::UkupnaPovrsinaStakla() const
{
	double rez = 0;
	for (int i = 0; i < tren; i++)
		rez += niz[i]->povrsina();
	return rez;
}

double Polica::UkupnaZapremina() const
{
	double rez=0;
	for (int i = 0; i < tren; i++)
		rez += niz[i]->zapremina();
	return rez;
}

Polica* Polica::PrebacitiAkvarijume(const char* tipvode)
{
	Polica* rez = new Polica(this->n);
	int i = 0;
	while (i < tren)
	{
		if (strcmp(niz[i]->getTip(), tipvode) == 0)
		{
			rez->Add(niz[i]);

			for (int j = i; j < tren - 1; j++)
				niz[j] = niz[j + 1];
			niz[tren - 1] = nullptr;
			tren--;
		}
		else i++;
	}
	return rez;
}

void Polica::Min(int* ind, Akvarijum** el)
{
	int indeks = 0;
	Akvarijum* taj = niz[0];

	for (int i = 0; i < tren; i++)
		if (niz[i]->koeficijent() < taj->koeficijent())
		{
			indeks = i;
			taj = niz[i];
		}

	*ind = indeks;
	*el = taj;
}

ostream& operator<<(ostream& o, const Polica& p)
{
	p.print(o);
	return o;
}
