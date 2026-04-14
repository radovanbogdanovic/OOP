#include <iostream>
#include "Polinom.h"
#include "Complex.h"
#include "Naziv.h"

using namespace std;

int main() {

    // Polinom stepena 5 (6 koeficijenata)
    Polinom<double, 5>* realniPolinom = new Polinom<double, 5>();
    Polinom<Complex, 5>* kompleksniPolinom = new Polinom<Complex, 5>();

    // Polinom stepena 2 (3 koeficijenta) sa char*
    Polinom<Naziv, 2>* tekstualniPolinom = new Polinom<Naziv, 2>();

    cout << "Unesite koeficijente za REALNI polinom (6 brojeva):" << endl;
    realniPolinom->ucitaj();

    cout << "\nUnesite koeficijente za KOMPLEKSNI polinom (6 parova realni imaginarni):" << endl;
    kompleksniPolinom->ucitaj();

    cout << "\nUnesite koeficijente za TEKSTUALNI polinom (3 reci):" << endl;
    tekstualniPolinom->ucitaj();

    double xReal = 2;
    cout << "\nVrednost realnog polinoma za x = 2 je: "
        << realniPolinom->IzracunajPolinom(xReal) << endl;

    Complex xComplex(2.0, 0.0);
    cout << "Vrednost kompleksnog polinoma za x = 2 je: "
        << kompleksniPolinom->IzracunajPolinom(xComplex) << endl;

    Naziv xNaziv("_X");
    cout << "Vrednost tekstualnog polinoma za x = X je: "
        << tekstualniPolinom->IzracunajPolinom(xNaziv) << endl;

    delete realniPolinom;
    delete kompleksniPolinom;
    delete tekstualniPolinom;

    return 0;
}