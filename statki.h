#pragma once
#include <set>
#include <utility>
#include <ostream>
#include "plansza.h"

class Statek
{
private:
    std::set<std::pair<int, int>> pozycje;
    int len; // tutaj przechowujemy dlugosc statku
             
    //len nie jest potrzebny bo moge sobie ustawic getlen wlasna metode, ale z std::pair jest metoda do zdobycia len
    // i mam niepotrzebnie skompilowane 

    // std::vector std::pair i std::set poznac nauczyc sie

public:
    Statek();
    Statek(int len, std::pair<int,int>* pola);
 
    void dodajSegment(int x, int y);
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
};
