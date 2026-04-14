#pragma once
#include <iostream>
using namespace std;

class IspitniMaterijal {
protected:
	int oznaka;
	float tezina;
	bool savladan;
public:
	IspitniMaterijal(int o, float t);
	
	int GetOznaka() const { return oznaka; }
	void Savladano() { savladan = true; }
	bool GetSavladan() const { return savladan; }
	virtual float Vreme() const { return 1; }
	virtual const char* GetNaziv() { return "Ispit"; }

	virtual void print(ostream& os) const;
	friend ostream& operator<<(ostream& os, IspitniMaterijal& i);
};
