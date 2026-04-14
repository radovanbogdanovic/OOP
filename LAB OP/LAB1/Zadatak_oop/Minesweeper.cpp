#include "Minesweeper.h"

Minesweeper::Minesweeper() 
{
	n = m = 10;
	polje = new bool* [n];

	for (int i = 0; i < n; i++)
	{
		polje[i] = new bool[m];
	}
	naziv = nullptr;
}
Minesweeper::Minesweeper(int red, int kolona) 
	:n(red), m(kolona)
{
	polje = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		polje[i] = new bool[m];
	}
	naziv = nullptr;
}
Minesweeper::~Minesweeper() 
{
	if (polje != 0)
	{
		for (int i = 0; i < n; i++) 
		{
			delete[] polje[i];
		}
		delete[] polje;
	}
}
void Minesweeper::ucitaj() 
{
	int num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> num;
			if (num == 0)
			{
				polje[i][j] = false;
			}
			else {
				polje[i][j] = true;
			}
		}
	}
}
void Minesweeper::prikazi() 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) 
		{
			cout << polje[i][j] << " ";
		}
		cout << endl;
	}
}
int Minesweeper::brojMinaOkoPolja(int red, int kolona) 
{
	if (polje[red][kolona] == true)
	{
		return -1;
	}
	int brojac = 0;
	for (int i = red-1; i <= red+1; i++)
	{
		for (int j = kolona-1; j <= kolona+1; j++)
		{
			if (i >= 0 && i < n && j >= 0 && j < m && !(i == red && j == kolona) && polje[i][j] == true)
			{
				brojac++;
			}
		}
	}
	return brojac;
}
void Minesweeper::izbaci() 
{
	//proveravamo da li redovi imaju bar jednu minu 
	bool* redImaMinu = new bool [n];
	for (int i = 0; i < n; i++)
	{
		redImaMinu[i] = false;
		for (int j = 0; j < m; j++)
		{
			if (polje[i][j] == true)
			{
				redImaMinu[i] = true;
				break;
			}
		}
	}
	//proveravamo da li kolone imaju bar jednu minu
	bool* kolImaMinu = new bool[m];
	for (int i = 0; i < m; i++)
	{
		kolImaMinu[i] = false;
		for (int j = 0; j < n; j++)
		{
			if (polje[j][i] == true)
			{
				kolImaMinu[i] = true;
				break;
			}
		}
	}
	//brojimo kolone i redove sa bar jednom minom
	int novoN = 0;
	int novoM = 0;
	for (int i = 0; i < n; i++)
	{
		if (redImaMinu[i] == true) 
		{
			novoN++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (kolImaMinu[i] == true)
		{
			novoM++;
		}
	}
	//pravimo novu matricu
	bool** novoPolje = new bool* [novoN];
	for (int i = 0; i < novoN; i++)
	{
		novoPolje[i] = new bool[novoM];
	}
	//prebacujemo elemente iz stare u novu matricu
	int nn = 0;
	for (int i = 0; i < n; i++)
	{
		if (!redImaMinu[i])
		{
			continue;
		}
		int mm = 0;
		for (int j = 0; j < m; j++)
		{
			if (!kolImaMinu[j])
			{
				continue;
			}
			novoPolje[nn][mm] = polje[i][j];
			mm++;
		}
		nn++;
	}
	if (polje != 0)
	{
		for (int i = 0; i < n; i++) 
		{
			delete[] polje[i];
		}
		delete[] polje;
	}
	delete[] redImaMinu;
	delete[] kolImaMinu;
	polje = novoPolje;
	n = novoN;
	m = novoM;
}