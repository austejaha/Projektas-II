#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::stoi;
using std::setw;
using std::setprecision;
using std::sort;
using std::vector;

struct studentas {
    string vard;
    string pavard;
    vector <int> nd;
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
int suma(vector <int> nd);
//
float vidurkis(vector <int> nd);
//
float mediana(vector <int> nd);
//skaiciuoja galutini bala
float galutinis(float, int egz);
//duomenu spausdinimui skirta funkcija
void spausdinimas();
//
void pagalbine(vector <studentas> St);
//
bool patvirtinimas();

int main()
{
    vector <studentas> St;
    pagalbine(St);
    St.clear();
}

void pagalbine(vector <studentas> St){
    studentas S;
    do{
        S.vard = vard_ivedimas("varda");
        S.pavard = vard_ivedimas("pavarde");
        cout << "Ar norite ivesti pazymiu kieki (t/n)? ";
        if(patvirtinimas()){
            int n = sk_ivedimas("pazymiu kieki", false);
            for(int j = 0; j < n; j++){
                S.nd.push_back(sk_ivedimas("pazymi", true));
            }
        }
        else{
            do{
                S.nd.push_back(sk_ivedimas("pazymi", true));
                cout << "Ar norite ivesti dar viena pazymi (t/n)? ";
            } while(patvirtinimas());
            
        }
        S.egz = sk_ivedimas("egzamino pazymi", true);
        S.glt = 0;
        St.push_back(S);
        S.nd.clear();
        cout <<"Ar norite ivesti dar vieno studento duomenis? (t/n) ";
        
    } while(patvirtinimas());

    cout << "Ar norite apskaiciuoti vidurki (kitu atveju bus skaiciuojama mediana)? (t/n) ";
    if(patvirtinimas()){ 
        for(int j = 0; j < St.size(); j++)
        {
            St[j].glt = galutinis(vidurkis(St[j].nd), St[j].egz);
        }
    }
    else{
        for(int j = 0; j < St.size(); j++)
        {
            St[j].glt = galutinis(mediana(St[j].nd), St[j].egz);
        }
    }

    //  for(int j = 0; j < St.size(); j++)
    //  {
    //      cout << St[j].vard << " " << St[j].pavard;
    //      for (int k = 0; k < St[j].nd.size(); k++) cout << St[j].nd[k] << " ";
    //      cout << St[j].egz << " " << St[j].glt <<" ";
    //  } 

    
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

int suma(vector <int> nd) {
    // int sum = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     sum += nd[i];
    // }
    
    return accumulate(nd.begin(), nd.end(), 0);
}

float vidurkis(vector <int> nd)
{
    int n = nd.size();
    float vid = suma(nd) / n;
    return vid;
}

float mediana(vector <int> nd)
{
    float median;
    int n = nd.size();
    sort(nd.begin(), nd.end());
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
