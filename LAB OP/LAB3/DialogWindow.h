#pragma once
#include "Window.h"
class DialogWindow : public Window
{
public:
	DialogWindow();
	virtual ~DialogWindow();

	virtual void draw(ostream& izlaz);
	virtual void read(istream& ulaz);

	bool confirm();
	bool cancel();

};

