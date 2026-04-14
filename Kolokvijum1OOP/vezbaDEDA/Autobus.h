#pragma once
#include "Putnik.h"
#include <fstream>
using namespace std;
class Autobus
{
protected:
	Putnik** niz;
	int n;
	int tren;
public:
	Autobus();
	Autobus(int n);
	Autobus(const Autobus& a);
	virtual ~Autobus();

	void Dodaj(Putnik* p);
	void Upisi(const char* naziv);

	Putnik* MaxOprema();
	double UkupnaOprema();


	Autobus operator+(const Autobus& a);

	void print(ostream& o) const;
	friend ostream& operator<<(ostream& o, const Autobus& a);

	int BrojPutnika() const { return n; };
};

