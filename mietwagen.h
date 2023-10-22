#ifndef MIETWAGEN_H
#define MIETWAGEN_H

#include <vector>
#include "fahrt.h"
#include <iostream>
using namespace std;


class Mietwagen
{
public:
    Mietwagen();
    void anmieten(Fahrt f);
    void fahrtAnzeigen(int nummer);
    void alleFahrtenAnzeigen();
    bool nummerPruefen(int nummer);
    bool fahrtLoeschen(int nummer);
    bool verfuegbarkeitPruefen(Fahrt f);
    void fahrzeugAnzeigen();
    int berechneTage(int datum);
    void umsatzAnzeigen();

    static double getGesamtUmsatz();

private:
    string marke;
    string kennzeichen;
    int sitze;
    double tagessatz;
    double umsatz = 0;
    inline static double gesamtUmsatz = 0;

    vector <Fahrt> fahrtenbuch;
};

#endif // MIETWAGEN_H
