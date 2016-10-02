# Viikkoraportti 4

Huomasin, että verkkoni vierusmatriisi-esitys tarkoittaa, että algoritmit tekevät turhaa työtä syvyys- ja leveyshauissa. Jokaiselle solmulle jouduttiin käymään jokainen toinen solmu läpi jotta saatiin katsottua, että mihin solmuihin on kaari sieltä.

Tämän takia halusin muuttaa verkkoni vieruslista-esitykseen, jonka johdosta joudun refaktoroimaan lähes koko koodin. Jotta tätä ei joudu tekemään enää lisäsin uuden verkko-tietorakenteen joka esittää verkkoa, ja abstrahoi sisäiset toteutukset sisäänsä. Tämän johdosta sain myös poistettua monesta paikasta toistoa.

Vieruslistan takia tarvitsin push_back funktiota vector-tietorakenteelle, eli funktiota, joka lisää dynaamisesti allokoiden muistia vektorin loppuun amortisoidussa O(1) ajassa. Koodasin sen ja testejä sille.

Lisäksi tein suorituskyky-testausta, ja koitin saada esiin Ford-Fulkersonin algoritmin pahinta tapausta. Tämä osoittautui vaikeaksi, ja tein siksi Ruby-scriptin joka generoi syötettä (verkkoja) ohjelmalle. Lisäsin myös testejä.

Opin tällä viikolla paljon GDB-debuggausta, jonka ansiosta sain niitettyä paljon bugeja.
