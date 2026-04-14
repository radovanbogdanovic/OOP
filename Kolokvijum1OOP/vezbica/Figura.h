#pragma once
#include <iostream>
using namespace std;

class Figura
{
protected:
	char* naziv_boje;
public:
	Figura();
	Figura(const char*);
	Figura(const Figura& f);
	virtual ~Figura();

	virtual double koeficijent() const = 0;
	virtual double obim() const = 0;
	virtual double povrsina() const = 0;

	virtual Figura* clone() const = 0;

	virtual void print(ostream& o) const;

	friend ostream& operator<<(ostream& o, const Figura& f);

	char* getBoja() const { return naziv_boje; };
};

