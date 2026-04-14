#pragma once 
#include "Lezaljka.h"

class ParLezaljkiSaDodatkom : public Lezaljka {
private:
	int dodatneLezaljke;
public:
	ParLezaljkiSaDodatkom (int rb, int r, int c, int n, int dl)
	: Lezaljka(rb, r, c, n), dodatneLezaljke(dl) {}
	
	double UkupnaCena() const override {
		double popust = 40 - 2 * red - 5 * dodatneLezaljke;
		return cenaLezaljki * (1 + 0.4 * dodatneLezaljke) + cenaNapica * (1 - popust / 100.0);
	}

	void Prikazi() const override {
		cout << "Par lezaljki sa dodatkom: Redni broj: " << redniBroj
			<< ", red: " << red
			<< ", cena lezaljki: " << cenaLezaljki
			<< ", cena napitaka: " << cenaNapica
			<< ", broj dodatih: " << dodatneLezaljke
			<< ", ukupna cena: " << UkupnaCena() << endl;
	}

	friend ostream& operator<<(ostream& os, const ParLezaljkiSaDodatkom& p) {
		os << "ParLezaljkiSaDodatkom: redniBroj=" << p.redniBroj
			<< ", red=" << p.red
			<< ", cenaLezaljki=" << p.cenaLezaljki
			<< ", cenaNapica=" << p.cenaNapica
			<< ", dodatneLezaljke=" << p.dodatneLezaljke
			<< ", ukupnaCena=" << p.UkupnaCena();
		return os;
	}

};