#pragma once
#include <set>
#include <utility> // dla std::pair
#include <ostream>
#include "plansza.h"

class Statek
{
private:
    // Zbiór par wspolrzednych
    std::set<std::pair<int, int>> pozycje;
    int len; // tutaj przechowujemy dlugosc statku
             
    //len nie jest potrzebny bo moge sobie ustawic getlen wlasna metode, ale z std::pair jest metoda do zdobycia len
    // i mam niepotrzebnie skompilowane 

    // std::vector std::pair i std::set poznac nauczyc sie
    // ksiazki do biblioteki oddac przed swietami

public:
    Statek();
    // todo: brakuje konstruktora statek(statek poz*)
    //  najlepiej wskaznik jesli wszystkie pozycje statkow mamy przech w plansza<statek poz*>
    // Statek(len, plansza na pola.)

    // Dodaje segment do "zdrowych"
    void dodajSegment(int x, int y);

    // Rejestruje trafienie (usuwa segment ze zbioru)
    bool strzal(int x, int y);
    bool czyTrafiony(int x, int y);
    bool czyZatopiony() const;
};

class StatPoz {
private:
    Statek* s;
    int x;
    int y;

public:
    StatPoz() : s(nullptr), x(0), y(0) {}
    StatPoz(Statek *statek, int x, int y) : s(statek), x(x), y(y) {}

    friend inline std::ostream &operator<<(std::ostream &o, const StatPoz &s);
};

/*
class Okret {
Statek *s;
Plansza<kratka> poz;
Plansza<StatPoz*> pozycja;

};
*/

/*


UML made easy

*/