#include "gracz.h"
#include <iostream>

using namespace std;

// konstruktor
Gracz::Gracz(int rozmiar) {
        if(CzySrandZrobiony==false) srand(time(nullptr));
        planszaStrzalow = new Plansza<kratka>(rozmiar);
        okrety = new Plansza<StatPoz>(rozmiar);
}

// strzał gracza
void Gracz::strzel(int x, int y) {
    try {
        kratka pole = planszaStrzalow->sprawdz(x, y);

        if (pole == PUSTA) {
            planszaStrzalow->ustaw(x, y, PUDLO);
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
const Plansza<kratka>* Gracz::getPlanszaStrzalow() const {
    return planszaStrzalow;
}

// rozlozenie okretow recznie i automatycznie
// i w klasie gracz stworzyc tablice okreslajaca okrety, dlugosci okretow 
// sln zaaktualizowac recznie


// chcielibysmy aby w kontrktorze gracz srand uruchomiony tylko raz
// niezaleznie ile graczy bedzie 
// zmienna statyczna w klasie zrobic od tego