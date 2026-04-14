#define _CRT_SECURE_NO_WARNINGS
#include "Folder.h"
#include <cstring>
#include <iostream>

using namespace std;

Folder::Folder(const char* ime) : FileSystemElement(ime,"")
{
	for (int i = 0; i < 2018; i++)
		podElementi[i] = nullptr;
}

Folder::~Folder()
{
	for (int i = 0; i < 2018; i++)
	{
		if (podElementi[i] != nullptr)
			delete podElementi[i];
	}
}

void Folder::dodajPodelement(FileSystemElement* element)
{
	if (element == nullptr) return;

	int i = 0;
	while (i < 2018 && podElementi[i] != nullptr)
		i++;

	if (i == 2018) return;

	podElementi[i] = element;
	element->postavi_roditeljski_element(this);
}

void Folder::ukloniPodelement(int indeks)
{
	if (indeks < 0 || indeks >= 2018)
		return;

	if (podElementi[indeks] != nullptr)
	{
		podElementi[indeks]->postavi_roditeljski_element(nullptr);
		podElementi[indeks] = nullptr;
	}
}

char* Folder::vrati_puno_ime()
{
	if (roditelj == nullptr)
	{
		char* rez = new char[strlen(ime) + 1];
		strcpy(rez, ime);
		return rez;
	}

	char* imeRoditelja = roditelj->vrati_puno_ime();

	// dužina: roditelj + '/' + ime + '\0'
	int duzina = strlen(imeRoditelja) + 1 + strlen(ime) + 1;
	char* rezultat = new char[duzina];

	strcpy(rezultat, imeRoditelja);
	strcat(rezultat, "/");
	strcat(rezultat, ime);

	delete[] imeRoditelja;
	return rezultat;
}

void Folder::PrintList()
{
	for (int i = 0; i < 2018; i++)
	{
		if (podElementi[i] != nullptr)
		{
			char* ime = podElementi[i]->vrati_puno_ime();
			cout << ime << endl;
			delete[] ime;

			// rekurzija SAMO za foldere
			Folder* f = dynamic_cast<Folder*>(podElementi[i]);
			if (f)
				f->PrintList();
		}
	}
}

