#include "Ispit.h"
#include "Kolekcija.h"
#include "Greske.h"

void main() {
    int maxPodataka = 8, brojPodataka = 5;
    int test[] = { 23, 37, 28, 31, 34 };

    const char* naziv[] = { "AIP", "UUR", "FIZ", "MAT", "EKM" };
    int ocena[] = { 10, 10, 6, 7, 8 };
    int espb[] = { 3, 5, 6, 5, 5 };

    // 3 boda
    // postavljanje i prihvatanje izuzetaka
    try {
        {
            // 1 bod
            Kolekcija<int> kolekcijaA(maxPodataka);
            // 1 bod
            for (int i = 0; i < brojPodataka; i++)
                kolekcijaA.DodajPodatak(test[i]);
            // 1 bod
            cout << kolekcijaA << endl; // kolekcijaA.Ispisi(cout);
            // 1 bod
            kolekcijaA.Obrisi(4);
            cout << kolekcijaA << endl; // kolekcijaA.Ispisi(cout);
            // 1 bod
            float prosecnaOcena = kolekcijaA.OdrediProsek();
            cout << prosecnaOcena << endl;
            // 1 bod
            int najveciPodatak = kolekcijaA.NajveciPodatak();
            cout << najveciPodatak << endl;
            // 1 bod
            kolekcijaA.Sacuvaj("KolekcijaA.txt");
            // 2 boda
            Kolekcija<int> kolekcijaATest(maxPodataka);
            kolekcijaATest.Ucitaj("KolekcijaA.txt");
            cout << kolekcijaATest << endl; // kolekcijaATest.Ispisi(cout);
        }
    }
    catch (Greske g)
    {
        switch (g) {
        case KOLEKCIJA_PUNA: cout << "Greska: Kolekcija je puna!" << endl; break;
        case POGRESAN_INDEKS: cout << "Greska: Pogresan indeks!" << endl; break;
        case PRAZNA_KOLEKCIJA: cout << "Greska: Kolekcija je prazna!" << endl; break;
        case FAJL_GRESKA_SACUVAJ: cout << "Greska: Problem sa cuvanjem fajla!" << endl; break;
        case FAJL_GRESKA_UCITAJ: cout << "Greska: Problem sa ucitavanjem fajla!" << endl; break;
        }
    }
    try {
        {
            // 1 bod
            Kolekcija<Ispit> kolIspit(maxPodataka);
            // 1 bod
            for (int i = 0; i < brojPodataka; i++) {
                Ispit tmp(naziv[i], ocena[i], espb[i]);
                kolIspit.DodajPodatak(tmp);
            }
            // 1 bod
            cout << kolIspit << endl; // kolIspit.Ispisi(cout);
            // 0 bodova
            kolIspit.Obrisi(4);
            cout << kolIspit << endl; // kolIspit.Ispisi(cout);
            // 2 boda
            float prosecnaOcena2 = kolIspit.OdrediProsek();
            cout << prosecnaOcena2 << endl;
            // 2 boda
            Ispit najveci = kolIspit.NajveciPodatak();
            cout << najveci << endl;
            // 0 bod
            kolIspit.Sacuvaj("Ispiti.txt");
            // 1 bod
            Kolekcija<Ispit> kolIspitTest(maxPodataka);
            kolIspitTest.Ucitaj("Ispiti.txt");
            cout << kolIspitTest << endl; // kolIspitTest.Ispisi(cout);
        }
    }
    catch (Greske g)
    {
        switch (g) {
        case KOLEKCIJA_PUNA: cout << "Greska: Kolekcija je puna!" << endl; break;
        case POGRESAN_INDEKS: cout << "Greska: Pogresan indeks!" << endl; break;
        case PRAZNA_KOLEKCIJA: cout << "Greska: Kolekcija je prazna!" << endl; break;
        case FAJL_GRESKA_SACUVAJ: cout << "Greska: Problem sa cuvanjem fajla!" << endl; break;
        case FAJL_GRESKA_UCITAJ: cout << "Greska: Problem sa ucitavanjem fajla!" << endl; break;
        }
    }
}
