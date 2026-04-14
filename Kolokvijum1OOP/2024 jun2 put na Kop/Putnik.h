#pragma once
#include <iostream>
using namespace std;

class Putnik {
protected:
	char* ime;
	char* sediste;
public:
	Putnik(const char* i, const char* s);
	virtual ~Putnik();
	Putnik(const Putnik& p);
	virtual Putnik* Kopija() const;

	const char* GetSediste() const{ return sediste; }
	virtual float GetMasa() const { return 1; }

	virtual void print(ostream& os) const;
	friend ostream& operator<<(ostream& os, Putnik& p);
};
