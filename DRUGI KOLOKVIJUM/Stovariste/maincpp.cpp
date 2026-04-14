#include "Greska.h"
#include "PaletaProsirena.h"
#include "Skladiste.h"

void main()
{
	int brElemenata = 10;
	int brojPodataka = 7;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	try
	{
		int masa[] = { 200, 300, 350, 250, 400, 300, 450 };
		Skladiste<int> skladiste(brElemenata);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			skladiste.Dodaj(masa[i]);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		// 1 bod
		skladiste.Preuzmi(5, 200);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		skladiste.Preuzmi(5, 100);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		// 1 bod
		int ukupno = skladiste.UkupnaMasa();
		cout << ukupno << endl;
		// 1 bod
		int zMasa = 2;
		int broj = skladiste.BrojSaVecomKolicinom(zMasa);
		cout << broj << endl;
		// 1 bod
		int min = 0, max = 0;
		skladiste.NajViseManje(2, 4, min, max);
		cout << min << " " << max << endl;
		// 1 bod
		char fajl[] = "SkladOs.txt";
		skladiste.Sacuvaj(fajl);
		// 1 bod
		Skladiste<int> skladisteUcitano;
		skladisteUcitano.Ucitaj(fajl);
		cout << skladisteUcitano << endl; //skladisteUcitano.Ispisi(cout);
	}
	catch (Greska g)
	{
		switch (g)
		{
		case UCITAJ_GRESKA: cout << "greska ucitaj"; break;
		case SACUVAJ_GRESKA: cout << "greska sacuvaj"; break;
		case NIZ_PUN: cout << "greska niz"; break;
		case LOS_INDEKS: cout << "greska indeks"; break;
		case LOSA_KOLICINA: cout << "greska kolicina"; break;
		}
	}
	try
	{
		float masa[] = { 20, 30, 20, 60, 35, 55, 30 };
		int broj[] = { 40, 40, 30, 30, 20, 20, 20 };
		float sirina[] = { 20, 50, 25, 60, 30, 50, 35 };
		Skladiste<PaletaProsirena> skladiste(brElemenata);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			skladiste.Dodaj(PaletaProsirena(masa[i], broj[i], sirina[i]));
		}
		// 1 bod
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		// 1 bod
		skladiste.Preuzmi(4, 300);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		skladiste.Preuzmi(4, 400);
		cout << skladiste << endl; //skladiste.Ispisi(cout);
		// 2 boda
		float ukupno = skladiste.UkupnaMasa();
		cout << ukupno << endl;
		// 2 boda
		int zMasa = 2;
		int brojVK = skladiste.BrojSaVecomKolicinom(zMasa);
		cout << brojVK << endl;

		// 2 boda
		PaletaProsirena min, max;
		skladiste.NajViseManje(1, 4, min, max);
		cout << min << " " << max << endl;
		// 0 bod
		char fajl[] = "SkladPr.txt";
		skladiste.Sacuvaj(fajl);
		// 1 bod
		Skladiste<PaletaProsirena> skladisteUcitano;
		skladisteUcitano.Ucitaj(fajl);
		cout << skladisteUcitano << endl; //skladisteUcitano.Ispisi(cout);
	}
	catch (Greska g)
	{
		switch (g)
		{
		case UCITAJ_GRESKA: cout << "greska ucitaj"; break;
		case SACUVAJ_GRESKA: cout << "greska sacuvaj"; break;
		case NIZ_PUN: cout << "greska niz"; break;
		case LOS_INDEKS: cout << "greska indeks"; break;
		case LOSA_KOLICINA: cout << "greska kolicina"; break;
		}
	}
}