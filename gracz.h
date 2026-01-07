#pragma once
#include "plansza.h"
#include "statki.h"
#include <iostream>
#include <utility>
#include <vector>
#define LICZBA_OKRETOW 5

class Gracz {
  private:
    Plansza<kratka> *planszaStrzalow;
    Plansza<StatPoz> *okrety; 
    int dlugosciOkretow[LICZBA_OKRETOW] = {5, 4, 3, 3, 2};
            
  public:
   static bool CzySrandZrobiony;
    Gracz(int rozmiar);     // rozmiar = rozmiar planszy
    // todo: destruktor
    void strzel(int x, int y);
    const Plansza<kratka>* getPlanszaStrzalow() const;
    void ustawOkretyLosowo();
    bool ustawOkretRecznie(int x, int y, int dlugosc, bool poziomo);
};

// zmienna statyczna istnieje nawet jak nie ma obiektu

// napisac funkcje ktora zwraca z planszy wolne pola
// czyli (0,1), (1,0), (1,1)
// tablica indeksow i te indeksy mieszamy
// i wtedy dla kazdego indeksu probobujemy rozstawic okret.
// i mozna jeszcze flage czy ma przylegac do statku lub nie
// ta funkcja ma byc do strzalow i do rozstawiania


// PODZIELIC trudny problem na mniejsze problemy tak aby mozna bylo to wkoncu zrobic i zrozumiec.
