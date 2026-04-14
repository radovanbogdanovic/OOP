#pragma once
#include <iostream>
using namespace std;

class Ispit {
	char* naziv;
	int ocena;
	int espb;
public:
	Ispit();
	Ispit(const char* n, int o, int e);
	~Ispit();
	Ispit(const Ispit& other);  //obavezni cK i = jer ima u Dodaj njehov poziv
	Ispit& operator=(const Ispit& other);

	int GetOcena() const { return ocena; }
	int GetEspb() const { return espb; }

	//operatori << >>
	friend ostream& operator<<(ostream& os, const Ispit& i);
	friend istream& operator>>(istream& is, Ispit& i);
};