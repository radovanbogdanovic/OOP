#include "Manifestacija.h"

Manifestacija::Manifestacija() : niz(nullptr), n(0), tren(0), brSektora(0), sektori(nullptr), brDana(0), ucesceDana(nullptr)
{
}

Manifestacija::Manifestacija(int nn) : niz(nullptr), n(nn), tren(0), brSektora(0), sektori(nullptr), brDana(0), ucesceDana(nullptr)
{
	char s[] = { 'A', 'B', 'C' };
	float u[] = { 20, 20, 20, 20, 20 };

	niz = new OsnovnaKarta * [n] {};
	PostaviSektore(3, s);
	PostaviDane(5, u);
}

Manifestacija::Manifestacija(int nn, int bbrSektora, const char* ssektori, int bbrDana, const float* uucesceDana)
	: niz(nullptr), n(nn), tren(0), brSektora(0), sektori(nullptr), brDana(0), ucesceDana(nullptr)
{
	niz = new OsnovnaKarta * [n] {};
	PostaviSektore(bbrSektora, ssektori);
	PostaviDane(bbrDana, uucesceDana);
}

Manifestacija::Manifestacija(const Manifestacija& m) : niz(nullptr), n(0), tren(0), brSektora(0), sektori(nullptr), brDana(0), ucesceDana(nullptr)
{
	Kopiraj(m);
}

Manifestacija::~Manifestacija()
{
	Oslobodi();
}

Manifestacija& Manifestacija::operator=(const Manifestacija& m)
{
	if (this != &m)
	{
		Oslobodi();
		Kopiraj(m);
	}

	return *this;
}

void Manifestacija::Oslobodi()
{
	for (int i = 0; i < tren; i++)
		if (niz[i] != nullptr)
			delete niz[i];

	if (niz != nullptr)
		delete[] niz;

	if (sektori != nullptr)
		delete[] sektori;

	if (ucesceDana != nullptr)
		delete[] ucesceDana;

	niz = nullptr;
	sektori = nullptr;
	ucesceDana = nullptr;
	n = 0;
	tren = 0;
	brSektora = 0;
	brDana = 0;
}

void Manifestacija::Kopiraj(const Manifestacija& m)
{
	n = m.n;
	tren = m.tren;
	niz = new OsnovnaKarta * [n] {};

	for (int i = 0; i < tren; i++)
		if (m.niz[i] != nullptr)
			niz[i] = m.niz[i]->clone();

	PostaviSektore(m.brSektora, m.sektori);
	PostaviDane(m.brDana, m.ucesceDana);
}

void Manifestacija::PostaviSektore(int bbrSektora, const char* ssektori)
{
	if (sektori != nullptr)
		delete[] sektori;

	brSektora = bbrSektora;
	sektori = new char[brSektora];

	for (int i = 0; i < brSektora; i++)
		sektori[i] = ssektori[i];
}

void Manifestacija::PostaviDane(int bbrDana, const float* uucesceDana)
{
	if (ucesceDana != nullptr)
		delete[] ucesceDana;

	brDana = bbrDana;
	ucesceDana = new float[brDana];

	for (int i = 0; i < brDana; i++)
		ucesceDana[i] = uucesceDana[i];
}

int Manifestacija::IndeksSektora(char sektor) const
{
	for (int i = 0; i < brSektora; i++)
		if (sektori[i] == sektor)
			return i;

	return -1;
}

void Manifestacija::Dodaj(OsnovnaKarta* karta)
{
	if (karta == nullptr)
		return;

	if (tren < n)
		niz[tren++] = karta;
	else
		delete karta;
}

void Manifestacija::VratiKarte(int indeks, int broj)
{
	if (indeks < 0 || indeks >= tren || broj <= 0)
		return;

	if (indeks + broj > tren)
		broj = tren - indeks;

	for (int i = indeks; i < indeks + broj; i++)
	{
		delete niz[i];
		niz[i] = nullptr;
	}

	for (int i = indeks; i < tren - broj; i++)
		niz[i] = niz[i + broj];

	for (int i = tren - broj; i < tren; i++)
		niz[i] = nullptr;

	tren = tren - broj;
}

float Manifestacija::UkupnaZarada() const
{
	float rez = 0;

	for (int i = 0; i < tren; i++)
		rez += niz[i]->UkupnaCena();

	return rez;
}

char Manifestacija::SektorSaNajviseKarata() const
{
	if (brSektora == 0)
		return ' ';

	int* brojac = new int[brSektora] {};

	for (int i = 0; i < tren; i++)
	{
		int ind = IndeksSektora(niz[i]->GetSektor());
		if (ind != -1)
			brojac[ind]++;
	}

	int max = 0;
	for (int i = 1; i < brSektora; i++)
		if (brojac[i] > brojac[max])
			max = i;

	char rez = sektori[max];
	delete[] brojac;

	return rez;
}

int Manifestacija::DanSaNajvecomZaradom(int& zarada) const
{
	if (brDana == 0)
	{
		zarada = 0;
		return 0;
	}

	float* zarade = new float[brDana] {};

	for (int i = 0; i < tren; i++)
		for (int j = 0; j < brDana; j++)
			zarade[j] += niz[i]->ZaradaZaDan(j + 1, ucesceDana);

	int max = 0;
	for (int i = 1; i < brDana; i++)
		if (zarade[i] > zarade[max])
			max = i;

	zarada = (int)zarade[max];

	delete[] zarade;
	return max + 1;
}

void Manifestacija::NajskupljeKarte(OsnovnaKarta** max, OsnovnaKarta** afterMax) const
{
	*max = nullptr;
	*afterMax = nullptr;

	for (int i = 0; i < tren; i++)
	{
		if (*max == nullptr || niz[i]->UkupnaCena() > (*max)->UkupnaCena())
		{
			*afterMax = *max;
			*max = niz[i];
		}
		else if (*afterMax == nullptr || niz[i]->UkupnaCena() > (*afterMax)->UkupnaCena())
		{
			*afterMax = niz[i];
		}
	}
}

ostream& operator<<(ostream& o, const Manifestacija& m)
{
	for (int i = 0; i < m.tren; i++)
		o << i << ". " << *m.niz[i] << endl;

	return o;
}
