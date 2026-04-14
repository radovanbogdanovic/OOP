#pragma once
#include "FileSystemElement.h"

class Folder : public FileSystemElement
{
private:

    FileSystemElement* podElementi[2018];
public:
    Folder(const char* ime);
    virtual ~Folder();

    void dodajPodelement(FileSystemElement* element);
    void ukloniPodelement(int indeks);

    virtual char* vrati_puno_ime();
    virtual void PrintList();

    FileSystemElement* getPodelement(int indeks) const {
        if (indeks < 0 || indeks >= 2018) return nullptr;
        return podElementi[indeks];
    }

    int getBrojElemenata() const {
        int brojac = 0;
        for (int i = 0; i < 2018; i++)
            if (podElementi[i] != nullptr) brojac++;
            else break; // prvi nullptr znaèi kraj
        return brojac;
    }
};

