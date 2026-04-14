#pragma once
#include <iostream>
using namespace std;

template <typename T, int N>
class Polinom
{
private:
	T koef[N + 1];

public:
	Polinom() {
	
		for (int i = 0; i <= N; i++)
			koef[i] = T();
	
	}

	void ucitaj()
	{
		for (int i = 0; i <= N; i++)
			cin >> koef[i];
	}
	
	T IzracunajPolinom(T x)
	{
		// Hornerova šema za izraèunavanje
		T rezultat = koef[N];

		for (int i = N - 1; i >= 0; --i) {
			rezultat = rezultat * x + koef[i];
		}
		return rezultat;
	}


};

