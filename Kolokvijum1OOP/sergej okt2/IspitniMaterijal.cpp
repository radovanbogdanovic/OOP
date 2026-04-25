#include "IspitniMaterijal.h"
#include <iostream>
#include <stdio.h>
using namespace std;

IspitniMaterijal::IspitniMaterijal(const IspitniMaterijal& drugi)
{
	oznaka = drugi.oznaka;
	tezina = drugi.tezina;
	savladan = drugi.savladan;

}

ostream& IspitniMaterijal::Ispisi(ostream& os)
{
	os << "Oznaka: " << oznaka << endl;
	os << "Tezina: " << tezina << endl;
	if (savladan == true) {
		os << "Savladan: " << "Da " << endl;
	}
	else {
		os << "Savladan: " << "Ne " << endl;
	}
	os << endl;


	return os;
}

ostream& operator<<(ostream& os, IspitniMaterijal& p)
{
	return p.Ispisi(os);
}
