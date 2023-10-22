#include "autovermietung.h"
#include "mietwagen.h"

Autovermietung::Autovermietung()
{

}

Autovermietung::~Autovermietung()
{
    for (unsigned int i = 0; i < fahrzeuge.size(); i++){
        delete fahrzeuge[i];
    }
    cout << "Vielen Dank!" << endl;
}

void Autovermietung::dialog(){
    Mietwagen* fahrzeug = new Mietwagen();
    fahrzeuge.push_back(fahrzeug);

    while (true){
        char eingabe;
        string kunde;
        int nummer, abholDate, abgabeDate;
        int index;

        cout << "1: Fahrzeug mieten" << endl;
        cout << "2: Fahrt anzeigen" << endl;
        cout << "3: Alle Fahrten anzeigen" << endl;
        cout << "4: Fahrzeug loeschen" << endl;
        cout << "5: Fahrzeug hinzufuegen" << endl;
        cout << "6: Alle Fahrzeuge ausgeben" << endl;
        cout << "7: Umsatzliste" << endl;
        cout << "0: Programm beenden" << endl;

        cin >> eingabe;
        switch(eingabe){
        case '1':{         // Fahrzeug mieten
            index = mietwagenSuchen();
            if(index == -1)
                break;

            cout << "Buchungsnummer? ";
            cin >> nummer;
            if(!fahrzeuge[index]->nummerPruefen(nummer))
                break;

            cout << "Kunde (Nachname,Vorname)? ";
            cin >> kunde;
            cout << "Abholdatum (yyyymmtt)? ";
            cin >> abholDate;
            cout << "Abgabedatum (yyyymmtt)? ";
            cin >> abgabeDate;
            if(abholDate>abgabeDate){
                cout << "Abholdatum liegt vor dem Abgabedatum: Buchung wird abgebrochen" << endl;
                break;
            }

            Fahrt fahrt(nummer, kunde, abholDate, abgabeDate);
            fahrzeuge[index]->anmieten(fahrt);
        }
            break;

        case '2':{         // Fahrt anzeigen
            index = mietwagenSuchen();
            if(index == -1)
                break;

            cout << "Buchungsnummer? ";
            cin >> nummer;
            fahrzeuge[index]->fahrtAnzeigen(nummer);

        }
            break;

        case '3':{         // Alle Fahrten anzeigen
            index = mietwagenSuchen();
            if(index == -1)
                break;

            fahrzeuge[index]->alleFahrtenAnzeigen();

        }
            break;

        case '4':{ // Fahrt loeschen
            index = mietwagenSuchen();
            if(index == -1)
                break;

            cout << "Buchungsnummer? ";
            cin >> nummer;
            if(fahrzeuge[index]->fahrtLoeschen(nummer))
                cout << "Buchungsnummer " << nummer << " wurde geloescht" << endl;
            else
                cout << "Buchung existiert nicht" << endl;
        }
            break;

        case '5':{         // Fahrzeug hinzuguegen
            Mietwagen* fahrzeug = new Mietwagen();
            fahrzeuge.push_back(fahrzeug);
        }
            break;

        case '6':{         // Alle Fahrzeuge ausgeben
            cout << "***********************************************************************************" << endl;
            for (unsigned int i = 0; i < fahrzeuge.size(); i++){
                fahrzeuge[i]->fahrzeugAnzeigen();
                fahrzeuge[i]->alleFahrtenAnzeigen();
                cout << "***********************************************************************************" << endl;
            }
        }
            break;

        case '7':{         // Umsatzliste
            cout << "***********************************************************************************" << endl;
            for (unsigned int i = 0; i < fahrzeuge.size(); i++){
                fahrzeuge[i]->umsatzAnzeigen();
            }
            cout << "***********************************************************************************" << endl;
            cout << right << "Gesamtumsatz: " << setw(72) << fixed
                 << setprecision(2)<< fahrzeuge[0]->getGesamtUmsatz() << endl;
        }
            break;

        case '0':{         // Programm beenden
            return;
            break;
        }
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}

int Autovermietung::mietwagenSuchen(){
    unsigned int index;
    cout << "Welches Fahrzeug (indexNr)? ";
    cin >> index;

    if(index >= fahrzeuge.size()){
        cout << "Fahrzeug gibt es nicht: Buchung wird abgebrochen"  << endl;
        return -1;
    }
    else{
        fahrzeuge[index]->fahrzeugAnzeigen();
        return index;
    }
}
