#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include "Folder.h"
#include <cstring>
#include <iostream>
using namespace std;


File::File() :FileSystemElement() 
{ 
}

File::File(const char* iime, const char* eekstenzija) : FileSystemElement(iime, eekstenzija)
{
}

File::~File()
{
}

char* File::vrati_puno_ime()
{
	if (roditelj == nullptr)
	{
		int duzina = strlen(ime) + 1 + strlen(ekstenzija) + 1; // ime + '.' + ekstenzija + '\0'
		char* rez = new char[duzina];
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

void File::PrintList()
{
	if (roditelj == nullptr) return;

	Folder* parent = dynamic_cast<Folder*>(roditelj);
	if (!parent) return;

	for (int i = 0; i < 2018; i++)
	{
		FileSystemElement* el = parent->getPodelement(i);
		if (!el) continue;

		File* f = dynamic_cast<File*>(el);
		if (f)
		{
			char* ime = f->vrati_puno_ime();
			cout << ime << endl;
			delete[] ime;
		}
	}
}
