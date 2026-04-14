#pragma once
#include "Greske.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Ispit {
private:
    char* naziv;
    int ocena;
    int espb;

public:
    Ispit();
    Ispit(const char* n, int o, int e);
    Ispit(const Ispit& i);
    virtual ~Ispit();

    Ispit& operator=(const Ispit& i);
    friend float operator+(float s, const Ispit& is) { return s + (float)is.ocena; }
    //Ispit operator+(const Ispit& i) const { return Ispit("", ocena + i.ocena, 0); };

    bool operator>(const Ispit& i) const { return espb > i.espb; };

    friend ostream& operator<<(ostream& o, const Ispit& i);
    friend istream& operator>>(istream& ii, Ispit& i);

    //operator float() const { return (float)ocena; }

};
