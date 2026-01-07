#pragma once
#include "plansza.h"
#include "statki.h"
#include <iostream>
#include <utility>
#include <vector>

class Gracz {
  private:
    Plansza<kratka> *planszaStrzalow;
    Plansza<StatPoz> *okrety; 
            
  public:
   static bool CzySrandZrobiony;
    Gracz(int rozmiar);     // rozmiar = rozmiar planszy
    // todo: destruktor
    void strzel(int x, int y);
    const Plansza<kratka>* getPlanszaStrzalow() const; 
};

// zmienna statyczna istnieje nawet jak nie ma obiektu
bool Gracz::CzySrandZrobiony = false;
