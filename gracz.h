#pragma once
#include "plansza.h"
#include "statki.h"
#include <vector>

#define LICZBA_OKRETOW 5

class Gracz {
private:
    Plansza<kratka>* PlanszaStrzalow;
    Plansza<kratka>* PlanszaStatkow;
    std::vector<Statek> statki;
    int dlugosciOkretow[LICZBA_OKRETOW] = {5,4,3,3,2};
	bool czyMoznaUstawic(int x,int y,int dl,bool poziomo);

public:
    static bool CzySrandZrobiony;

    Gracz(int rozmiar);
    ~Gracz();

    void strzel(int x, int y);

    bool ustawStatekRecznie(int x, int y, int dlugosc, bool poziomo);
    void ustawOkretyLosowo();

    const Plansza<kratka>* getPlanszaStrzalow() const;
    const Plansza<kratka>* getPlanszaStatkow() const;
};
