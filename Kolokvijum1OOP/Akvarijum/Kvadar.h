#pragma once
#include "Akvarijum.h"
#include <iostream>
using namespace std;

class Kvadar: public Akvarijum
{
protected:
	double a, b, c;
public:
	Kvadar();
	Kvadar(double, double, double, const char*, bool);
	Kvadar(const Kvadar& k);
	virtual ~Kvadar();

	void print(ostream& o) const override;
	double koeficijent() const override;
	double povrsina() const override;
	double zapremina() const override;


};

