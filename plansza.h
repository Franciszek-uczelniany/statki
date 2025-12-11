#pragma once
#include "statki.h"
#include <iostream>
#include <vector>

enum kratka { PUSTA, ZAJETE, TRAFIONY, PUDLO };


template <typename T>
class Plansza {
private:
    int roz;    // Nie moze miec takiej samej nazwy co nazwa metody  
    std::vector<std::vector<T>> pola;

public:
    Plansza(int r);

    T sprawdz(int x, int y) const;
    void ustaw(int x, int y, T wartosc);
    int rozmiar() const { return rozmiar; } // Metoda potrzebna dla operatora<<
};
