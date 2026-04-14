#include "Minesweeper.h"
#include <fstream>

int main()
{
    ifstream* ulaz = new ifstream("ulaz.txt");
    if (ulaz->good())
    {
        int* x = new int;
        int* y = new int;

        *ulaz >> *x >> *y;

        Minesweeper* M = new Minesweeper(*x, *y);
        *ulaz >> *M;
        ulaz->close();

        cout << "Prikaz pocetne matrice: \n" << *M;

        M->PomeriGore();
        cout << "Mine pomerene gore: \n" << *M;

        M->PomeriDole();
        cout << "Mine pomerene dole: \n" << *M;

        M->PomeriDesno();
        cout << "Mine pomerene desno: \n" << *M;

        M->PomeriLevo();
        cout << "Mine pomerene levo: \n" << *M;

        M->PopuniMinom(5);
        cout << "Svako peto polje popunjeno je minom \n" << * M;

        delete M;
        delete x;
        delete y;
        delete ulaz;
    }
    else
    {
        cout << "FAJL NIJE USPESNO OTVOREN \n";
        delete ulaz;
        return 0;
    }
}