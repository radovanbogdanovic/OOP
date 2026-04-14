#include <fstream>
#include <iostream>
#include "Putnik.h"
#include "Skijanje.h"
#include "Sankanje.h"
#include "Autobus.h"
using namespace std;
int main()
{
	// A) Kopaonik
	// 2 poena
	Putnik* p1 = new Sankanje("Mika", "2A", 12, 0.65);
	//p1->print();
	cout << *p1 << endl;
	// 2 poena
	Putnik* p2 = new Skijanje("Anta", "5B", 170, 2700, 1900);
	//p2->print();
	cout << *p2 << endl;
		Autobus a1(4);
		Autobus* a2 = new Autobus(4);
		// 2 poena
		for (int i = 0; i < a1.BrojPutnika() / 2; i++)
		{
			a1.Dodaj(new Sankanje("Mara", "4C", 13, 0.7));
			a1.Dodaj(new Skijanje("Ana", "7D", 175, 2700, 1900));
		}
		a2->Dodaj(new Sankanje("Zika", "4C", 14, 0.75));
		a2->Dodaj(new Skijanje("Joca", "7D", 180, 2750, 2000));
		a2->Dodaj(new Sankanje("Branka", "5A", 11, 0.6));
		a2->Dodaj(new Skijanje("Goca", "15A", 165, 1900, 1800));
		// 2 poena
		//a1.print();
		cout << a1 << endl;
		cout << *a2 << endl;
	//	// 3 poena
		Autobus a3 = a1 + *a2;
	//	//a3.print();
		cout << a3 << endl;
	//	// 2 poena
		delete a2;
	//	// 2 poena
		a1.Upisi("zimovanje.txt");
		// 3 poena
		Putnik* pmaxOprema = a3.MaxOprema();
		cout << *pmaxOprema << endl;
		//a3.print();
		cout << a3 << endl;
		// 2 poena
		cout << "Ukupna masa opreme: " << a3.UkupnaOprema() << endl;
}