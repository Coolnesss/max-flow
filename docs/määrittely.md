# Maksimivirtaus-algoritmit

Toteutan [maksimivirtaus](https://en.wikipedia.org/wiki/Maximum_flow_problem) ongelman ratkaisevat algoritmit [Ford-Fulkerson](https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm) ja [Edmonds-Karp](https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm). Ongelmassa on annettu painotettu verkko, jonka kaaret edustavat kapasiteettia, jota solmujen läpi kulkeva virtaus ei voi ylittää. Maksimivirtaus on alkusolmusta loppusolmuun kulkeva virtaus verkossa. Solmusta lähtevä virtaus tulee myös olla yhtäsuuri solmuun tulevan kokonaisvirtauksen kanssa.

Toteutettavat algoritmit ovat standardeja ongelman ratkaisuun. Asymptoottisesti parempia algoritmeja on olemassa, mutta ne ovat vaikeita toteuttaa. Ford-Fulkerson-algoritmi suoriutuu ajassa `O(E*f)` missä `E` on verkon kaarien määrä ja `f` maksimivirtaus. Edmonds-Karp sen sijaan suoriutuu ajassa `(V*E^2)` missä `V` on solmujen määrä.

Algoritmit saavat syötteekseen verkon määrittelyn seuraavassa formaatissa:

Ensin on kaksi arvoa, `n` ja `m` eli solmujen ja kaarien määrä. Tämän jälkeen on `m` riviä, joilla on jokaisella kolme arvoa `a, b, c`: solmusta `a` solmuun `b` kapasiteetti on `c`. Algoritmit palauttavat verkon maksimivirtauksen solmusta alkusolmusta 1 loppusolmuun `n`.

Toteutan lisäksi algoritmeihin tarvittavat tietorakenteet `vector` ja `unordered_map`. Vector-tietorakenne tukee alkioiden lisäystä loppuun amortisoidussa O(1) ajassa ja indeksöintiä O(1) ajassa. unordered_map taas tukee satunnaistettua O(1) lisäystä ja poistoa, sekä hakua avaimella. Toteutan hajautustaulun ylivuotolistat vectoreina, joten hajautustaulun pahimman tapauksen haku on O(N).
