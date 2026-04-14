#define _CRT_SECURE_NO_WARNINGS
#include "FileSystemElement.h"
#include <cstring>

FileSystemElement::FileSystemElement()
{
	ime = nullptr;
	ekstenzija = nullptr;
	roditelj = nullptr;
}

FileSystemElement::FileSystemElement(const char* iime, const char* eekstenzija)
{
	ime = new char[strlen(iime) + 1];
	strcpy(ime, iime);
	ekstenzija = new char[strlen(eekstenzija) + 1];
	strcpy(ekstenzija, eekstenzija);
	roditelj = nullptr;
}

FileSystemElement::~FileSystemElement()
{
	if (ime != nullptr)
	{
		delete[] ime;
		ime = nullptr;
	}
	if (ekstenzija != nullptr)
	{
		delete[] ekstenzija;
		ekstenzija = nullptr;
	}
}

void FileSystemElement::postavi_roditeljski_element(FileSystemElement* rroditelj)
{
	roditelj = rroditelj;
}

