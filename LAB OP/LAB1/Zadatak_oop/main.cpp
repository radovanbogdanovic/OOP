#include "Minesweeper.h"

void main() 
{
	Minesweeper m1(4, 4);
	Minesweeper m2(3, 3);

	cout << "Uneti 0 za prazno polje ili 1 za minu u prvo polje:" << endl;
	m1.ucitaj();
	cout << "Uneti 0 za prazno polje ili 1 za minu u drugo polje:" << endl;
	m2.ucitaj();
	int n = m1.brojMinaOkoPolja(0, 0);
	if (n == -1)
	{
		cout << "Pogodjena je mina!" << endl;
		m1.prikazi();
	}
	else 
	{
		cout << "Broj mina oko polja: " << n << endl;
	}
	cout << "Broj redova drugog polja: " << m2.vrati_redove() << endl;
	cout << "Broj kolona drugog polja: " << m2.vrati_kolone() << endl;
	cout << "Drugo polje pre izbacivanja praznih redova i kolona: " << endl;
	m2.prikazi();
	m2.izbaci();
	cout << "Drugo polje nakon izbacivanja praznih redova i kolona: " << endl;
	m2.prikazi();
}