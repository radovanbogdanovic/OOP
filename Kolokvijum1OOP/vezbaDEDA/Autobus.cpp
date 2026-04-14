#define _STR_SECURE_NO_WARNINGS
#include "Autobus.h"

Autobus::Autobus() : niz(nullptr), n(), tren()
{
}

Autobus::Autobus(int n)
{
	niz = new Putnik * [n] {};
}

Autobus::Autobus(const Autobus& a) : n(a.n), tren(a.tren)
{
	niz = new Putnik * [n] {};
	for (int i =0 ; i < a.tren ; i++)
	{
		niz[i] = a.niz[i]->clone();
	}
}

Autobus::~Autobus()
{
	if (niz != 0)
	{
		for (int i = 0; i < tren; i++)
		{
			delete niz[i];
			niz[i] = 0;
		}

		delete[] niz; niz = 0;
	}
}

void Autobus::Dodaj(Putnik* p)
{
	bool k = 1;
	for (int i = 0; i < tren; i++)
		if (strcmp(niz[i]->getS(),p->getS()) == 0)
			k = 0;

	if (k && tren < n)
	{
		niz[tren++] = p;
	}
	else
		delete p;

}

void Autobus::Upisi(const char* naziv)
{
	ofstream izlaz(naziv);
	if (izlaz.good())
	{
		izlaz << *this << endl;
	}
	izlaz.close();
}

Putnik* Autobus::MaxOprema()
{
	int ind = 0;
	double max = 0;

	for (int i = 0; i < tren; i++)
	{
		if (niz[i]->tezina() > max)
		{
			max = niz[i]->tezina();
			ind = i;
		}
	}
	Putnik* najjaci = niz[ind];
	for (int i = ind; i < tren - 1; i++) {
		niz[i] = niz[i + 1];
	}
	niz[tren - 1] = nullptr;
	tren--;

	return najjaci;
}

double Autobus::UkupnaOprema()
{
	double rez = 0;
	for (int i = 0; i < tren; i++)
		rez += niz[i]->tezina();
	return rez;
}

Autobus Autobus::operator+(const Autobus& a)
{

	Autobus a3(n + a.n);
	for (int i = 0; i < tren; i++)
		a3.Dodaj(niz[i]->clone());

	for (int i = 0; i < a.tren; i++)
		a3.Dodaj(a.niz[i]->clone());
	return a3;
}

void Autobus::print(ostream& o) const
{
	for (int i = 0; i < tren ; i++)
		o << *niz[i] << endl;
}

ostream& operator<<(ostream& o, const Autobus& a)
{
	a.print(o);
	return o;
}
