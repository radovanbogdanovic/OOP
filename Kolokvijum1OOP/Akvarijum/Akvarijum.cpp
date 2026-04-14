#define _CRT_SECURE_NO_WARNINGS
#include "Akvarijum.h"
#include <cstring>  // za strlen i strcpy

Akvarijum::Akvarijum() : tip_vode(nullptr), poklopac(false)
{
}

Akvarijum::Akvarijum(const char* tip, bool p) :  poklopac(p)
{
	tip_vode = new char[strlen(tip) + 1];
	strcpy(tip_vode, tip);
}

Akvarijum::~Akvarijum()
{
	delete[] tip_vode; tip_vode = 0;
}

Akvarijum::Akvarijum(const Akvarijum& a)
{
	if (a.tip_vode != 0)
	{
		tip_vode = new char[strlen(a.tip_vode) + 1];
		strcpy(tip_vode, a.tip_vode);
	}

	poklopac = a.poklopac;
}

void Akvarijum::print(ostream& o) const
{
	o << "Tip vode je: " << tip_vode << ", " << "I akvarijum " << (poklopac ? "ima poklopac" : "nema poklopac") << endl;
}

ostream& operator<<(ostream& o, const Akvarijum& a)
{
	a.print(o);
	return o;
}
