#include "plansza.h"

//template typename T
template <class T>
T Plansza<T>::sprawdz(int x, int y) const {
    if(x >= 0 && x < roz && y >= 00 && y < roz)
        return pola[y][x];

        return T();
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Plansza<T>& p) {
    for (int y = 0; y < p.roz(); y++) {
        for (int x = 0; x < p.roz(); x++) {
            o << p.sprawdz(x, y) << " ";
        }
        o << "\n";
    }
    return o;
}


template <typename T>
Plansza<T>::Plansza(int r) : roz(r) {
    pola.assign(r, std::vector<T>(r));
}



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

