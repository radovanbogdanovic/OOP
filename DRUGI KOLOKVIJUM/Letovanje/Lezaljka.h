#pragma once
#include <iostream>
using namespace std;
class Lezaljka
{
private:
	int broj, cena;

public:
	Lezaljka();
	Lezaljka(int b, int c);
	virtual ~Lezaljka();


	Lezaljka& operator=(const Lezaljka& le);

	friend float operator+(float s, const Lezaljka& le) { return s + (float)le.cena; }
	friend int operator+(int s, const Lezaljka& le) { return s + le.broj; }
	bool operator==(int b) const { return broj == b; }
	bool operator==(const Lezaljka& le) const { return broj == le.broj; }

	friend ostream& operator<<(ostream& o, const Lezaljka& le);
	friend istream& operator>>(istream& i, Lezaljka& le);
};

