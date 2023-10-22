#ifndef FAHRT_H
#define FAHRT_H

#include <iomanip>
using namespace std;

class Fahrt
{
public:
    Fahrt(int n, string k, int ab, int bis);
    void anzeigen();
    int getNummer();
    int getAbholdatum() const;
    int getAbgabedatum() const;
    void setMietkosten(double newMietkosten);

private:
    int nummer;
    string kunde;
    int abholdatum;
    int abgabedatum;
    double mietkosten;
};

#endif // FAHRT_H
