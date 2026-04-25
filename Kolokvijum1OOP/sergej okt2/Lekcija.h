#pragma once
#include "IspitniMaterijal.h"
#include <iostream>

class Lekcija :
    public IspitniMaterijal
{
private:
    double duzinaStr;

public:
    Lekcija();
    Lekcija(int _oznaka, double _tezina, double _duzinaStr);
    ~Lekcija() {}


    ostream& Ispisi(ostream& os);

    double potrebnovreme(int v)const override;
};

