#pragma once
#include "Lezaljka.h"

class ParLezaljki : public Lezaljka {
public:
	ParLezaljki(int rb, int r, int c, int n)
		: Lezaljka(rb, r, c, n) {}
	
	double UkupnaCena() const override {
		double popust = 40 - 2 * red;
		return cenaLezaljki + cenaNapica * (1 - popust / 100.0);
	}
	
	void Prikazi() const override {
		cout << "Par lezaljki: Redni broj: " << redniBroj
			<< ", red: " << red
			<< ", cena lezaljki: " << cenaLezaljki
			<< ", cena napitaka: " << cenaNapica
			<< ", ukupna cena: " << UkupnaCena() << endl;
	}

	friend ostream& operator<<(ostream& os, const ParLezaljki& p) {
		os << "ParLezaljki: redniBroj=" << p.redniBroj
			<< ", red=" << p.red
			<< ", cenaLezaljki=" << p.cenaLezaljki
			<< ", cenaNapica=" << p.cenaNapica
			<< ", ukupnaCena=" << p.UkupnaCena();
		return os;
	}
};