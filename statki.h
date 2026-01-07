#pragma once
#include <set>
#include <utility>
#include <ostream>

class Statek
{
private:
    std::set<std::pair<int, int>> pozycje;          // pozycje statków
    // Statek jest jednym obiektem a tutaj przechowujemy pozycje iluś statków?
    // Jest to dlatego aby móc robic strzały itd

public:
    Statek(int len, std::pair<int,int>* pola);
 
    void dodajSegment(int x, int y);                // zajmij kolejne pola przez 1 statek
                                                    // StatPoz sluzy po to aby kazde pole mozna bylo
                                                    // jednoznacznie zidentyfikowac z danym statkiem

    // ale  pozycje to jest set, par <int, int> a nie set StatPoz
    // i fun dodaj segment nie dodaje *s, co musi byc
    // 
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
