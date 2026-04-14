#pragma once
#include "Putnik.h"
class Sankanje : public Putnik
{
protected:
	double zapremina;
	double gustina;
public:
	Sankanje();
	Sankanje(const char* i, const char* s, double z, double g);
	virtual ~Sankanje();

	double tezina() const override;

	void print(ostream& o) const override;

	Putnik* clone() override;
};

