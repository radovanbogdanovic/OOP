#pragma once
#include <iostream>
using namespace std;

class Akvarijum
{
protected:
	char* tip_vode;
	bool poklopac;
public:
	Akvarijum();
	Akvarijum(const char* tip_vode, bool poklopac);
	virtual ~Akvarijum();
	Akvarijum(const Akvarijum& a);

	virtual void print(ostream& o) const;
	virtual double koeficijent() const = 0;
	virtual double povrsina() const = 0;
	virtual double zapremina() const = 0;

	friend ostream& operator<<(ostream& o, const Akvarijum& a);

	const char* getTip() const { return tip_vode; }
};

