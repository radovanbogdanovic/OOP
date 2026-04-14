#pragma once
#include <iostream>
#include "Akvarijum.h"
using namespace std;

class Valjak: public Akvarijum
{
protected:
	double r;
	double h;
public:
	Valjak();
	Valjak(double r, double h, const char* tip_vode, bool poklopac);
	Valjak(const Valjak& v);
	virtual ~Valjak();

	void print(ostream& o) const override;
	double koeficijent() const override;
	
	double povrsina() const override;
	double zapremina() const override;

};

