#include "Lekcija.h"

Lekcija::Lekcija(int o, float t, float s) 
	: IspitniMaterijal(o, t), stranice(s) { }

void Lekcija::print(ostream& os) const
{
	os << "LEKCIJA:";
	IspitniMaterijal::print(os);
	os << ", broj strana: " << stranice << endl;
}

