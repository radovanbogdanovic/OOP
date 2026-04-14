#pragma once
#include <cstring>

class FileSystemElement
{
protected:
    char* ime;
    char* ekstenzija;
    FileSystemElement* roditelj;

public:
    FileSystemElement();
    FileSystemElement(const char* iime,const char* eekstenzija);
    virtual ~FileSystemElement();

    void postavi_roditeljski_element(FileSystemElement* rroditelj);
    virtual char* vrati_puno_ime() = 0;
    virtual void PrintList() = 0;
};