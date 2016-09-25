# Viikkoraportti 3

Tällä viikolla toteutin Ford-Fulkersonin algoritmin käyttäen syvyyshakua. Tein myös edellisellä viikolla tehtyä Edmonds-Karp algoritmia varten jono-rakenteen joka toimii samalla tavalla kuin std::queue siltä osin kun sen ominaisuuksia käytän. Lisäksi kirjoitin testejä jonolle ja FFlle. 

Aloitin myös nopeustestien kirjoittamisen, jota varten lisäsin isohkon syötteen inputs kansioon. Lisäksi kirjotin koodia syötteen lukemiseen tiedostosta, ja refaktoroin hieman testikoodia.

Eniten päänvaivaa aiheutti jälleen muistinhallinta, ja muistivuotoja ja valgrind erroreita metsästin kauan. Varsinkin jonon toteutuksessa on tärkeää tehdä nopeaa koodia, joka ei vuoda muistia ylettömästi. Tietorakenteiden toteutus alkaa olla paketissa, en käytä enää standardikirjaston tietorakenteita.

Seuraavaksi teen scaling flow-algoritmin johon pitää vielä perehtyä lisää. Sen toteutus poikkeaa jonkin verran kahdesta algoritmista jotka olen jo tehnyt. Onkin kiinnostavaa nähdä, miten se suoriutuu Edmonds-Karpiin nähden.