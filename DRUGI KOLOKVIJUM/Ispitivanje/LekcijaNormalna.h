#pragma once
#include <iostream>
using namespace std;
class LekcijaNormalna
{
private:
	char* naziv;
	float duzina, tezina;
public:
	LekcijaNormalna();
	LekcijaNormalna(const char*, float, float);
	LekcijaNormalna(const LekcijaNormalna& le);
	virtual ~LekcijaNormalna();

	float Get() const { return duzina * tezina; }
	LekcijaNormalna& operator=(const LekcijaNormalna& le);
	friend float operator+(float s, const LekcijaNormalna& le) { return s + le.Get(); }
	bool operator>(float vrednost) const { return Get() > vrednost; }
	bool operator>(const LekcijaNormalna& le) const { return Get() > le.Get(); }
	friend int operator+(int s, const LekcijaNormalna& le) { return s + le.Get(); }

	friend ostream& operator<<(ostream& o, const LekcijaNormalna& a);
	friend istream& operator>>(istream& i, LekcijaNormalna& a);

};

