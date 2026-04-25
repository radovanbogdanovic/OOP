#include "Zadatak.h"

Zadatak::Zadatak() : IspitniMaterijal()
{
    brojL = 0;
}

Zadatak::Zadatak(int _oznaka, double _tezina, int _brojl) : IspitniMaterijal(_oznaka, _tezina)
{
    brojL = _brojl;
}

ostream& Zadatak::Ispisi(ostream& os)
{
    IspitniMaterijal::Ispisi(os);
    os << "Broj lekcija: " << brojL << endl;

    return os;
}

double Zadatak::potrebnovreme(int v) const
{
    double vreme = 0;
    vreme = brojL * tezina * v * 0.05;
    return vreme;
}
