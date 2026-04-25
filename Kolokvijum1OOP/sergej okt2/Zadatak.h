#pragma once
#include "IspitniMaterijal.h"
class Zadatak :
    public IspitniMaterijal
{
private:
    int brojL;
public:

    Zadatak();
    Zadatak(int _oznaka, double _tezina, int _brojL);
    ~Zadatak(){}


    ostream& Ispisi(ostream& os);

    double potrebnovreme(int v)const override;

};

