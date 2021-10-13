#include "funkcijos.h"

int main()
{
    vector <studentas> St;
    srand(time(0));

    cout << "Ar norite duomenis ivesti patys (kitu atveju duomenys bus nuskaityti is failo)? (t/n) ";
    if(patvirtinimas()) pagalbine(St);
    else nuskaitymas(St);
    vidMed(St);
    spausdinimas(St);
    St.clear();
}


