#pragma once
#include "plansza.h"
#include "statki.h"
#include <vector>
#include <string>

class Gracz {
protected:
    std::string nazwa;
    Plansza<kratka> planszaStatkow;
    Plansza<kratka> planszaRadar;
    std::vector<Statek> statki;

public:
    Gracz(std::string n, int rozmiar);
    virtual ~Gracz() {}

    // metody czysto wirtualne
    virtual void WykonajRuch(Gracz& przeciwnik) = 0;
    virtual void UstawStatki() = 0;

    const Plansza<kratka>& getPlanszaRadar() const { return planszaRadar; }
    const Plansza<kratka>& getPlanszaStatkow() const { return planszaStatkow; }
};


class Si : public Gracz {
public:
    Si(int rozmiar) : Gracz("SI", rozmiar) {};

    void WykonajRuch(Gracz& przeciwnik); 
    void UstawStatki();
    
};
