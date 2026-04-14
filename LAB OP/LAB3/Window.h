#pragma once
#include <iostream>
using namespace std;
class Window
{
protected:
	string title;
	bool state;
public:
	Window();
	Window(string ttitle, bool sstate);
	virtual ~Window();
	virtual void draw(ostream& izlaz);

	virtual void read(istream& ulaz);

	void close();
	void open();

	string getTitle() const { return title; }
	void setTitle(const string& t) { title = t; }
};

