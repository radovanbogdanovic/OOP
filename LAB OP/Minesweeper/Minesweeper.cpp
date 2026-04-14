
#include "Minesweeper.h"


Minesweeper::Minesweeper()
{
	x = 10;
	y = 10;

	matrica = new bool* [x];

	for (int i = 0; i < x; i++)
	{
		matrica[i] = new bool[y];

	}

	ime = nullptr;

}

Minesweeper::Minesweeper(int xx, int yy)
{
	
	x = xx;
	y = yy;

	matrica = new bool* [x];

	for (int i = 0; i < x; i++)
	{
		matrica[i] = new bool [y];

	}

	ime = nullptr;
}

Minesweeper::~Minesweeper()
{
	for (int i = 0; i < x; i++)
		delete[] matrica[i];

	delete[] matrica;

	delete[] ime;
}

Minesweeper::Minesweeper(const Minesweeper& m)
{
	x = m.x;
	y = m.y;

	matrica = new bool* [x];

	for (int i = 0; i < x; i++) {
		matrica[i] = new bool[y];
		for (int j = 0; j < y; j++)
			matrica[i][j] = m.matrica[i][j];
	}

	ime = nullptr; 
}

int Minesweeper::BrMina(int m, int n)
{
	if (matrica[m][n] == true)
		return -1;

	int brojac=0;

	int red[] = { -1, -1, -1, 1, 1, 1, 0, 0 };
	int kolona[] = { -1, 0, 1, -1, 0, 1, -1, 1 };
	
	for (int i = 0; i < 8; i++)
	{
		int r = m + red[i];
		int k = n + kolona[i];
		if (!(r < 0 || r >= x || k < 0 || k >= y) && matrica[r][k] == true)
			brojac++;
	}

	return brojac;
}

void Minesweeper::ucitaj()
{
	int op;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> op;
			if (op == 0)
				matrica[i][j] = false;
			else
				matrica[i][j] = true;
		}
	}

}

void Minesweeper::prikaz()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << matrica[i][j] << " ";

		cout << endl;
	}

}

void Minesweeper::izbaci()
{
	int brojac;

	for (int i = 0; i < x; i++)
	{
		brojac = 0;
		for (int j = 0; j < y; j++)
			if (matrica[i][j] == 1)
				brojac++;

		if (brojac == 0)
		{
				for (int p = i; p < x-1; p++)
				{
					for (int j = 0; j < y; j++)
						matrica[p][j] = matrica[p+1][j];
				}
			x--;
			i--;
		}

	}

	for (int j = 0; j < y; j++)
	{
		int brojac = 0;
		for (int i = 0; i < x; i++)
			if (matrica[i][j] == 1)
				brojac++;

		if (brojac == 0)
		{
			for (int i = 0; i < x; i++)
				for (int k = j; k < y - 1; k++)
					matrica[i][k] = matrica[i][k + 1];

			y--;
			j--;
		}
	}
}

void Minesweeper::PomeriDesno()
{
	for (int i = 0; i < x; i++)
	{
		bool pom = matrica[i][y - 1];
		for (int j = y - 1; j > 0; j--)
			matrica[i][j] = matrica[i][j - 1];
		matrica[i][0] = pom;
	}
}

void Minesweeper::PomeriLevo()
{
	for (int i = 0; i < x; i++)
	{
		bool pom = matrica[i][0];
		for (int j = 0; j < y-1; j++)
			matrica[i][j] = matrica[i][j + 1];
		matrica[i][y-1] = pom;
	}
}

void Minesweeper::PomeriGore()
{
	for (int j = 0; j < y; j++)
	{
		bool pom = matrica[0][j];
		for (int i = 0; i < x - 1; i++)
			matrica[i][j] = matrica[i + 1][j];
		matrica[x - 1][j] = pom;

	}

}

void Minesweeper::PomeriDole()
{
	for (int j = 0; j < y; j++)
	{
		bool pom = matrica[x - 1][j];
		for (int i = x - 1; i > 0; i--)
			matrica[i][j] = matrica[i-1][j];
		matrica[0][j] = pom;
	}
}

void Minesweeper::PopuniMinom(int nn)
{
	int brojac = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (matrica[i][j] == 0)
				brojac++;

			if (brojac == nn)
			{
				matrica[i][j] = 1;
				brojac = 0;
			}
		}
	}
}

istream& operator >> (istream& ulaz, Minesweeper& m)
{
	for (int i = 0; i < m.x; i++)
		for (int j = 0; j < m.y; j++)
			ulaz >> m.matrica[i][j];

	return ulaz;
}

ostream& operator << (ostream& izlaz, Minesweeper& m)
{
	for (int i = 0; i < m.x; i++)
	{
		for (int j = 0; j < m.y; j++)
			izlaz << m.matrica[i][j] << " ";
		izlaz << endl;
	}

	izlaz << endl;
	return izlaz;
}
