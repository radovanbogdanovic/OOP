#define _CRT_SECURE_NO_WARNINGS
#include "Naziv.h"

Naziv::Naziv() {
    tekst = new char[1];
    tekst[0] = '\0';
}

Naziv::Naziv(const char* t) {
    tekst = new char[strlen(t) + 1];
    strcpy(tekst, t);
}

Naziv::Naziv(const Naziv& n) {
    tekst = new char[strlen(n.tekst) + 1];
    strcpy(tekst, n.tekst);
}

Naziv::~Naziv() {
    delete[] tekst;
}

Naziv& Naziv::operator=(const Naziv& n) {
    if (this != &n) {
        delete[] tekst;
        tekst = new char[strlen(n.tekst) + 1];
        strcpy(tekst, n.tekst);
    }
    return *this;
}

Naziv Naziv::operator+(const Naziv& n) const {
    char* tmp = new char[strlen(tekst) + strlen(n.tekst) + 1];
    strcpy(tmp, tekst);
    strcat(tmp, n.tekst);

    Naziv rez(tmp);
    delete[] tmp;
    return rez;
}

Naziv Naziv::operator*(const Naziv& n) const {
    return (*this + n);
}

ostream& operator<<(ostream& o, const Naziv& n) {
    o << n.tekst;
    return o;
}

istream& operator>>(istream& i, Naziv& n) {
    char buffer[256];
    i >> buffer;

    delete[] n.tekst;
    n.tekst = new char[strlen(buffer) + 1];
    strcpy(n.tekst, buffer);

    return i;
}

