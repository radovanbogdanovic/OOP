#include "DialogWindow.h"

DialogWindow::DialogWindow() : Window("DialogWindow", 0)
{
}

DialogWindow::~DialogWindow()
{
}

void DialogWindow::draw(ostream& izlaz)
{
	izlaz << title << " (Dialog) | state = " << (state ? "OPEN" : "CLOSED") << endl;

}

bool DialogWindow::confirm()
{
	state = 0;
	return 1;
}

bool DialogWindow::cancel()
{
	state = 0;
	return 0;
}

void DialogWindow::read(istream& ulaz)
{
	Window::read(ulaz);
}
