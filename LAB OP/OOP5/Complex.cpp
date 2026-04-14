#include "Complex.h"

Complex::Complex() :realni(), imag()
{
}

Complex::Complex(double r, double i) : realni(r), imag(i)
{
}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex& drugi) const
{
	Complex rez = Complex();

	rez.imag = this->imag + drugi.imag;
	rez.realni = this->realni + drugi.realni;


	return rez;
}

Complex Complex::operator*(const Complex& drugi) const
{

	Complex rez = Complex();

	rez.imag = this->realni * drugi.imag + this->imag * drugi.realni;
	rez.realni = this->realni * drugi.realni - this->imag * drugi.imag;


	return rez;
}

Complex& Complex::operator=(const Complex& drugi)
{
	if (this != &drugi)
	{
		realni = drugi.realni;
		imag = drugi.imag;

	}
	return *this;
}

ostream& operator<<(ostream& o, const Complex& c)
{
	o << c.realni << " + i" << c.imag << endl;
	return o;
}

istream& operator>>(istream& o,Complex& c)
{
	o >> c.realni >> c.imag;
	return o;
}
