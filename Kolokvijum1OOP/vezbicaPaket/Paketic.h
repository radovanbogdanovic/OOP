#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Poklon.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Paketic
{
protected:
	Poklon** niz;
	int n;
	int tren;
public:
	Paketic();
	Paketic(int nn);
	Paketic(const Paketic& p);
	virtual ~Paketic();

	int BrojPoklona() const;
	void Add(Poklon* p);
	Poklon* Max() const;
	void RemoveMinimum(Poklon** p);

	void print(ostream& o) const;
	void Save(const char* naziv_fajla) const;

	Paketic operator+(const Paketic& p1) const;

	friend ostream& operator<<(ostream& o, const Paketic& p);
};

