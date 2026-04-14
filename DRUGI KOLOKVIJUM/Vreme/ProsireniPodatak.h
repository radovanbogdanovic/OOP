#pragma once
#include <iostream>
using namespace std;

class ProsireniPodatak
{
private:
	float t, e, v;

public:
	ProsireniPodatak();
	ProsireniPodatak(float ff, float ee, float vv);
	virtual ~ProsireniPodatak();

	
	ProsireniPodatak& operator=(const ProsireniPodatak& pp);

	friend float operator+(float rez, const ProsireniPodatak& pp);

	bool operator<(const ProsireniPodatak& pp) const;

	friend ostream& operator<<(ostream& o, const ProsireniPodatak& pp);

	friend istream& operator>>(istream& i, ProsireniPodatak& pp);


};

