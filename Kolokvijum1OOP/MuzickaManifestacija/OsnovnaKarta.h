#pragma once
#include <iostream>
using namespace std;

class OsnovnaKarta
{
private:
	char* oznaka;
	char sektor;
	int cena;

protected:
	void IspisiOsnovno(ostream& o) const;

public:
	OsnovnaKarta();
	OsnovnaKarta(const char* ooznaka, char ssektor, int ccena);
	OsnovnaKarta(const OsnovnaKarta& ok);
	virtual ~OsnovnaKarta();

	OsnovnaKarta& operator=(const OsnovnaKarta& ok);

	char GetSektor() const { return sektor; }
	int GetCena() const { return cena; }
	char* GetOznaka() const { return oznaka; }

	virtual float UkupnaCena() const;
	virtual float ZaradaZaDan(int dan, const float* ucesceDana) const = 0;
	virtual OsnovnaKarta* clone() const = 0;
	virtual void Ispisi(ostream& o) const;

	friend ostream& operator<<(ostream& o, const OsnovnaKarta& ok);
};
