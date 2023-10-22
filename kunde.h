#ifndef KUNDE_H
#define KUNDE_H

#include <iostream>
using namespace std;

class Kunde
{
public:
    Kunde(int kNummer, string vName, string nName);
    void anzeigen();

private:
    int kundenNummer;
    string vorname;
    string nachname;
};

#endif // KUNDE_H
