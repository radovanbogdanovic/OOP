#pragma once
#include <iostream>
using namespace std;
class Complex
{
private:
	double realni;
	double imag;
public:
	Complex();
	Complex(double, double);
	virtual ~Complex();

	Complex operator+(const Complex& drugi) const;
	Complex operator*(const Complex& drugi) const;
	Complex& operator=(const Complex& drugi);


	friend ostream& operator<<(ostream& o, const Complex& c);
	friend istream& operator>>(istream& o, Complex& c);

};


