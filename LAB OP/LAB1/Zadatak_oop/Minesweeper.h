#include <iostream>
using namespace std;

class Minesweeper 
{
private:
	int n; //broj redova
	int m; //broj kolona
	bool** polje;
	char* naziv;
public:
	Minesweeper();
	Minesweeper(int red, int kolona);
	~Minesweeper();
	inline int vrati_redove() //vraca broj redova polja
	{
		return n;
	}
	inline int vrati_kolone() //vraca broj kolona polja
	{
		return m;
	}
	int brojMinaOkoPolja(int red, int kolona); //broj mina oko polja
	void ucitaj(); //upis polja
	void prikazi(); //ispis polja
	void izbaci(); //izbacuje sve redove i kolone bez mina

};