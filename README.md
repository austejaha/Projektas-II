# Studentų galutinio balo skaičiuoklė #
Programa skirta apskaičiuoti kiekvieno studento galutinį balą panaudojant vidukį/medianą.

- - - 

## Veikimo principas ##

Vartotojo paprašoma įvesti:
* studento vardą ir pavardę;
* studento namų darbų pažymius;
* studento egzamino balą;


-------------------------------------------------------------------------

### Vartotojas turi galimybę pasirinkti ###

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

-----------------------------------------------------------------------------------

Įvedus visus prašomus duomenis, vartotojas nurodo, ar nori įtraukti dar vieną studentą. Programa kartojama tol, kol vartotojas nusprendžia, kad daugiau studentų įvesti nebenori.

Rezultatų išvedimo į ekraną pavidalas:

 ```
Pavardė    Vardas     Galutinis
--------------------------------
Pavardė1   Vardas1    8.50
Pavardė2   Vardas2    9.99
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

Programa yra realizuota dviem būdais: naudojant ```C``` tipo masyvą - **masyvas.cpp** ir ```<vector>``` tipo konteinerį - **vektorius.cpp**.

### Įdiegimas ####
* Atsisiųskite norimą programos versiją (rekomenduojama atsisiųsti naujausią versiją) iš [Releases](https://github.com/austejaha/Projektas/releases) aplanko;
* Išarchyvuokite parsisiųstą failą;
* Paleiskite main.cpp programą naudojantis C++ IDE (pvz. CodeBlocks arba Visual Studio) arba per komandinę eilutę.

### Versijos ###
* [v0.1](https://github.com/austejaha/Projektas/tree/v0.1) - pirminė programos versija.

