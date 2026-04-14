#define _CRT_SECURE_NO_WARNINGS
#include "Folder.h"
#include "File.h"
#include "Link.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ulaz("input.txt");
    if (!ulaz.is_open()) {
        cout << "Greska pri otvaranju fajla!" << endl;
        return 1;
    }

    char ime[50];
    ulaz >> ime;

    Folder* root = new Folder(ime);

    int brojFoldera;
    ulaz >> brojFoldera;

    Folder** folderi = new Folder * [brojFoldera];

    for (int i = 0; i < brojFoldera; i++) {
        ulaz >> ime;
        folderi[i] = new Folder(ime);
        root->dodajPodelement(folderi[i]);
    }

    File* prviFajl = nullptr;

    for (int i = 0; i < brojFoldera; i++) {
        int brojFajlova;
        ulaz >> brojFajlova;

        for (int j = 0; j < brojFajlova; j++) {
            char imeFajla[50], ekstenzija[10];
            ulaz >> imeFajla >> ekstenzija;

            File* f = new File(imeFajla, ekstenzija);
            folderi[i]->dodajPodelement(f);

            if (prviFajl == nullptr)
                prviFajl = f; // zapamtimo fajl za link
        }
    }

    // Ucitavanje linka
    char imeLinka[50];
    ulaz >> imeLinka;

    Link* link = new Link(imeLinka, prviFajl);
    root->dodajPodelement(link);

    // Test vrati_puno_ime
    char* punoIme = link->vrati_puno_ime();
    cout << "\nPuno ime linka: " << punoIme << endl;
    delete[] punoIme;

    // Test PrintList
    cout << "\nPrintList root-a:" << endl;
    root->PrintList();

    cout << "\nPrintList linka:" << endl;
    link->PrintList();

    // Ciscenje memorije
    delete root;   // pod uslovom da Folder destruktor brise podelemente
    delete[] folderi;

    ulaz.close();
    return 0;
}
