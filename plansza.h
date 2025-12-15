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
  Plansza(int r);

  T sprawdz(int x, int y) const;
  void ustaw(int x, int y, T wartosc);
  int rozmiar() const { return rozmiar; } // Metoda potrzebna dla operatora<<
  virtual void Drukuj();
};

// szablony mają byc w nagłówku.
// {4,4,3,3,2,2,2,1,1,} zze 4 pozycje 4 poz 3 pozycje 3 pozycje
// jak nie uda sie poziomo to pionowo mozna postawic.
// robimy gracz komputer ktory ma losowo przydzielac statki do pól

// metoda CzyPuste na planszy np
// najlepiej aby byla dopasowana do gracza

// template typename T
template <class T> T Plansza<T>::sprawdz(int x, int y) const {
  if (x >= 0 && x < roz && y >= 0 && y < roz)
    return pola[y][x];

  // a jeśli jest poza tymi zakresami to wyrzuć wyjątek
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const Plansza<T> &p) {
  for (int y = 0; y < p.roz(); y++) {
    for (int x = 0; x < p.roz(); x++) {
      o << p.sprawdz(x, y) << " ";
    }
    o << "\n";
  }
  return o;
}

template <typename T> Plansza<T>::Plansza(int r) : roz(r) {
  pola.assign(r, std::vector<T>(r));
}

template <typename T>
void Plansza<T>::ustaw(int x, int y, T wartosc) {
    //todo
    pola[x][y]=wartosc;
}