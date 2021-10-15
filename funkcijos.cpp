#include "funkcijos.h"

void vidMed(vector <studentas> &St)
{
    cout << "Ar norite apskaiciuoti vidurki (kitu atveju bus skaiciuojama mediana)? (t/n) ";
    long dydis = St.size();
    if(patvirtinimas())
    { 
        for(long int j = 0; j < dydis; j++)
        {
            St[j].glt = galutinis(vidurkis(St[j].nd), St[j].egz);
        }
    }
    else
    {
        for(long int j = 0; j < dydis; j++)
        {
            St[j].glt = galutinis(mediana(St[j].nd), St[j].egz);
        }
    }
}

void nuskaitymas(vector <studentas> &St, string failas)
{
    stringstream buffer;
    ifstream duom;
    pradzia = std::chrono::steady_clock::now();
    try{ 
    duom.open(failas);
    if(!duom) throw 1; 
    buffer << duom.rdbuf();
    duom.close();
    string eil;
    getline(buffer, eil); 

    while(getline(buffer, eil)) 
    {
        
        studentas S; 
        stringstream duom(eil); 
        duom >> S.pavard >> S.vard;
        int paz;
        while(duom >> paz) 
        {   if(paz > 10 || paz < 1 ) throw 2;
            else S.nd.push_back(paz);
        }
        if(S.nd.size() == 0) throw 3;
        S.nd.pop_back(); 
        S.egz = paz;
        S.glt = 0;
        St.push_back(S);
        S.nd.clear();
    }
    }catch (int e) 
    {
        switch(e)
        {
            case 1:
                cout << "Failas neegzistuoja/negali buti atidarytas." << endl;
                break;
            case 2:
                cout << "Pazymys turi buti intervale [1 - 10]." << endl;
                break;
            case 3:
                cout << "Neteisinga ivestis." << endl;
                break;
            default:
                cout << "Sistemos klaida." << endl;
                break;
        }

        exit(0);
    }

    double pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - pradzia).count() / 1000.0;
    cout << endl <<"Sugaistas laikas duomenims nuskaityti: " << pabaiga << " s" << endl << endl;  

}

void pagalbine(vector <studentas> &St)
{
    studentas S;

    do
    {
        S.vard = vardIvedimas("varda");
        S.pavard = vardIvedimas("pavarde");
        cout << "Ar norite pazymius ivesti patys (kitu atveju jie bus sugeneruoti atsitiktinai)? (t/n) ";
        if(patvirtinimas())
        {
        cout << "Ar norite ivesti pazymiu kieki (t/n)? ";
        if(patvirtinimas())
        {
            int n = skIvedimas("pazymiu kieki", false);
            for(int j = 0; j < n; j++)
            {
                S.nd.push_back(skIvedimas("pazymi", true));
            }
        }
        else
        {
            do
            {
                S.nd.push_back(skIvedimas("pazymi", true));
                cout << "Ar norite ivesti dar viena pazymi (t/n)? ";
            } while(patvirtinimas());
            
        }  
        }
        else
        {
            int n = skIvedimas("pazymiu kieki", false);

            for (int j = 0; j < n; j++) S.nd.push_back(atsitiktiniai());
            cout << "Atsitiktinai sugeneruoti pazymiai: ";

            for (int j = 0; j < n - 1; j++) cout << S.nd[j] << ", ";
            cout << S.nd[n - 1] << "." << endl;
        }

        cout << "Ar norite egzamino bala suvesti patys (kitu atveju jis bus sugeneruotas atsitiktinai)? (t/n) ";
        if(patvirtinimas())
        {
            S.egz = skIvedimas("egzamino pazymi", true);
        }
        else
        {
            S.egz = atsitiktiniai();
            cout << "Sugeneruotas egzamino balas: " << S.egz << endl;

        }
        S.glt = 0;
        St.push_back(S);
        S.nd.clear();
        cout << "Ar norite ivesti dar vieno studento duomenis? (t/n) ";
        
    } while(patvirtinimas());
    
}

bool patvirtinimas()
{
    bool tiesa = true;
    bool laik = true;
    string tn;

    do
    {
        cin >> tn;
        if(tn.length() == 1 && (tolower(tn[0]) == 't' || tolower(tn[0]) == 'n'))
        {
            laik = true;
            if(tolower(tn[0]) == 't' )
            tiesa = true;
            else tiesa = false;
        }
        else 
        {
            cout << "Iveskite duomenis is naujo! ";
            laik = false;
        }
    } while(!laik);

    return tiesa;
}

bool vardTikrinimas(string kint) 
{
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

string vardIvedimas(string ivedimas) 
{
    string kint;

    do 
    {
        cout << "Iveskite studento " << ivedimas << ": ";
        cin >> kint;
    } while (!vardTikrinimas(kint));

    return kint;
}

bool skKiekioTikrinimas(string laik)
{
    bool teisingas = true;

    for (int i = 0; i < laik.length(); i++) 
    {
        if (!isdigit(laik[i]) || stoi(laik) == 0)
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu (didesni uz nuli)"<<endl;
            break;
        }
    }

    return teisingas;
}

bool skTikrinimas(string laik) 
{
    bool teisingas = true;

    for (int i = 0; i < laik.length(); i++) 
    {
        if (!isdigit(laik[i]))
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu" << endl;
            break;
        }
        else if (teisingas == true && (stoi(laik) < 1 || stoi(laik) > 10))
        {
            teisingas = false;
            cout << "Klaida! Skaicius turi buti is intervalo [1-10]" << endl;
        }
        
    }

    return teisingas;
}

