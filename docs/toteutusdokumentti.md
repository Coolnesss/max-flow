# Toteutusdokumentti

Toteutin algoritmeja jotka etsivät verkosta maksimivirtauksen. Koodi on C++ ohjelmointikieltä ja se koostuu tietorakenne-toteutuksista, testeistä ja varsinaisesta koodista.

Algoritmeja on kolme, Ford-Fulkerson, Edmonds-Karp ja Scaling Flow. Jokaiselle on omat header filet jossa näkyy koodin rajapinta, ja lisäksi `.cpp` tiedostot joissa on toteutukset metodeille.

Suorituskyvyltään algoritmit vastaavat yleistä toteutusta. Ford-Fulkerson on `O(|E| * |f|)` missä `|f|` on maksimivirtauksen koko ja `|E|` kaarten määrä, sillä se kasvattaa pahimmassa tapauksessa virtausta vain yhdellä yksiköllä per kierros, ja tekee yhden syvyyshaun per kierros. Käytännössä kuitenkin se on hyvin nopea.

Edmonds-Karp taas ei koskaan suoriudu huonosti, vaan hakee lyhimmän reitin leveyshaulla. Täten se käyttää `O(|V|^2 * |E|)` aikaa, missä `|V|` on solmujen määrä. Tämän todistus jätetään harjoitustehtäväksi.

Toteutuksessani molemmat aikavaativuudet toteutuvat, koska käytän vieruslista-esitystä vierusmatriisin sijaan (muuten EK olisi `O(|V|^3)`).

Lopuksi Scaling Flow käyttää `O(|E|*log(|f|))` aikaa, eli näyttäisi paperilla olevan iso optimointi Ford Fulkersoniin. Käytännössä kuitenkin esim satunnaisilla verkoilla se toimii hieman hitaammin.

Satunnaisilla syötteillä paperilla hitain algoritmi osoittautuu nopeimmaksi, tosin oikeasti kannattanee käyttää Edmonds-Karpia, koska se on nopea myös huonolla syötteellä.

Olisi ollut kiva saada Ford-Fulkersonin pahimman tapauksen verkko generoitua, mutta se osoittautui hyvin hankalaksi enkä ehtinyt tehdä sitä loppuun.

Lähteet:

http://www.cs.princeton.edu/~wayne/cs423/lectures/max-flow-4up.pdf

https://people.cs.clemson.edu/~bcdean/iterm.pdf
