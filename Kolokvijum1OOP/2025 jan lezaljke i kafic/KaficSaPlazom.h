#include <iostream>
#include "Lezaljka.h"
#include "ParLezaljki.h"
#include "ParLezaljkiSaDodatkom.h"
using namespace std;

class KaficSaPlazom {
	Lezaljka** lezaljke;
	int kapacitet;
	int trenutno;
	double naplaceno;
public:
	KaficSaPlazom(int kap = 0) : kapacitet(kap), trenutno(0), naplaceno(0) {
		lezaljke = new Lezaljka* [kapacitet];
		for (int i = 0; i < kapacitet; i++) {
			lezaljke[i] = nullptr;
		}
	}
	~KaficSaPlazom() {
		for (int i = 0; i < trenutno; i++)
			delete lezaljke[i];
		delete[] lezaljke;
	}

	void Dodaj(Lezaljka* l) {
		if (trenutno < kapacitet) {
			lezaljke[trenutno++] = l;
		}
		else {
			cout << "Nema dovoljno mesta za novu lezaljku!";
		}
	}

	void Oslobodi(int redniBroj) { //mora da postoji redniBroj atribut
		for (int i = 0; i < trenutno; i++)
			if (lezaljke[i]->getRedniBroj() == redniBroj) {
				naplaceno += lezaljke[i]->UkupnaCena();
				delete lezaljke[i];
				for (int j = i; j < trenutno - 1; j++) //pomeranje niza lezaljki
					lezaljke[j] = lezaljke[j + 1];
				lezaljke[trenutno - 1] = nullptr;
				trenutno--;
				break;
			}
	}//da nema dela sa pomeranjem ne bismo mogli da vidimo koliko je puno koliko nije 
	//da je npr samo pisalo lezaljke[i] = nullptr

	int UkupnoLezaljki() const { return trenutno; }

	double UkupnaSvotaNovca() const {
		double suma = 0.0;
		for (int i = 0; i < trenutno; i++)
			suma += lezaljke[i]->UkupnaCena();
		return suma;
	}

	bool PostojiGdeTrebaPlatiti(double svota) const {
		for (int i = 0; i < trenutno; i++)
			if (lezaljke[i]->UkupnaCena() > svota)
				return true;
		return false;
	}
	//mora lezaljka** da bi funkcija mogla da vrati dev vr jer t=return radi samo sa jednom
	void VratiNajskuplje(Lezaljka** maxCena, Lezaljka** maxNapitak) const {
		//da se ide kroz niz i da se nadje sa maks cenom i sa maks napitkom i smesti u ova dva parametra
		double najCena = -1, najNap = -1;
		*maxCena = nullptr;
		*maxNapitak = nullptr;

		for (int i = 0; i < trenutno; i++) {
			if (lezaljke[i]->UkupnaCena() > najCena) {
				najCena = lezaljke[i]->UkupnaCena();
				*maxCena = lezaljke[i];
			}
			if (lezaljke[i]->getCenaNapica() > najNap) {
				najNap = lezaljke[i]->getCenaNapica();
				*maxNapitak = lezaljke[i];
			}
		}
	}

	friend ostream& operator<<(ostream& os, const KaficSaPlazom& k) {
		for (int i = 0; i < k.trenutno; i++)
			k.lezaljke[i]->Prikazi();
		os << "Ukupna naplacena svota: " << k.naplaceno << endl;
		return os;
	}

	void print() const {
		cout << *this << endl;
	}
};
