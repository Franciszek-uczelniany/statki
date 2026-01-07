#include "gracz.h"
#include <iostream>

using namespace std;

// konstruktor
Gracz::Gracz(int rozmiar) {
        if(CzySrandZrobiony==false) srand(time(nullptr));
        PlanszaStrzalow = new Plansza<kratka>(rozmiar);
        PlanszaStatkow = new Plansza<kratka>(rozmiar);
}

Gracz::~Gracz() {
        free(PlanszaStrzalow);
        free(PlanszaStatkow);
}

// strzał gracza
void Gracz::strzel(int x, int y) {
    try {
        kratka pole = PlanszaStrzalow->sprawdz(x, y);

        if (pole == PUSTA) {
            PlanszaStrzalow->ustaw(x, y, PUDLO);
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
    return PlanszaStrzalow;
}

bool Gracz::CzySrandZrobiony = false;

bool Gracz::ustawStatekRecznie(int x, int y, int dl, bool poziomo) {
    Statek s(dl);

    for (int i = 0; i < dl; i++) {
        int xx = poziomo ? x + i : x;
        int yy = poziomo ? y : y + i;

        if (PlanszaStatkow->sprawdz(xx,yy) != PUSTA)
            return false;

        s.dodajPozycje(xx,yy);
    }

    // zapis na planszy
    for (int i = 0; i < dl; i++) {
        int xx = poziomo ? x + i : x;
        int yy = poziomo ? y : y + i;
        PlanszaStatkow->ustaw(xx,yy,ZAJETE);
    }

    statki.push_back(s);
    return true;
}


void Gracz::ustawOkretyLosowo() {
    //TODO
 /*   for (int i = 0; i < LICZBA_OKRETOW; i++) {
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
        */
}



// rozlozenie okretow recznie i automatycznie
// i w klasie gracz stworzyc tablice okreslajaca okrety, dlugosci okretow 
// sln zaaktualizowac recznie
