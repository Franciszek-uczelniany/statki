#include "gracz.h"
#include <iostream>

using namespace std;

// konstruktor
Gracz::Gracz(int rozmiar)
    : planszaStrzalow(rozmiar), 
    okrety(rozmiar) {}

// strzał gracza
void Gracz::strzel(int x, int y) {
    try {
        kratka pole = planszaStrzalow.sprawdz(x, y);

        if (pole == PUSTA) {
            planszaStrzalow.ustaw(x, y, PUDLO);
            cout << "Pudlo!\n";
        } else {
            cout << "Tu juz strzelales!\n";
        }
    }
    catch (out_of_range&) {
        cout << "Strzal poza plansze!\n";
    }
}

// getter planszy strzałów
const Plansza<kratka>& Gracz::getPlanszaStrzalow() const {
    return planszaStrzalow;
}
