#include "plansza.h"

inline std::ostream& operator<<(std::ostream& o, const StatPoz& s)
{
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

inline std::ostream& operator<<(std::ostream& o, kratka k) {
    switch (k) {
    case PUSTA:    return o << "~";
    case ZAJETE:   return o << "O";
    case TRAFIONY: return o << "X";
    case PUDLO:    return o << "*";
    default:       return o << "?";
    }
    return o;
}

