#pragma once
#include "plansza.h"
#include "statki.h"
#include <iostream>
#include <utility>
#include <vector>

class Gracz {
  private:
    Plansza<kratka> planszaStrzalow;
    Plansza<StatPoz> okrety;          
  public:
    Gracz(int rozmiar);     // rozmiar = rozmiar planszy
    void strzel(int x, int y);
    const Plansza<kratka>& getPlanszaStrzalow() const; 
};
