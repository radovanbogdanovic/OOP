#pragma once
#include <iostream>
using namespace std;
class ProsireniPodatak
{
private:
	float temp, vlaz, brzina;
public:
	ProsireniPodatak();
	ProsireniPodatak(float, float, float);
	virtual ~ProsireniPodatak();

	//TS=T+0.33?E–0.7?V–4.0.

	float TS() const { return temp + 0.33 * vlaz - 0.7 * brzina - 4.0; }

	ProsireniPodatak& operator=(const ProsireniPodatak& pp);

	friend float operator+(float s, const ProsireniPodatak& pp) { return s + pp.TS(); };

	bool operator<(const ProsireniPodatak& pp) const { return TS() < pp.TS(); }



	friend ostream& operator<<(ostream& o, const ProsireniPodatak& pp);
	friend istream& operator>>(istream& i, ProsireniPodatak& pp);
};

