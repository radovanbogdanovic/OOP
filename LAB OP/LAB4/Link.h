#pragma once
#include "FileSystemElement.h"

class Link : public FileSystemElement
{
private:
    FileSystemElement* target;

public:
    Link(const char* ime, FileSystemElement* t);
    virtual ~Link();

    virtual char* vrati_puno_ime();
    virtual void PrintList();
};
