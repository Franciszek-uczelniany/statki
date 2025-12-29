#include "plansza.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, Plansza<kratka> &p) {
    int w = p.rozmiar();
    int s = w;

    os << "   ";
    for (int col = 0; col < s; col++)
        os << char('A' + col) << " ";
    os << "\n";

    for (int i = 0; i < w; i++) {
        os << (i + 1 < 10 ? " " : "") << i + 1 << " ";
        for (int j = 0; j < s; j++) {
            os << p.sprawdz(i, j) << " ";
        }
        os << "\n";
    }
    return os;
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

