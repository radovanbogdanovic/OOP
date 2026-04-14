#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Putnik
{
protected:
	char* ime;
	char* sifra;
public:
	Putnik();
	Putnik(const char* i, const char* s);
	Putnik(const Putnik& p);
	virtual ~Putnik();

	virtual double tezina() const = 0;

	virtual void print(ostream& o) const;
	friend ostream& operator<<(ostream& o, const Putnik& p);

	virtual Putnik* clone() = 0;
	const char* getS() const { return sifra; };
};

