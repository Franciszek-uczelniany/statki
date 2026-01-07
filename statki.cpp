#include <iostream>
#include <vector>
#include <string>
#include "statki.h"
#include "plansza.h"

using namespace std;

Statek::Statek(int len, std::pair<int,int>* pola) {
        for (int i = 0; i < len; i++) {
            pozycje.insert(pola[i]);
        }
    dlugosc = len;
}

Statek::Statek(int len) {
    dlugosc = len;
}


// dokonujemy strzalu i jesli trafilismy to ta pozycja jest czyszczona
// todo: pozycje maj? wskazywa? na pozycje wroga
bool Statek::strzal(int x, int y) {
    auto it = pozycje.find({ x, y });
    if (it != pozycje.end()) {
        pozycje.erase(it);
        return true;
    }
    return false;
}

bool Statek::czyTrafiony(int x, int y) {
    auto tr = pozycje.find({ x,y });
    if (tr == pozycje.end()) {
        return true;
    }
    return false;
}

bool Statek::czyZatopiony() const {
    return pozycje.empty();
}

void Statek::dodajPozycje(int x, int y) {
    pozycje.insert({ x, y });
}
