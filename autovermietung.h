#ifndef AUTOVERMIETUNG_H
#define AUTOVERMIETUNG_H

#include <vector>
#include <iostream>
#include "mietwagen.h"

using namespace std;


class Autovermietung
{
public:
    Autovermietung();
    ~Autovermietung();
    void dialog();
    int mietwagenSuchen();

private:
    vector <Mietwagen*> fahrzeuge;
};

#endif // AUTOVERMIETUNG_H
