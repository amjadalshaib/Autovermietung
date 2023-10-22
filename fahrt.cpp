#include "fahrt.h"
#include <iostream>

Fahrt::Fahrt(int n, string k, int ab, int bis):
    nummer(n), kunde(k), abholdatum(ab), abgabedatum(bis)
{

}

void Fahrt::anzeigen()
{
    cout << "Nr. " << nummer << ": Kunde " << setw(15) << kunde << " von " << abholdatum << " bis "
         << abgabedatum << " fuer " << fixed << setprecision(2) << mietkosten << " Euro" << endl;
}

int Fahrt::getNummer(){
    return nummer;
}

int Fahrt::getAbholdatum() const
{
    return abholdatum;
}

int Fahrt::getAbgabedatum() const
{
    return abgabedatum;
}

void Fahrt::setMietkosten(double newMietkosten)
{
    mietkosten = newMietkosten;
}
