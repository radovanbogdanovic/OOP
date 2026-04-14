#pragma once
#include "FileSystemElement.h"


class File : public FileSystemElement
{
public:
    File();
    File(const char* ime, const char* ekstenzija);
    virtual ~File();
    virtual char* vrati_puno_ime();
    virtual void PrintList();
};

