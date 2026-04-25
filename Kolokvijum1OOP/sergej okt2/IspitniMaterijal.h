#pragma once
#include <iostream>
using namespace std;


class IspitniMaterijal
{
protected:
	int oznaka;
	double tezina;
	bool savladan;
public:

	IspitniMaterijal() {
		oznaka = 0;
		tezina = 0.0;
		savladan = false;
	};

	IspitniMaterijal(int _oznaka, double _tezina) {
		oznaka = _oznaka;
		tezina = _tezina;
		savladan = false;
	}

	~IspitniMaterijal() {};

	IspitniMaterijal(const IspitniMaterijal& drugi);

	int vratiOznaku() const {
		return oznaka;
	}
	bool jelSavladan()const { 
		return savladan; };

	virtual ostream& Ispisi(ostream& os);
	friend ostream& operator<<(ostream& os, IspitniMaterijal& p);

	void setSavladan(bool _savladan) {
		savladan = _savladan;
	}
	virtual double potrebnovreme(int v)const = 0;
};