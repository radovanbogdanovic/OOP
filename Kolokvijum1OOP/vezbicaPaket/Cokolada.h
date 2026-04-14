#pragma once
#include "Poklon.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Cokolada : public Poklon
{
protected:
	float kakao;
public:
	Cokolada();
	Cokolada(double c, int br, float k);
	Cokolada(const Cokolada& c);
	virtual ~Cokolada();

	void print(ostream& o) const;
	virtual int BrojMasnica() const;

	Poklon* clone();
};

