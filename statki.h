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

class StatPoz : private Statek
{
private:
    int x;
    int y;

public:
    Statek *s; // Wskaznik na statek (nullptr/0 jesli woda)
    //    const Statek* s;
    //   StatPoz() : _s(0), x(0), y(0) {s = _s;}
    StatPoz() : s(0), x(0), y(0) { s = s; }

    StatPoz(Statek *s, int x, int y) : s(s), x(x), y(y) { s = s; }
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