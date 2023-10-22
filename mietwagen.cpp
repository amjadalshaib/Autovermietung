#include "mietwagen.h"


Mietwagen::Mietwagen()
{
    cout << "Neues Fahrzeug " << endl;
    cout << "Automarke? ";
    cin >> marke;
    cout << "KFZ-Kennzeichen? ";
    cin >> kennzeichen;
    cout << "Sitze? ";
    cin >> sitze;
    cout << "Tagessatz? ";
    cin >> tagessatz;

    cout << " --> Fahrzeug " << marke << " mit KFZ-Kennzeichen " << kennzeichen << " und " << sitze
         << " Sitzen zum Tagessatz " << fixed << setprecision(2) << tagessatz << " Euro wurde aufgenommen" << endl << endl;
}

void Mietwagen::anmieten(Fahrt f){
    if(verfuegbarkeitPruefen(f)){
        int leihdauer = berechneTage(f.getAbgabedatum()) - berechneTage(f.getAbholdatum() - 1);
        double miete = leihdauer * tagessatz;
        f.setMietkosten(miete);
        fahrtenbuch.push_back(f);
        umsatz += miete;   ///////////////////////////////////////////////////////////
        cout << "Fahrt " << f.getNummer() << " erfolgreich angelegt" << endl;
    }
    else
        cout << "Buchung wegen Ueberschneidung nicht erfolgt!" << endl;
}

void Mietwagen::fahrtAnzeigen(int nummer){
    bool found = false;
    for (unsigned int i = 0; i < fahrtenbuch.size(); i++){
        if(fahrtenbuch[i].getNummer() == nummer){
            fahrtenbuch[i].anzeigen();
            found = true;
            break;
        }
    }
    if (found == false)
        cout << "Buchung existiert nicht" << endl;
}

void Mietwagen::alleFahrtenAnzeigen(){
    if (fahrtenbuch.size()==0){
        cout << "Mietwagen wurde noch nicht verliehen" << endl;
    }
    else
        for(unsigned int i = 0; i < fahrtenbuch.size(); i++){
            fahrtenbuch[i].anzeigen();
            cout << "----------------------------------------" << endl;
        }
}

bool Mietwagen::nummerPruefen(int nummer){
    for (unsigned int i = 0; i < fahrtenbuch.size(); i++){
        if(fahrtenbuch[i].getNummer() == nummer){
            cout << "Buchungsnummer " << nummer
                 << " ist schon vergeben, bitte neu eingeben!" << endl;
            return false;
            break;
        }
    }
    return true;
}

bool Mietwagen::fahrtLoeschen(int nummer){
    for (unsigned int i = 0; i < fahrtenbuch.size(); i++){
        if(fahrtenbuch[i].getNummer() == nummer){
            fahrtenbuch.erase(fahrtenbuch.begin()+i);
            return true;
            break;
        }
    }
    return false;
}

bool Mietwagen::verfuegbarkeitPruefen(Fahrt f){
    for (unsigned int i = 0; i < fahrtenbuch.size(); i++){

        // neueAbgabe >= vorhandeneAbholung UND neueAbgabe <= vorhandenAbgabe
        if(f.getAbgabedatum() >= fahrtenbuch[i].getAbholdatum() &&
                f.getAbgabedatum() <= fahrtenbuch[i].getAbgabedatum()){
            return false;
            break;
        }

        // neueAbholung >= vorhandeneAbholung UND neueAbholung <= vorhandenAbgabe
        if(f.getAbholdatum() >= fahrtenbuch[i].getAbholdatum() &&
                f.getAbholdatum() <= fahrtenbuch[i].getAbgabedatum()){
            return false;
            break;
        }

        // neueAbholung <= vorhandeneAbholung UND neueAbgabe >= vorhandenAbgabe
        if(f.getAbholdatum() <= fahrtenbuch[i].getAbholdatum() &&
                f.getAbgabedatum() >= fahrtenbuch[i].getAbgabedatum()){
            return false;
            break;
        }
    }
    return true;
}

void Mietwagen::fahrzeugAnzeigen(){
    cout << " --> Fahrzeug " << marke << " mit KFZ-Kennzeichen " << kennzeichen << endl;
}

int Mietwagen::berechneTage(int datum)
{
    string date = to_string(datum);

    int day = stoi(date.substr(6,2));
    int month = stoi(date.substr(4,2));
    int year = stoi(date.substr(0,4));
    year = (year-2023)*365;

    int total = 0;
    static int length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i=1; i < month; i++)
        total += length[i];
    total += day;
    total += year;
    return (total);
}

void Mietwagen::umsatzAnzeigen(){
    cout << left << setw(25) << marke << setw(12) <<  kennzeichen << "  Tagespreis: " << fixed
         << right << setw(8) << setprecision(2) << tagessatz << "    Gesamtumsatz: " << setw(9) << umsatz << endl;
    gesamtUmsatz += umsatz;
}

double Mietwagen::getGesamtUmsatz()
{
    return gesamtUmsatz;
}
