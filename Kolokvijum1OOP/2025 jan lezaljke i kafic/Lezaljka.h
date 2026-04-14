#pragma once
#include <iostream>
using namespace std;

class Lezaljka {
protected:
	int redniBroj;
	int red;
	int cenaLezaljki;
	int cenaNapica;
public:
	Lezaljka(int rb, int r, int c, int n)
		: redniBroj(rb), red(r), cenaLezaljki(c), cenaNapica(n) {}
	~Lezaljka() {}

	virtual double UkupnaCena() const = 0; //pisi konst!!!!
	virtual void Prikazi() const = 0;

	int getRedniBroj() const { return redniBroj; }
	int getCenaNapica() const { return cenaNapica; }
};