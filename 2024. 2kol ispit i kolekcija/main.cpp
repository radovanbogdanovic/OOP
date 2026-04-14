#include <iostream>
#include "Kolekcija.h"
#include "Ispit.h"
using namespace std;

int main() {
	int maxPodataka = 8, brojPodataka = 5; //probaj i sa 9 za gresku(ja dop)
	int test[] = { 23, 37, 28, 31, 34 };
	const char* naziv[] = { "AIP", "UUR", "FIZ", "MAT", "EKM" };
	int ocena[] = { 10, 10, 6, 7, 8 };
	int espb[] = { 3, 5, 6, 5, 5 };
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	{
		// 1 bod
		Kolekcija<int> kolekcijaA(maxPodataka);
		// 1 bod
		try {
			for (int i = 0; i < brojPodataka; i++)
				kolekcijaA.DodajPodatak(test[i]);
				// 1 bod
				cout << kolekcijaA << endl;
			}// kolekcijaA.Ispisi(cout);
		catch (Greska g)
		{
			cout << GreskaToString(g) << endl;
		}
		try {
			// 1 bod
			kolekcijaA.Obrisi(4);
			cout << kolekcijaA << endl;
			}// kolekcijaA.Ispisi(cout);
		catch (Greska g)
		{
			cout << GreskaToString(g) << endl;
		}
		// 1 bod
		float prosecnaOcena = kolekcijaA.OdrediProsek();
		cout << prosecnaOcena << endl;
		// 1 bod
		int najveciPodatak = kolekcijaA.NajveciPodatak();
		cout << najveciPodatak << endl;
		// 1 bod
		try {
			kolekcijaA.Sacuvaj("Kolekcija.txt");
		}
		catch (Greska g)
		{
			cout << GreskaToString(g) << endl;
		}
		// 2 boda
		Kolekcija<int> KolekcijaAtest(maxPodataka);
		try {
			KolekcijaAtest.Ucitaj("Kolekcija.txt");
			cout << KolekcijaAtest << endl;
		}// kolekcijaatest.ispisi(cout);
		catch (Greska g)
		{
			cout << GreskaToString(g) << endl;
		}
	}
	{
		// 1 bod
		Kolekcija<Ispit> kolIspit(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			Ispit tmp(naziv[i], ocena[i], espb[i]);
			try {
				kolIspit.DodajPodatak(tmp);
			}
			catch (Greska g)
			{
				cout << GreskaToString(g) << endl;
			}
		}
		// 1 bod
		cout << kolIspit << endl; // kolIspit.Ispisi(cout);
		// 0 bodova
		try {
			kolIspit.Obrisi(4);
			cout << kolIspit << endl;
		}// kolIspit.Ispisi(cout);
		catch (Greska g)
		{
			cout << GreskaToString(g) << endl;
		}
		// 2 boda
		float prosecnaOcena2 = kolIspit.OdrediProsek();
		cout << prosecnaOcena2 << endl;
		// 2 boda
		Ispit najveci = kolIspit.NajveciPodatak();
		cout << najveci << endl;
		// 0 bod
		try {
			kolIspit.Sacuvaj("Ispiti.txt");
		}
		catch (Greska g)
		{
			cout << GreskaToString(g) << endl;
		}
		// 1 bod
		Kolekcija<Ispit> kolIspitTest(maxPodataka);
		try {
			kolIspitTest.Ucitaj("Ispiti.txt");
			cout << kolIspitTest << endl;
		}// kolIspitTest.Ispisi(cout);
		catch (Greska g)
		{
			cout << GreskaToString(g) << endl;
		}
	}
}