#pragma once
#include <set>
#include <utility> // dla std::pair
#include "plansza.h"

class Statek {
private:
    // Zbiór par wspó³rzêdnych (x, y), które s¹ "zdrowe"
    std::set<std::pair<int, int>> pozycje;
    int len; //tutaj przechowujemy dlugosc statku, bo np tankowiec ma 300m
             // ale moga i miec 450m, podczas gdy lotniskowce maja po 270m

public:
    Statek();
    //todo: brakuje konstruktora statek(statek poz*)
    // najlepiej wskaznik jesli wszystkie pozycje statkow mamy przech w plansza<statek poz*>

    // Dodaje segment do "zdrowych"
    void dodajSegment(int x, int y);

    // Rejestruje trafienie (usuwa segment ze zbioru)
    bool strzal(int x, int y);
    bool czyTrafiony(int x, int y);
    bool czyZatopiony() const;
};


struct StatPoz {
private:
    Statek* s; // Wskaznik na statek (nullptr/0 jesli woda)
    int x;
    int y;

public:
    StatPoz() : s(0), x(0), y(0) {}
    StatPoz(Statek* s, int x, int y) : s(s), x(x), y(y) {}
};

/*
class Okret {
Statek *s;
Plansza<kratka> poz;
Plansza<StatPoz*> pozycja;

};
*/