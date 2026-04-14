#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Naziv {
private:
    char* tekst;

public:
    Naziv();
    Naziv(const char* t);
    Naziv(const Naziv& n);
    ~Naziv();

    Naziv& operator=(const Naziv& n);

    Naziv operator+(const Naziv& n) const;
    Naziv operator*(const Naziv& n) const;

    friend ostream& operator<<(ostream& o, const Naziv& n);
    friend istream& operator>>(istream& i, Naziv& n);
};


