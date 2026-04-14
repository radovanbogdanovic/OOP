#pragma once
#include "Figura.h"

class Krug : public Figura
{
protected:
	double r;
public:
	Krug();
	Krug(const char* n, double r);
	virtual ~Krug();

	double koeficijent() const override;
	double obim() const override;
	double povrsina() const override;

	Figura* clone() const override;
};

