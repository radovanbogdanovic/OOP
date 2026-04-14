#pragma once
#include "Window.h"

class DocumentWindow : public Window
{
public:
	DocumentWindow();
	virtual ~DocumentWindow();

	virtual void draw(ostream& izlaz);
	virtual void read(istream& ulaz);
};

