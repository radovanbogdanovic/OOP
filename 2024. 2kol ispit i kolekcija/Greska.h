#pragma once

enum Greska {
    KOLEKCIJA_PUNA,
    NEISPRAVAN_INDEKS,
    PRAZNA_KOLEKCIJA,
    FAJL_GRESKA_SACUVAJ,
    FAJL_GRESKA_UCITAJ
};

inline const char* GreskaToString(Greska g) {
    switch (g) {
    case KOLEKCIJA_PUNA:
        return "Greska: Kolekcija je puna!";
    case NEISPRAVAN_INDEKS:
        return "Greska: Neispravan indeks!";
    case PRAZNA_KOLEKCIJA:
        return "Greska: Kolekcija je prazna!";
    case FAJL_GRESKA_SACUVAJ:
        return "Greska: Problem pri snimanju fajla!";
    case FAJL_GRESKA_UCITAJ:
        return "Greska: Problem pri ucitavanju fajla!";
    default:
        return "Nepoznata greska!";
    }
}
