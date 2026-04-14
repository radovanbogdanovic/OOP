#include "Autobus.h"
#include <fstream>

Autobus::Autobus(int m) 
	: maxbroj(m), trenutno(0)
{
	niz = new Putnik * [maxbroj];
	for (int i = 0; i < maxbroj; i++)
		niz[i] = nullptr;
}

Autobus::~Autobus()
{
	for (int i = 0; i < maxbroj; i++)
		if (niz[i] != nullptr)
			delete niz[i];
	delete[] niz;
}

Autobus::Autobus(const Autobus& a)
{
	this->maxbroj = a.maxbroj;
	this->trenutno = a.trenutno;
	niz = new Putnik * [maxbroj];
	for (int i = 0; i < maxbroj; i++)
		if (a.niz[i] != nullptr)
			niz[i] = a.niz[i]->Kopija();
		else
			niz[i] = nullptr;
}

Autobus& Autobus::operator=(const Autobus& a)
{
	if (this != &a)
	{
		for (int i = 0; i < maxbroj; i++)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;

		maxbroj = a.maxbroj;
		trenutno = a.trenutno;

		niz = new Putnik * [maxbroj];

		for (int i = 0; i < maxbroj; i++)
			if (a.niz[i] != nullptr)
				niz[i] = a.niz[i]->Kopija();
			else
				niz[i] = nullptr;
	}
	return *this;
	// TODO: insert return statement here
}

void Autobus::Dodaj(Putnik* p)
{
	bool postoji = 0; // pretpostavimo da postoji putnik
	for (int i = 0; i < maxbroj; i++)
		if (niz[i] != nullptr && strcmp(niz[i]->GetSediste(), p->GetSediste()) == 0)
		{
			postoji = 1; //ipak ne postoji putnik
			break;
		}
	if (!postoji && trenutno < maxbroj)
		niz[trenutno++] = p;
}

Putnik* Autobus::MaxOprema()
{
	Putnik* rez = niz[0]; //poziv kopi konst.
	float maxmasa = niz[0]->GetMasa();
	for (int i = 0; i < trenutno; i++)
		if (niz[i] != nullptr && niz[i]->GetMasa() > maxmasa)
		{
			maxmasa = niz[i]->GetMasa();
			rez = niz[i];
		}
	return rez;
}

float Autobus::UkupnaOprema() const
{
	float suma = 0.0;
	for (int i = 0; i < trenutno; i++)
		if (niz[i] != nullptr)
			suma += niz[i]->GetMasa();
	return suma;
}

Autobus Autobus::operator+(const Autobus& a) const
{
	Autobus novi(this->maxbroj + a.maxbroj);
	for (int i = 0; i < this->trenutno; i++)
		//if (this->niz[i] != nullptr)
			novi.Dodaj(niz[i]->Kopija());
	for (int i = 0; i < a.trenutno; i++)
		//if (a.niz[i] != nullptr)
			novi.Dodaj(a.niz[i]->Kopija());
	return novi;
}

void Autobus::Upisi(const char* imeFajla) const
{
	ofstream izlaz(imeFajla); 
	if (!izlaz) { cout << "neuspesno otvaranje fajla" << endl; return; }

	izlaz << "AUTOBUS: max broj: " << maxbroj
		<< ", trenutn: " << trenutno << endl;
	for (int i = 0; i < trenutno; i++)
		if (niz[i] != nullptr)
			izlaz << "		" << *niz[i] << "\n";
	izlaz.close();
}

ostream& operator<<(ostream& os, const Autobus& a)
{
	os << "AUTOBUS: max putnika: " << a.maxbroj
		<< ", trenutno: " << a.trenutno << endl;
	for (int i = 0; i < a.maxbroj; i++)
		if (a.niz[i] != nullptr)
			os << "		" << *a.niz[i] << "\n";
	return os;
}
