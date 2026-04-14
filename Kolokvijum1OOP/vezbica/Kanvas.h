#pragma once
#include "Figura.h"
#include <cstring>
#include <iostream>
using namespace std;

class Kanvas
{
protected:
	Figura** niz;
	int n;
	int tren;
public:
	Kanvas();
	Kanvas(int nn);
	Kanvas(const Kanvas& k);
	virtual ~Kanvas();

	void Add(Figura* f);
	void print(ostream& o) const;
	double UkupnaPovrsina() const;
	double UkupanObim() const;

	Kanvas* PrebaciPoBoji(const char* nazivboje);
	void Max(Figura** el, int* indeks);


};

