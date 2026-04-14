#include <iostream>
#include "ParLezaljki.h"
#include "ParLezaljkiSaDodatkom.h"
#include "KaficSaPlazom.h"

using namespace std;

void zadatak1() {
    // 2 poena
    int pL[] = { 12, 1, 40, 20 };
    ParLezaljki* p1 = new ParLezaljki(pL[0], pL[1], pL[2], pL[3]);
    // prikaz preko metode Prikazi()
    // p1->Prikazi();
    cout << *p1 << endl;  // preko operator<<

    // 2 poena
    int pLD[] = { 21, 2, 30, 10, 1 };
    ParLezaljkiSaDodatkom* p2 = new ParLezaljkiSaDodatkom(pLD[0], pLD[1], pLD[2], pLD[3], pLD[4]);
    // p2->Prikazi();
    cout << *p2 << endl;

    int rbr[] = { 12, 15, 18, 23, 27, 31, 34, 37 };
    int red[] = { 1, 1, 1, 2, 2, 3, 3, 3 };
    int cena[] = { 40, 40, 40, 30, 30, 20, 20, 20 };
    int napici[] = { 20, 40, 30, 30, 70, 20, 30, 10 };
    int dodatno[] = { 1, 2 };

    // Kafic sa kapacitetom 10
    KaficSaPlazom* pKSP = new KaficSaPlazom(10);

    // 2 poena: dodavanje lezaljki
    for (int i = 0; i < 4; i++) {
        pKSP->Dodaj(new ParLezaljki(rbr[i], red[i], cena[i], napici[i]));
        pKSP->Dodaj(new ParLezaljkiSaDodatkom(rbr[i], red[i], cena[i], napici[i], dodatno[i % 2]));
    }

    // 2 poena: prikaz kafica
    // pKSP->print();
    cout << *pKSP << endl;

    // 2 poena: oslobadjanje lezaljke
    int oznaka = 34;
    pKSP->Oslobodi(oznaka);
    // pKSP->print();
    cout << *pKSP << endl;

    // 2 poena: ukupno trenuto iznajmljenih lezaljki
    cout << "Ukupno lezaljki: " << pKSP->UkupnoLezaljki() << endl;

    // 2 poena: ukupna svota novca
    cout << "Ukupna svota novca: " << pKSP->UkupnaSvotaNovca() << endl;

    // 2 poena: da li postoji lezaljka koja prelazi zadatu svotu
    int svota = 5000;
    if (pKSP->PostojiGdeTrebaPlatiti(svota))
        cout << "Postoje lezaljke gde treba platiti vise od " << svota << endl;
    else
        cout << "Ne postoje lezaljke gde treba platiti vise od " << svota << endl;

    // 3 poena: pronalazak najskupljih lezaljki
    Lezaljka* pLezMaxCena = nullptr;
    Lezaljka* pLezMaxNapitak = nullptr;
    pKSP->VratiNajskuplje(&pLezMaxCena, &pLezMaxNapitak);
    if (pLezMaxCena) pLezMaxCena->Prikazi();
    if (pLezMaxNapitak) pLezMaxNapitak->Prikazi();

    // 1 poen: ciscenje
    delete pKSP;
    delete p1;
    delete p2;
}

int main() {
    zadatak1();
    return 0;
}
