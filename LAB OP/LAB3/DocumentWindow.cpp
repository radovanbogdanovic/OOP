#include "DocumentWindow.h"

DocumentWindow::DocumentWindow(): Window("DocumentWidnow", 0)
{
}

DocumentWindow::~DocumentWindow()
{
}

void DocumentWindow::draw(ostream& izlaz)
{
	izlaz << title << " (Document) | state = " << (state ? "OPEN" : "CLOSED") << endl;
}

void DocumentWindow::read(istream& ulaz)
{
	Window::read(ulaz);
}