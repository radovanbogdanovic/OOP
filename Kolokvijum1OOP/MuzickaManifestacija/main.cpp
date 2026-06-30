#include <iostream>
#include "JednodnevnaKarta.h"
#include "KompletKarata.h"
#include "Manifestacija.h"
using namespace std;

void zadatak1()
{
	// 2 boda
	char o1[] = "JK00";
	char s1 = 'A';
	int v1[] = { 2000, 1 };
	JednodnevnaKarta* p1 = new JednodnevnaKarta(o1, s1, v1[0], v1[1]);
	cout << "Jednodnevna karta: " << endl;
	cout << *p1 << endl; //p1->Ispisi();

	// 2 boda
	char o2[] = "KK00";
	char s2 = 'A';
	int v2[] = { 4000, 10 };
	KompletKarata* p2 = new KompletKarata(o2, s2, v2[0], v2[1]);
	cout << "Komplet karata: " << endl;
	cout << *p2 << endl; //p2->Ispisi();

	char oz[][10] = { "JK1", "KK2", "JK3", "KK4", "JK5",
					  "KK6", "JK&", "KK8", "JK9", "KK10" };

	char sek[] = { 'A', 'B', 'C', 'C', 'B', 'A', 'C', 'B', 'B', 'A' };
	int cena[] = { 1000, 4500, 2000, 5000, 1500, 3000, 1500, 7000, 1000, 6000 };
	float n[] = { 1, 2, 3, 2, 1 };
	float pop[] = { 10, 4, 8, 8, 10 };

	int brElem = 10;
	Manifestacija* pMan = new Manifestacija(brElem + 2);

	// 2 boda
	for (int i = 0; i < brElem / 2; i++)
	{
		pMan->Dodaj(new JednodnevnaKarta(oz[2 * i], sek[2 * i], cena[2 * i], n[i]));
		pMan->Dodaj(new KompletKarata(oz[2 * i + 1], sek[2 * i + 1], cena[2 * i + 1], pop[i]));
	}

	// 1 bod
	cout << "Dodate karte: " << endl;
	cout << *pMan << endl; //pMan->Ispisi();

	// 3 boda
	int ind = 7, br = 2;
	pMan->VratiKarte(ind, br);
	cout << "Vracene karte: " << endl;
	cout << *pMan << endl; //pMan->Ispisi();

	// 2 boda
	cout << "Ukupna zarada: " << pMan->UkupnaZarada() << endl;

	// 2 boda
	char sektor = pMan->SektorSaNajviseKarata();
	cout << "Sektor sa najvise karata: " << sektor << endl;

	// 2 boda
	int zaradaDan = 0;
	int rbDan = pMan->DanSaNajvecomZaradom(zaradaDan);
	cout << "Najveca zarada je " << rbDan << ". dana i iznosi " << zaradaDan << endl;

	// 3 boda
	OsnovnaKarta* pMax = nullptr, * pAfterMax = nullptr;
	pMan->NajskupljeKarte(&pMax, &pAfterMax);

	cout << "Dve najskuplje karte su: " << endl;
	cout << *pMax << endl;       //pMax->Ispisi();
	cout << *pAfterMax << endl;  //pAfterMax->Ispisi();

	// 1 bod
	delete pMan;
	delete p1;
	delete p2;
}

int main()
{
	zadatak1();
	return 0;
}
