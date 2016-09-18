# Viikkoraportti 2

Toteutin tällä viikolla Edmonds-Karp-algoritmin joka ratkaisee maksimivirtaus-ongelman. Tein sen ensin niin, että käytin `std::vector` ja `std::queue` tietorakenteita. Loin algoritmille muutaman testin, varmistaen näin että se toimii helpoilla pienillä esimerkeillä. Seuraavaksi toteutin itse vector-tietorakenteen, joka on siis dynaaminen taulukko. Siihen liittyen opin paljon C++ muistinhallinnasta ja operaattorikuormituksesta, sekä template-järjestelmästä, joka on tosi kätevä.

Huomasin, että edistys on nopeaa, joten tulen ehkä toteuttamaan enemmän algoritmeja kuin aiemmin kuvittelin. Tajusin, etten tarvitse unordered_map rakennetta ollenkaan ainakaan vielä - mutta sen sijaan jono-rakenne on pakko tehdä vielä. Olen koodannut jonkun verran algoritmeja kisakoodauksessa, mutta niissä ei tarvitse huolehtia muistinhallinnasta joten tämä on uusi kokemus. Eniten hankaluuksia tuottikin juuri vectorin toteutus, vaikka se onkin hyvin yksinkertainen rakenne, ja toteutuksessani on vain muutama pieni ominaisuus verrattuna standardikirjaston vastaavaan rakenteeseen.

Seuraavaksi aion toteuttaa Ford-Fulkerson-algoritmin, ja sen lisäksi jono-tietorakenteen. Lisäksi teen testejä jotka vertailevat kahta algoritmiani, eli lähinnä varmistan, että niistä tulee sama vastaus kaikille syötteille.

Käytän testeihin Catch-frameworkiä joka on `test`-kansiossa header-tiedostona. Projektissa on käytössä Makefile, jonka ansiosta testit voi ajaa projektin juuressa komennolla `make -B -C src test`.

Käytin aikaa noin 12-15h.