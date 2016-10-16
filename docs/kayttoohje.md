# Käyttöohje

Kirjoitin Edmonds-Karp-algoritmille main-luokan, josta sitä voi ajaa. Tämä tapahtuu ajamalla ensin `make -B -C src release` projektin juuressa, joka kääntää koodin. Sen jälkeen src-kansioon ilmestyy `a.out`-niminen tiedosto, jonka voi ajaa.

Ohjelma lukee syötteensä standardivirrasta. Syötteenä on verkko, josta halutaan etsiä maksimivirtaus, ja tulosteena on yksi luku: maksimivirtaus. Ensin tulee antaa verkon solmujen ja kaarien määrä, ja sitten m riviä, joissa on jokaisella 3 numeroa `a` `b` ja `c`. Tämä tarkoittaa, että solmusta `a` on solmuun `b` kaari kapasiteetilla `c`. Huomaa, että solmut on nimetty numeroilla [1..n], ja että ohjelma etsii aina maksimivirtauksen solmusta 1 solmuun n.

Alla on esimerkki ohjelman ajosta. Viimeinen "3" on ohjelman tuloste: maksimivirtaus verkossa.

```bash
➜  max-flow git:(master) ✗ make -B -C src release
make: Entering directory '/home/chang/max-flow/src'
clang++ -std=c++11 -Ofast main.cpp edmondskarp.cpp
make: Leaving directory '/home/chang/max-flow/src'
➜  max-flow git:(master) ✗ cd src
➜  src git:(master) ✗ ./a.out
2 1
1 2 3
3

```

Esimerkki testien ajosta

```bash
➜  max-flow git:(master) ✗ make -B -C src test
make: Entering directory '/home/chang/max-flow/src'
clang++ -std=c++11 -g scaling_flow.cpp ford_fulkerson.cpp edmondskarp.cpp ./test/*.cpp && ./a.out
===============================================================================
All tests passed (87 assertions in 23 test cases)

make: Leaving directory '/home/chang/max-flow/src'
```
