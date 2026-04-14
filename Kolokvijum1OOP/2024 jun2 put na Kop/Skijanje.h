#pragma once
#include "Putnik.h"

class Skijanje : public Putnik {
	int duzina;
	int masa;
	int pancericem;
public:
	Skijanje(const char* i, const char* s, int d, int m, int p);
	~Skijanje() {};
	Skijanje(const Skijanje& s);
	Putnik* Kopija() const override;

	float GetMasa() const override { return (float)masa + (float)pancericem; }

	void print(ostream& os) const;
};
