#pragma once
#include "Poklon.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstring>

class Igracka : public Poklon
{
protected:
	char* materijal;
public:
	Igracka();
	Igracka(double c, int br, const char* m);
	Igracka(const Igracka& i);
	virtual ~Igracka();


	virtual int BrojMasnica() const;
	virtual void print(ostream& o) const;

	Poklon* clone() override;
};

