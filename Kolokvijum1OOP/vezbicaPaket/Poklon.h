#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Poklon
{
protected:
	double cena;
	int br_masinca;
public:
	Poklon();
	Poklon(double c, int br);
	Poklon(const Poklon& p);
	virtual ~Poklon();

	virtual int BrojMasnica() const;
	virtual void print(ostream& o) const;
	friend ostream& operator<<(ostream& o, const Poklon& p);

	virtual Poklon* clone() = 0;

};