int skIvedimas(string ivedimas, bool tarpinis)
{
    string kint;
    bool laik;

    do 
    {
        cout << "Iveskite " << ivedimas << ": ";
        cin >> kint;
        if(tarpinis)laik = skTikrinimas(kint);
        else laik = skKiekioTikrinimas(kint);
    } while (!laik);

    int skaicius = stoi(kint);

    return skaicius;
}

int suma(vector <int> nd) 
{
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

float galutinis(float sum, int egz) 
{
    float glt = float(0.4 * sum) + 0.6 * egz;

    return glt;
}

int atsitiktiniai()
{
    int paz;
    paz = 1 + rand() % ((10 + 1) - 1);
    return paz;
}

int ilgPavarde(vector <studentas> St)
{
    int max = 0;
    long int ilgis = St.size();
    
    for(long int i = 0; i < ilgis; i++)
    {
        if(St[i].pavard.length() > max)
        max = St[i].pavard.length();
    }

    return max;
}

int ilgVardas(vector <studentas> St)
{
    int max = 0;
    long int ilgis = St.size();
    
    for(long int i = 0; i < ilgis; i++)
    {
        if(St[i].vard.length() > max)
        max = St[i].vard.length();
    }

    return max;
}

void rikiavimas(vector <studentas> &St)
{
    sort(St.begin(), St.end(), pavardLyginimas);
}

bool pavardLyginimas(studentas &a, studentas &b)
{
    return a.pavard < b.pavard;
}

void spausdinimas(vector <studentas> St, string failas)
{
    rikiavimas(St);
    ofstream out (failas);
    long int ilgis = St.size(); 
    string pnktr = "";
    int maxpavard = ilgPavarde(St);
    int maxvard = ilgVardas(St);
    pnktr.append(maxpavard + maxvard + 30, '-'); 
    pradzia = std::chrono::steady_clock::now();
    out << left << setw(maxpavard + 10) << "Pavarde" << setw(maxvard + 10) << "Vardas" << "Galutinis" << endl; 
    out << pnktr << endl;

    for(long int i = 0; i < ilgis; i++)
    {
        out << left << setw(maxpavard + 10) << St[i].pavard << setw(maxvard + 10) << St[i].vard << fixed << setprecision(2) << St[i].glt << endl;

    }

    double pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - pradzia).count() / 1000.0;
    cout << endl <<"Sugaistas laikas duomenims (" <<failas <<") isvesti: " << pabaiga << " s" << endl << endl;  
}

int pasirinkimas()
{
    cout << "Kuri faila norite naudoti? (1 - 5)" << endl;
    cout << "1 - studentai1000.txt; " << endl << "2 - studentai10000.txt;" << endl << "3 - studentai100000.txt;" 
    << endl << "4 - studentai1000000.txt;" << endl << "5 - studentai10000000.txt;" << endl;
    int skaicius = skIvedimas();
    return skaicius;
}


bool skGenTikrinimas(string laik) 
{
    bool teisingas = true;

    for (int i = 0; i < laik.length(); i++) 
    {
        if (!isdigit(laik[i]))
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu" << endl;
            break;
        }
        else if (teisingas == true && (stoi(laik) < 1 || stoi(laik) > 5))
        {
            teisingas = false;
            cout << "Klaida! Skaicius turi buti is intervalo [1-5]" << endl;
        }
        
    }

    return teisingas;
}

int skIvedimas()
{
    string kint;
    bool laik;
    do 
    {
        cout << "Iveskite skaiciu: ";
        cin >> kint;
        laik = skGenTikrinimas(kint);
    } while (!laik);

    int skaicius = stoi(kint);

    return skaicius;
}

void generavimas(int sk, string &failas)
{
    long n;
    if(sk == 1) n = 1000;
    else if(sk == 2) n = 10000;
    else if(sk == 3) n = 100000;
    else if(sk == 4) n = 1000000;
    else if(sk == 5) n = 10000000;

    failas = "studentai" + to_string(n) + ".txt";
    
    pradzia = std::chrono::steady_clock::now();
    ofstream out(failas); 
    out << "Pavarde" << setw(20) << "Vardas" << setw(13);
    for (int i = 0; i < 10; i++) out << "ND" + to_string(i + 1) << setw(8);
    out << "Egz" << endl;

    for(long int i = 0; i < n; i++)
    {
        out << "Pavarde" + to_string(i + 1);
        out << setw(20) << "Vardas" + to_string(i + 1) << setw(10);
        for(int j = 0; j <= 10; j++) out << atsitiktiniai() <<setw(8);
        out << endl;
    }

    out.close();  

    double pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - pradzia).count() / 1000.0;
    cout << endl <<"Sugaistas laikas failams sugeneruoti: " << pabaiga << " s" << endl << endl;  
    

}

void skirstymas(vector <studentas> St, vector <studentas> &Idiotai, vector <studentas> &Genijai)
{
    long int n = St.size();
    pradzia = std::chrono::steady_clock::now();

    for (long int i = 0; i < n; i ++)
    {
        if(St[i].glt < 5) Idiotai.push_back(St[i]);
        else Genijai.push_back(St[i]);
    }

    double pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - pradzia).count() / 1000.0;
    cout << endl <<"Sugaistas laikas studentams suskirstyti: " << pabaiga << " s" << endl << endl;  
}

