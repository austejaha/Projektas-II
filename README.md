# Studentų galutinio balo skaičiuoklė #
Programa skirta apskaičiuoti kiekvieno studento galutinį balą panaudojant vidukį/medianą.

- - - 

## Veikimo principas ##

Vartotojo paprašoma įvesti:
* studento vardą ir pavardę;
* studento namų darbų pažymius;
* studento egzamino balą;
* pasirinkti ar galutinis balas bus skaičiuojamas naudojant vidurkį, ar medianą.



### Vartotojas turi galimybę pasirinkti ###

Duomenis suvesti rankiniu būdu/nuskaityti iš failo ```kursiokai.txt```

* Duomenų suvedimas rankiniu būdu:
   * vartotojas įveda studentų vardus/pavardes;
   * vartotojas įveda namų darbų pažymius;
   * vartotojas įveda egzamino balus;
   * vartotojas pasirenka kaip bus skaičiuojamas galutinis balas (naudojant vidurkį/medianą).

* Duomenų nuskaitymas iš failo:
   * programa nuskaito duomenis iš failo;
   * vartotojas pasirenka kaip bus skaičiuojamas galutinis balas (naudojant vidurkį/medianą).

Namų darbų pažymius įvesti rankiniu būdu/sugeneruoti atsitiktinius

* Namų darbų pažymių įvedimas rankiniu būdu:
   * vartotojas nurodo, ar nori įvesti namų darbų pažymių kiekį:
      * **jei taip**, įveda norimą kiekį;
      * **jei ne**, įvedus pažymį klausiama, ar vartotojas nori įvesti dar vieną pažymį (taip kartojama tol, kol vartotojas nusprendžia, jog dar vieno pažymio įvesti nebenori).
* Namų darbų pažymių atsitiktinis generavimas:
   * vartotojo yra paprašoma įvesti pažymių kiekį, pažymiai sugeneruojami.    

Egzamino balą įvesti rankiniu būdu/sugeneruoti atsitiktinį

* Egzamino balo įvedimas rankiniu būdu:
   * vartotojas pats įveda norimą balą.
* Egzamino balo atsitiktinis generavimas:
   * egzamino balas yra sugeneruojamas pačios programos. 

Galutinį balą skaičiuoti naudojant vidurkį/medianą

Įvedus visus prašomus duomenis, vartotojas nurodo, ar nori įtraukti dar vieną studentą. Programa kartojama tol, kol vartotojas nusprendžia, kad daugiau studentų įvesti nebenori.

Programa surūšiuoja studentus pagal **pavardes**.

Rezultatų išvedimo į ekraną pavidalas:

 ```
Pavardė    Vardas     Galutinis
--------------------------------
Pavardė1   Vardas2    8.50
Pavardė2   Vardas1    9.99
Pavardė3   Vardas3    3.67
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

- - - 

## Apie programą ##

Programa yra realizuota dviem būdais: su C tipo masyvais ir su vektoriais. Programa su C tipo masyvais saugoma **masyvas.cpp**, o su vektoriais - **vektorius.cpp**.


Įdiegimas:
* Atsisiųskite norimą programos versiją (rekomenduojama atsisiųsti naujausią versiją) iš [Releases](https://github.com/austejaha/Projektas/releases) aplanko;
* Išarchyvuokite parsisiųstą failą;
* Paleiskite main.cpp programą naudojantis C++ IDE (pvz. CodeBlocks arba Visual Studio) arba per komandinę eilutę.

