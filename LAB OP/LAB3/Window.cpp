#include "Window.h"
#include "DialogWindow.h"

Window::Window()
{
	title = "Window";
	state = 0;

}

Window::Window(string ttitle, bool sstate)
{
	title = ttitle;
	state = sstate;
}

Window::~Window()
{
}


void Window::draw(ostream& izlaz)
{
	izlaz << title << " | state = " << (state ? "OPEN" : "CLOSED") << endl;
}

void Window::open()
{
	state = 1;
}

void Window::close()
{
	state = 0;
}
void Window::read(istream& ulaz)
{
	ulaz >> title >> state;
}