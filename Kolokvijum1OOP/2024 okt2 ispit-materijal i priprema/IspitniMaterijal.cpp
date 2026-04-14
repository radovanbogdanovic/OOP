#include "IspitniMaterijal.h"

IspitniMaterijal::IspitniMaterijal(int o, float t)
	: oznaka(o), tezina(t), savladan(false) { }

void IspitniMaterijal::print(ostream& os) const
{
	os << " oznaka: " << oznaka
		<< ", tezina: " << tezina;
	if (savladan)
		os << ", savladan: Da";
	else 
		os << ", savladan: Ne";
}

ostream& operator<<(ostream& os, IspitniMaterijal& i)
{
	i.print(os);
	return os;
}
