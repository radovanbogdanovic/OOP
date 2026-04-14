#define _CRT_SECURE_NO_WARNINGS
#include "Link.h"
#include <cstring>
#include <iostream>

using namespace std;

Link::Link(const char* ime, FileSystemElement* t)
    : FileSystemElement(ime, "lnk"), target(t)
{
}

Link::~Link()
{
    // link ne briše target
}

char* Link::vrati_puno_ime()
{
    if (roditelj == nullptr)
    {
        char* rez = new char[strlen(ime) + 1 + strlen(ekstenzija) + 1];
        strcpy(rez, ime);
        strcat(rez, ".");
        strcat(rez, ekstenzija);
        return rez;
    }

    char* imeRoditelja = roditelj->vrati_puno_ime();

    int duzina = strlen(imeRoditelja) + 1 + strlen(ime) + 1 + strlen(ekstenzija) + 1;
    char* rez = new char[duzina];

    strcpy(rez, imeRoditelja);
    strcat(rez, "/");
    strcat(rez, ime);
    strcat(rez, ".");
    strcat(rez, ekstenzija);

    delete[] imeRoditelja;
    return rez;
}

void Link::PrintList()
{
    cout << "Link -> ";
    if (target != nullptr)
    {
        char* ime = target->vrati_puno_ime();
        cout << ime << endl;
        delete[] ime;
    }
    else
        cout << "null" << endl;
}