#include "Lezaljka.h"
#include "Plaza.h"
#include "Greska.h"

void main()
{
	int brRedova = 4, brKolona = 8;
	int brojPodataka = 7;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	{
		int red[] = { 1, 1, 2, 2, 3, 3, 3 };
		int kolona[] = { 2, 5, 1, 6, 3, 5, 7 };
		int lez[] = { 2, 3, 2, 2, 4, 3, 2 };
		Plaza<int> plaza(brRedova, brKolona);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			plaza.Dodaj(red[i], kolona[i], lez[i]);
		cout << plaza << endl; //plaza.Ispisi(cout);
		// 1 bod
		plaza.Oslobodi(red[3], kolona[3]);
		cout << plaza << endl; //plaza.Ispisi(cout);
		// 1 bod
		int ukupno = plaza.Ukupno();
		cout << ukupno << endl;
		// 1 bod
		int brLez = 2;
		int brojMesta = plaza.BrojMesta(brLez);
		cout << brojMesta << endl;
		// 1 bod
		int brojLez = 0;
		int redNaj = plaza.RedSaNajvise(brojLez);
		cout << redNaj << " " << brojLez << endl;
		// 1 bod
		char fajl[] = "PlazaVal.txt";
		plaza.Sacuvaj(fajl);
		// 1 boda
		Plaza<int> plazaUcitana;
		plazaUcitana.Ucitaj(fajl);
		cout << plazaUcitana << endl; //plazaUcitana.Ispisi(cout);
	}
	{
		int red[] = { 1, 1, 2, 2, 3, 3, 3 };
		int kolona[] = { 2, 5, 1, 6, 3, 5, 7 };
		int lez[] = { 2, 3, 2, 2, 4, 3, 2 };
		int cena[] = { 40, 40, 30, 30, 20, 20, 20 };
		Plaza<Lezaljka> plaza(brRedova, brKolona);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			plaza.Dodaj(red[i], kolona[i], Lezaljka(lez[i], cena[i]));
		}
		// 1 bod
		cout << plaza << endl; //plaza.Ispisi(cout);
		// 1 bodova
		plaza.Oslobodi(red[3], kolona[3]);
		cout << plaza << endl; //plaza.Ispisi(cout);
		// 2 bod
		float ukupno = plaza.Ukupno();
		cout << ukupno << endl; // 2664
		// 2 bod
		int brLez = 2;
		int brojMesta = plaza.BrojMesta(brLez);
		cout << brojMesta << endl;

		// 2 bod
		int brojLez = 0;
		int redNaj = plaza.RedSaNajvise(brojLez);
		cout << redNaj << " " << brojLez << endl;
		// 0 bod
		char fajl[] = "PlazaVall.txt";
		plaza.Sacuvaj(fajl);
		// 1 bod
		Plaza<Lezaljka> plazaUcitana;
		plazaUcitana.Ucitaj(fajl);
		cout << plazaUcitana << endl; //novValUc.Ispisi(cout);
	}
}