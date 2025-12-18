#pragma once
#include "statki.h"
#include <iostream>
#include <vector>

enum kratka { PUSTA, ZAJETE, TRAFIONY, PUDLO };

template <typename T> class Plansza {
private:
  int roz; // Nie moze miec takiej samej nazwy co nazwa metody
  std::vector<std::vector<T>> pola;

public:
  Plansza(int r); // : roz(r), pola(r, std::vector<T>(r)) {};
  T sprawdz(int x, int y) const;
  void ustaw(int x, int y, T wartosc);
  int rozmiar() const { return roz; } // Metoda potrzebna dla operatora<<
  //virtual void Drukuj();      <-- to trzeba zaimplementowac
};


template <class T> T Plansza<T>::sprawdz(int x, int y) const {
  if (x >= 0 && x < roz && y >= 0 && y < roz)
    return pola[y][x];

    throw std::out_of_range("Poza plansza");
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const Plansza<T> &p) {
  for (int y = 0; y < p.rozmiar(); y++) {
    for (int x = 0; x < p.rozmiar(); x++) {
      o << p.sprawdz(x, y) << " ";
    }
    o << "\n";
  }
  return o;
}

template <typename T> Plansza<T>::Plansza(int r) : roz(r) {
  pola.assign(r, std::vector<T>(r));
}

template <typename T> void Plansza<T>::ustaw(int x, int y, T wartosc) {
    //todo
    pola[y][x]=wartosc;
}