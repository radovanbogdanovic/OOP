#pragma once
#include <iostream>
using namespace std;

class PaletaProsirena
{
private:
	float masa, broj, sirina;
public:

	PaletaProsirena();
	PaletaProsirena(float m, float b, float s);
	virtual ~PaletaProsirena();

	PaletaProsirena& operator=(const PaletaProsirena& pa);

	PaletaProsirena operator-(int s) const {
		float novaMasaPalete = (masa * broj) - s;
		return PaletaProsirena(masa, novaMasaPalete / masa, sirina);
	}

	bool operator>=(int s) const { return MasaPalete() >= s; }
	bool operator>(int s) const { return MasaPalete() > s; }
	bool operator>(const PaletaProsirena& pa) const { return MasaPalete() > pa.MasaPalete(); }
	//bool operator<(const PaletaProsirena& pa) const { return MasaPalete() < pa.MasaPalete(); }
	bool operator==(int s) const { return MasaPalete() == s; }

	
	friend float operator+(float s, const PaletaProsirena& pa) { return s + pa.MasaPalete(); }

	// Konverzija u float da bi "rez = rez + niz[i]" u Skladistu radilo lakse
	//operator float() const { return MasaPalete(); }

	float MasaPalete() const { return masa * broj; }
	//int BR() const { return (int)broj; } // Vratili smo broj dasaka, ne masu daske

	friend ostream& operator<<(ostream& o, const PaletaProsirena& pa);
	friend istream& operator>>(istream& i, PaletaProsirena& pa);
};