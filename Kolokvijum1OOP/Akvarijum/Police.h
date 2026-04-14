#pragma once
#include "Akvarijum.h"
#include <ostream>
using namespace std;

class Polica
{
protected:
	Akvarijum** niz;
	int n;
	int tren;

public:
	Polica();
	Polica(int n);
	virtual ~Polica();

	void print(ostream& o) const;
	void Add(Akvarijum* a);
	double UkupnaPovrsinaStakla() const;
	double UkupnaZapremina() const;
	int BrojAkvarijuma() const { return n; };

	Polica* PrebacitiAkvarijume(const char* tipvode);
	void Min(int* ind, Akvarijum** el);

	friend ostream& operator<<(ostream& o, const Polica& p);

};