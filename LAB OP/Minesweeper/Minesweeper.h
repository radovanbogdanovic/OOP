#pragma once
#include <iostream>
using namespace std;

class Minesweeper
{
private:
	bool** matrica;
	int x;
	int y;
	char* ime;

public:
	Minesweeper();
	
	Minesweeper(int xx, int yy);

	~Minesweeper();

	Minesweeper(const Minesweeper& m);

	inline int VratiX() const { return x;}

	inline int VratiY() const { return y; }

	int BrMina(int xx, int yy);

	void ucitaj();

	void prikaz();

	void izbaci();

	void PomeriDesno();

	void PomeriLevo();

	void PomeriGore();

	void PomeriDole();

	void PopuniMinom(int nn);

	friend istream& operator >> (istream& ulaz, Minesweeper& m);

	friend ostream& operator << (ostream& izlaz, Minesweeper& m);
};

