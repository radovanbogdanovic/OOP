#include "Paketic.h"

Paketic::Paketic() : niz(nullptr), n(), tren()
{
}

Paketic::Paketic(int nn) : n(nn), tren()
{
	niz = new Poklon * [nn] {};
}

Paketic::Paketic(const Paketic& p) : n(p.n), tren(p.tren)
{

	niz = new Poklon * [p.n];
	for (int i = 0; i < p.tren; i++)
	{
		niz[i] = p.niz[i]->clone();

	}
}

Paketic::~Paketic()
{
	for (int i = 0; i < tren; i++)
	{
		if (niz[i] != 0)
		{
			delete niz[i];
			niz[i] = 0;
		}
	}

	if (niz != 0)
	{
		delete[] niz;
		niz = 0;
	}
}

int Paketic::BrojPoklona() const
{
	return n;
}

void Paketic::Add(Poklon* p)
{
	if (tren == n)
		delete p;
	niz[tren] = p;
	tren++;
}

void Paketic::print(ostream& o) const
{
	for (int i = 0; i < tren; i++)
	{
		if (niz[i] != nullptr)
			o << *niz[i] << ", " << endl;
		else
			o << "PRAZNO" << endl;
	}
}

Paketic Paketic::operator+(const Paketic& p) const
{
	Paketic rez(n + p.n);

	for (int i = 0; i < tren; i++)
		rez.Add( niz[i]->clone());

	for (int i = 0; i < p.tren; i++)
		rez.Add( p.niz[i]->clone());

	return rez;
}


Poklon* Paketic::Max() const
{
	int indeks = 0;
	int brr = 0;

	if (tren == 0)
		return nullptr;

	for(int i=0; i<tren; i++)
		if (brr < niz[i]->BrojMasnica())
		{
			indeks = i;
			brr = niz[i]->BrojMasnica();
		}

	return niz[indeks];
}

void Paketic::RemoveMinimum(Poklon** p)
{
	if (tren == 0)
		return ;
	
	int indeks = 0;
	int min = 9999;

	for(int i=0; i<tren; i++)
		if (niz[i]->BrojMasnica() < min)
		{
			indeks = i;
			min = niz[i]->BrojMasnica();
		}
	*p = niz[indeks];

	for (int i = indeks; i < tren-1; i++)
		niz[i] = niz[i + 1];
	niz[tren - 1] = nullptr;
	tren--;

	//if (tren == 0)
	//	return;
	//int min = 0;
	//for (int i = 1; i < tren; i++)
	//{
	//	if (niz[min]->BrojMasnica() > niz[i]->BrojMasnica())
	//		min = i;
	//}
	//*p = niz[min];
}

void Paketic::Save(const char* naziv_fajla) const
{
	ofstream out(naziv_fajla);
	if (!out.good())
		return;
	out << *this << "\n";
	out.close();
}

ostream& operator<<(ostream& o, const Paketic& p)
{
	p.print(o);
	return o;
}