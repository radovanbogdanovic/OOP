#include "Lekcija.h"

Lekcija::Lekcija() : IspitniMaterijal()
{
	duzinaStr = 0;
}

Lekcija::Lekcija(int _oznaka, double _tezina, double _duzinaStr) : IspitniMaterijal(_oznaka, _tezina)
{
	duzinaStr = _duzinaStr;
}

ostream& Lekcija::Ispisi(ostream& os)
{
	IspitniMaterijal::Ispisi(os);

	os << "Duzina lekcije: " << duzinaStr << endl;
	
	return os;
}
double Lekcija::potrebnovreme(int v) const
{
	double vreme = 0;
	vreme = duzinaStr * tezina * v;
	return vreme;
}

