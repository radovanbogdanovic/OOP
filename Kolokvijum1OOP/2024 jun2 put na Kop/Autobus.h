#pragma once
#include <iostream>
#include "Putnik.h"
using namespace std;

class Autobus {
	int maxbroj;
	int trenutno;
	Putnik** niz;
public:
	Autobus(int m);
	~Autobus();
	Autobus(const Autobus& a);
	Autobus& operator=(const Autobus& a);

	void Dodaj(Putnik* p);
	int BrojPutnika() const { return maxbroj; }
	Putnik* MaxOprema();
	float UkupnaOprema() const;

	Autobus operator+(const Autobus& a) const;
	
	void Upisi(const char* imeFajla) const;
	friend ostream& operator<<(ostream& os, const Autobus& a);
};