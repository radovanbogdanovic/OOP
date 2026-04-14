#define _CRT_SECURE_NO_WARNINGS
#include "Ispit.h"
#include <cstring>

Ispit::Ispit()
{
	naziv = nullptr;
	ocena = 0;
	espb = 0;
}

Ispit::Ispit(const char* n, int o, int e) : ocena(o), espb(e)
{
	naziv = new char[strlen(n) + 1];
	strcpy(naziv, n);
}

Ispit::~Ispit()
{
	delete[] naziv;
}

Ispit::Ispit(const Ispit& other) : ocena(other.ocena), espb(other.espb) {
	if (other.naziv) {
		naziv = new char[strlen(other.naziv) + 1];
		strcpy(naziv, other.naziv);
	}
	else {
		naziv = nullptr;
	}
}

Ispit& Ispit::operator=(const Ispit& other) {
	if (this != &other) {
		delete[] naziv;

		ocena = other.ocena;
		espb = other.espb;

		if (other.naziv) {
			naziv = new char[strlen(other.naziv) + 1];
			strcpy(naziv, other.naziv);
		}
		else {
			naziv = nullptr;
		}
	}
	return *this;
}

ostream& operator<<(ostream& os, const Ispit& i)
{
	os << i.naziv << " "
		<< i.ocena << " "
		<< i.espb << endl;
	return os;
	// TODO: insert return statement here
}

istream& operator>>(istream& is, Ispit& i)
{
	char temp[100];
	is >> temp >> i.ocena >> i.espb;
	delete[] i.naziv;
	i.naziv = new char[strlen(temp) + 1];
	strcpy(i.naziv, temp);
	return is;
	// TODO: insert return statement here
}
