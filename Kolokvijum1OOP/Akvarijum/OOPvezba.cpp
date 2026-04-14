#include <iostream> 
#include "Akvarijum.h"

#include "Police.h"
#include "Kvadar.h"
#include "Valjak.h"
using namespace std;

void main()
{
	const char* tip_akvarijuma[] = { "akvarijum slatke vode", "akvarijum slane vode", "bez vode - terarijum" };

	// 2 poena 
	Akvarijum* p1 = new Valjak(5.0, 10.1, tip_akvarijuma[0], false);
	//p1.print(); 
	//cout << *p1 << endl;

	// 2 poena 
	Akvarijum* p2 = new Kvadar(200, 40, 55, tip_akvarijuma[1], true);
	//p2.print(); 
	//cout << *p2 << endl;

	Polica p(4);
	Polica* pp = new Polica(4);

	// 2 poena 
	for (int i = 0; i < p.BrojAkvarijuma() / 2; i++)
	{
		p.Add(new Valjak(100 + i * 5, i * 3, tip_akvarijuma[(2 * i) % 3], i % 2));
		p.Add(new Kvadar(1000 + i * 20.37, (i + 1) * i, i * 3, tip_akvarijuma[(2 * i + 1) % 3], (i + 1) % 2));
	}
	for (int i = 0; i < pp->BrojAkvarijuma() / 2; i++)
	{
		pp->Add(new Valjak(100 + i * 5, i * 3, tip_akvarijuma[(2 * i) % 3], i % 2));
		pp->Add(new Kvadar(1000 + i * 20.37, (i + 1) * i, i * 3, tip_akvarijuma[(2 * i + 1) % 3], (i + 1) % 2));
	}

	// 2 poena 
	//p.print(); 
	//cout << p << endl;

	// 2 poena 
	delete pp;

	
	//cout << p.UkupnaPovrsinaStakla() << endl;
	
	//cout << p.UkupnaZapremina() << endl;

	 
	Polica* ppp = p.PrebacitiAkvarijume(tip_akvarijuma[2]);
	//ppp->print(); 
	cout << *ppp << endl;

	 
	Akvarijum* pmin = nullptr;
	int ind;
	p.Min(&ind, &pmin);
	cout << ind << "/n " << *pmin << endl;
}