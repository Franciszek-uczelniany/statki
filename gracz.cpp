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

bool Gracz::CzySrandZrobiony = false;

bool Gracz::ustawOkretRecznie(int x, int y, int dlugosc, bool poziomo) {
    try {
        for (int i = 0; i < dlugosc; i++) {
            int xx = poziomo ? x + i : x;
            int yy = poziomo ? y : y + i;

            if (okrety->sprawdz(xx, yy) != PUSTA)
                return false;
        }

        for (int i = 0; i < dlugosc; i++) {
            int xx = poziomo ? x + i : x;
            int yy = poziomo ? y : y + i;

            okrety->ustaw(xx, yy, ZAJETE);
        }

        return true;
    }

    catch(exception) {
    return false;
};

}

void Gracz::ustawOkretyLosowo() {
    for (int i = 0; i < LICZBA_OKRETOW; i++) {
        bool ustawiony = false;

        while (!ustawiony) {
            int x = rand() % okrety->rozmiar();
            int y = rand() % okrety->rozmiar();
            bool poziomo = rand() % 2;

            ustawiony = ustawOkretRecznie(
                x, y,
                dlugosciOkretow[i],
                poziomo
            );
        }
    }
}



// rozlozenie okretow recznie i automatycznie
// i w klasie gracz stworzyc tablice okreslajaca okrety, dlugosci okretow 
// sln zaaktualizowac recznie
