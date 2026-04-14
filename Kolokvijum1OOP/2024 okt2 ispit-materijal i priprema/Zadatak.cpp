#include "Zadatak.h"

Zadatak::Zadatak(int o, float t, int b)
	: IspitniMaterijal(o, t), br_linija(b) {
}

void Zadatak::print(ostream& os) const
{
	os << "ZADATAK:";
	IspitniMaterijal::print(os);
	os << ", broj linija: " << br_linija << endl;
}