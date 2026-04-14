#pragma once
#include "Putnik.h"

class Sankanje : public Putnik {
	int zapremina;
	float gustina;
public:
	Sankanje(const char* i, const char* s, int z, float g);
	~Sankanje() {};
	Sankanje(const Sankanje& s);
	Putnik* Kopija() const override;

	float GetMasa() const override { return gustina * (float)zapremina; }

	void print(ostream& os) const;
};
