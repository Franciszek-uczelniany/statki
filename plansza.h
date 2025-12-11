#include "statki.h"
#include <iostream>

enum kratka { PUSTA, ZAJETE, TRAFIONY, PUDLO };

lass Plansza {
private:
    int rozmiar;
    kratka** pola;

// todo: plansza to ma byc template, poprawic to
}

struct StatPoz {
    Statek* s; // WskaŸnik na statek (lub nullptr/0 jeœli woda)
    int x;
    int y;

    StatPoz() : s(0), x(0), y(0) {}
    StatPoz(Statek* s, int x, int y) : s(s), x(x), y(y) {}
};

inline std::ostream& operator<<(std::ostream& o, const StatPoz& s) {
    if (s.s == 0) {
        o << "~"; // Woda
    }
    else {
        // Obiekt StatPoz pyta wskazywany Statek o jego stan w punkcie (x,y)
        if (s.s->czyTrafiony(s.x, s.y)) {
            o << "X"; // Statek trafiony w tym miejscu
        }
        else {
            o << "O"; // Statek stoi w tym miejscu
        }
    }
    return o;
}