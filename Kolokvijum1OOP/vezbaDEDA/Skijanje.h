#pragma once
#include "Putnik.h"
class Skijanje : public Putnik
{
protected:
	double duzina;
	double masa_sk;
	double masa_pan;
public:
	Skijanje();
	Skijanje(const char* i, const char* s, double d, double m, double mp);
	virtual ~Skijanje();

	double tezina() const override;

	void print(ostream& o) const override;

	Putnik* clone() override;
};

