# Studentų galutinio balo skaičiuoklė #
Programa skirta apskaičiuoti kiekvieno studento galutinį balą panaudojant vidukį/medianą.

- - - 

## Veikimo principas ##

Vartotojo paprašoma įvesti:
* studento vardą ir pavardę;
* studento namų darbų pažymius (galima sugeneruoti);
* studento egzamino balą (galima sugeneruoti).


---------------------------------------------------------------------------------------------------------------------------------------------------------------------
### Vartotojas turi galimybę pasirinkti ###

DUOMENIS SUVESTI RANKINIU BŪDU/NUSKAITYTI IŠ FAILO ```kursiokai.txt```

* Duomenų suvedimas rankiniu būdu:
   * vartotojas įveda studentų vardus/pavardes;
   * vartotojas įveda namų darbų pažymius;
   * vartotojas įveda egzamino balus;
   * vartotojas pasirenka kaip bus skaičiuojamas galutinis balas (naudojant vidurkį/medianą).

* Duomenų nuskaitymas iš failo:
   * vartotojas pasirenka kokio dydžio studentų sąrašą norės sugeneruoti (1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų)  
   * programa nuskaito duomenis iš failo;
   * vartotojas pasirenka kaip bus skaičiuojamas galutinis balas (naudojant vidurkį/medianą).

NAMŲ DARBŲ PAŽYMIUS ĮVESTI RANKINIU BŪDU/SUGENERUOTI ATSITIKTINIUS

* Namų darbų pažymių įvedimas rankiniu būdu:
   * vartotojas nurodo, ar nori įvesti namų darbų pažymių kiekį:
      * **jei taip**, įveda norimą kiekį;
      * **jei ne**, įvedus pažymį klausiama, ar vartotojas nori įvesti dar vieną pažymį (taip kartojama tol, kol vartotojas nusprendžia, jog dar vieno pažymio įvesti nebenori).
* Namų darbų pažymių atsitiktinis generavimas:
   * vartotojo yra paprašoma įvesti pažymių kiekį, pažymiai sugeneruojami.    



EGZAMINO BALA ĮVESTI RANKINIU BŪDU/SUGENERUOTI ATSITIKTINĮ

* Egzamino balo įvedimas rankiniu būdu:
   * vartotojas pats įveda norimą balą.
* Egzamino balo atsitiktinis generavimas:
   * egzamino balas yra sugeneruojamas pačios programos. 

GALUTINĮ BALĄ SKAIČIUOTI NAUDOJANT VIDURKĮ/MEDIANĄ


---------------------------------------------------------------------------------------------------------------------------------------------------------------------

Įvedus visus prašomus duomenis, vartotojas nurodo, ar nori įtraukti dar vieną studentą. Programa kartojama tol, kol vartotojas nusprendžia, kad daugiau studentų įvesti nebenori.

Programa surūšiuoja studentus pagal **pavardes**.

Programa surūšiuoja studentus į dvi kategorijas: „Idiotai" (**galutinis balas < 5.0**) ir „Genijai" (**galutinis balas >= 5.0**), ir išveda į du atskirus failus: ```idiotai.txt``` ir ```genijai.txt```.

Rezultatų išvedimo į failą pavidalas:

 ```                                      
Pavardė    Vardas     Galutinis
--------------------------------

Pavardė1   Vardas2    8.50
Pavardė2   Vardas1    9.99
Pavardė3   Vardas3    7.67
 ```

**Galutinis balas** yra apskaičiuojamas pagal formulę: ```galutinis = 0.4 * vidurkis + 0.6 * egzaminas ```.

- - - 

## Įvedimo instrukcija ##

Vartotojas po kiekvieno pažymio įvedimo turi paspausti *Enter*.

Kai vartotojo prašoma pasirinkti, jis turi įvesti vieną iš nurodytų simbolių *(t/n)* - taip/ne.


Programa išmeta klaidą ir prašo pakartoti įvedimą šiais atvejais:
* Jei studento varde/pavardėje aptinka ne raidę, o neleistiną simbolį;
* Jei namų darbų pažymys/egzamino balas yra:
  * raidė;
  * simbolis;
  * ne intervale [1 - 10].
* Jei vietoje 't' arba 'n' aptinka kitą simbolį.

Sistema nutraukia darbą šiais atvejais:
* Jei failas neegzistuoja/negali buti atidarytas;
* Jei faile studento pažymys nėra intervale [0 - 10];
* Jei faile yra tuščia eilutė;
* Jei įvyksta bet kokia sisteminė klaida.

- - - 

## Programos veikimo greičio (spartos) analizė ##

 ```                                      

             | 1000 | 10000 | 1000000 | 10000000 | 10000000
------------ | -------------| -------------| -------------| -------------| -------------
Generavimas  | 0s | 0.003s | 0.038s | 0.44s | 8.52s 
Nuskaitymas  | 0s | 0.004s | 0.047s | 0.57s | 9.48s
Rūšiavimas   | 0s | 0.002s | 0.031s | 0.45s | 10.07s
Išvedimas    | 0s | 0.002s | 0.031s | 0.45s | 10.07s
 ```

- - -

## Apie programą ##





### Įdiegimas ####
* Atsisiųskite ir išarchyvuokite programą;
* Paleiskite programą naudodami komandinę eilutę:
```
   g++ -o main projektas.cpp
   ./main
   ```

### Versijos ###

* [v0.1](https://github.com/austejaha/Projektas/tree/v0.1) Pirminė programos versija. Programa yra realizuota dviem būdais: naudojant ```C``` tipo masyvą - **masyvas.cpp** ir ```<vector>``` tipo konteinerį - **vektorius.cpp**. 
* [v0.2](https://github.com/austejaha/Projektas/tree/v0.2) Pridėta nuskaitymo iš tekstinio failo funkcija. Programa realizuota naudojant ```<vector>``` tipo konteinerį. 
* [v0.3](https://github.com/austejaha/Projektas/tree/v0.3) Pridėtas išimčių valdymas (angl. Exception Handling). Funkcijos išskirstytos į failus.
* [v0.4](https://github.com/austejaha/Projektas/tree/v0.4) Sukurta funkcija, kuri generuoja atsitiktinius studentų sąrašų failus (1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų). Pridėtas studentų surūšiavimas į dvi kategorijas: „Idiotai" (**galutinis balas < 5.0**) ir „Genijai" (**galutinis balas >= 5.0**), ir išvedimas į du atskirus failus: ```idiotai.txt``` ir ```genijai.txt```. Atlikta programos veikimo greičio (spartos) analizė.


