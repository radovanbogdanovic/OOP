#pragma once
#include "Figura.h"

class Pravougaonik : public Figura
{
protected: 
	double a, b;
public:
	Pravougaonik();
	Pravougaonik(const char* n, double a, double b);
	~Pravougaonik();

	double koeficijent() const override;
	double obim() const override;
	double povrsina() const override;

	Figura* clone() const override;
};

