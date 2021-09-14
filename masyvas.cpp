#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::stoi;
using std::setw;
using std::setprecision;
using std::sort;


struct studentas {
    string vard;
    string pavard;
    int n;
    int nd[10000];
    int egz;
    float glt;
};

//tikrina ar ivesta varda/pavarde sudaro tik raides
bool vard_tikrinimas(string kint);
//ivedami duomenis, jei neteisingi - prasoma ivesti is naujo
string vard_ivedimas(string ivedimas);
//
bool sk_kiekio_tikrinimas(string laik);
//tikrina ar ivestas skaicius/ar priklauso intervalui [1-10]
bool sk_tikrinimas(string laik);
//
int sk_ivedimas(string ivedimas, bool);
//skaiciuoja suma
int sum(int nd[]);
//
float vidurkis(int n, int nd[]);
//
float mediana(int n, int nd[]);
//skaiciuoja galutini bala
float galutinis(float, int egz);
//duomenu spausdinimui skirta funkcija
void spausdinimas();
//
void pagalbine(studentas St[], int &i);
//
bool patvirtinimas();

int main()
{

    studentas St[10];
    int i;
    pagalbine(St, i);
    /*vard_ivedimas( ivedimas);
    sk_tikrinimas(laik, minpaz, maxpaz);
    sum(nd);
    galutinis(nd, egz, glt);*/



}

void pagalbine(studentas St[], int &i){
    i = 0;
    int n;
    do{
        n = 0;
        St[i].vard = vard_ivedimas("varda");
        cout<<St[i].vard;
        St[i].pavard = vard_ivedimas("pavarde");
        cout << "Ar norite ivesti pazymiu kieki (t/n)? ";
        if(patvirtinimas()){
            n = sk_ivedimas("pazymiu kieki", false);
            for(int j = 0; j < n; j++){
                St[i].nd[j] = sk_ivedimas("pazymi", true);
            }
        }
        else{
            do{
                St[i].nd[n] = sk_ivedimas("pazymi", true);
                cout<< St[i].nd[n];
                n++;
                cout << "Ar norite ivesti dar viena pazymi (t/n)? ";
            } while(patvirtinimas());
            
        }
        St[i].n = n;
        St[i].egz = sk_ivedimas("egzamino pazymi", true);
        cout <<"Ar norite ivesti dar vieno studento duomenis? (t/n) ";
        i++;
    } while(patvirtinimas());

    cout << "Ar norite apskaiciuoti vidurki (kitu atveju bus skaiciuojama mediana)? (t/n) ";
    cout<< i;
    if(patvirtinimas()){ cout <<"th";
        for(int j = 0; j < i; j++)
        {
            St[i].glt = galutinis(vidurkis(St[i].n, St[i].nd), St[i].egz);
        }
    }
    else{
        for(int j = 0; j < i; j++)
        {
            St[i].glt = galutinis(mediana(St[i].n, St[i].nd), St[i].egz);
        }
    }
     for(int j = 0; j < i; j++)
     {
         cout << St[i].vard << " " << St[i].pavard;
         //for (int k = 0; k < sizeof (St[i].nd); k++) cout << St[i].nd[k] << " ";
         cout << St[i].egz << " " << St[i].glt <<" ";
         cout << "n=" << St[i].n << endl;
     } 

    
}

bool patvirtinimas(){
    bool tiesa = true;
    bool laik = true;
    string tn;

    do{
        cin >> tn;
        if(tn.length() == 1 && (tolower(tn[0]) == 't' || tolower(tn[0]) == 'n')){
            laik = true;
            if(tolower(tn[0]) == 't' )
            tiesa = true;
            else tiesa = false;
        }
        else {
            cout << "Iveskite duomenis is naujo! ";
            laik = false;
        }
    } while(!laik);

    return tiesa;
}

bool vard_tikrinimas(string kint) {
    bool teisingas = true;
    for (int i = 0; i < kint.length(); i++)
    {
        if (isalpha(kint[i]) == false)
        {
            teisingas = false;
            cout << "Klaida, varda/pavarde turi sudaryti tik raides" << endl;
            break;
        }
        else teisingas = true;
    }
    return teisingas;
}

string vard_ivedimas(string ivedimas) {
    string kint;
    do {
        // cout << "Iveskite duomenis is naujo: ";
        cout << "Iveskite studento " << ivedimas << ": ";
        cin >> kint;
    } while (!vard_tikrinimas(kint));
    return kint;
}

bool sk_kiekio_tikrinimas(string laik){
    bool teisingas = true;
    for (int i = 0; i < laik.length(); i++) {
        if (!isdigit(laik[i]) && stoi(laik) > 0)
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu"<<endl;
            break;
        }
    }
    return teisingas;

}

bool sk_tikrinimas(string laik) {
    bool teisingas = true;
    for (int i = 0; i < laik.length(); i++) {
        if (!isdigit(laik[i]))
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu" << endl;
            break;
        }
        // if (teisingas == true && stoi(laik) < 1) 
        // // && minpaz == 0 && maxpaz == 0
        // {
        //     teisingas = false;
        //     cout << "Klaida! Skaicius turi buti didesnis uz 0";
        // }
        else if (teisingas == true && (stoi(laik) < 1 || stoi(laik) > 10))
        //&& maxpaz != 0
        {
            teisingas = false;
            cout << "Klaida! Skaicius turi is intervalo [1-10]" << endl;
        }
        
    }
    return teisingas;

}

int sk_ivedimas(string ivedimas, bool tarpinis){
    string kint;
    bool laik;
    do {
        // cout << "Iveskite duomenis is naujo: ";
        cout << "Iveskite " << ivedimas << ": ";
        cin >> kint;
        if(tarpinis)laik = sk_tikrinimas(kint);
        else laik = sk_kiekio_tikrinimas(kint);
    } while (!laik);
    int skaicius = stoi(kint);
    return skaicius;
}

int sum(int nd[]) {
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += nd[i];
    }
    return sum;
}

float vidurkis(int n, int nd[])
{
    return sum(nd) / n;
}

float mediana(int n, int nd[])
{
    float median;
    sort(nd, nd + sizeof nd / sizeof nd[0]);
    if(n / 2 == 0)
    median = (nd[n/2] + nd[n/2 + 1])/2;
    else
    median = nd[n/2];

    return median;
}

float galutinis(float sum, int egz) {
    float glt = float(0.4 * sum) + 0.6 * egz;
    return glt;
}
