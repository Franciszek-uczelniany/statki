#pragma once
#include "plansza.h"
#include "statki.h"
#include <vector>
#include <string>

class Gracz {
protected:
    std::string imie;
    Plansza<kratka> planszaRadar; 
    Plansza<kratka> planszaFlota;
    std::vector<Statek> statki;
    std::vector<int> dlugosciOkretow = { 5, 4, 3, 3, 2 };

    bool czyMoznaPostawic(int x, int y, int dl, bool poziomo);
    void rozmiescLosowo();

public:
    Gracz(std::string n, int rozmiar);
    virtual ~Gracz() {}
    virtual void WykonajRuch(Gracz& przeciwnik) = 0;
    virtual void UstawStatki() = 0;
    bool OtrzymajStrzal(int x, int y);
    bool CzyPrzegral() const;
    const Plansza<kratka>& getPlanszaRadar() const { return planszaRadar; }
    const Plansza<kratka>& getPlanszaFlota() const { return planszaFlota; }
    std::string getImie() const { return imie; }
};


class Si : public Gracz {
public:
    Si(int rozmiar);

    void wykonajRuch();
};