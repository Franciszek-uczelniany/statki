#pragma once
#include <set>
#include <utility>
#include <ostream>

class Statek
{
private:
    int dlugosc;                                       // dlugosc czyli ile dokladnie pól zajmuje
    std::set<std::pair<int,int>> pozycje;              // Pola zajmowane przez jeden statek
    std::set<std::pair<int,int>> zatopione_pozycje;    // Pola trafione przez wrogiego gracza

public:
    Statek(int len, std::pair<int,int>* pola);
    Statek(int len);
    //todo: destruktor!
    void dodajPozycje(int x, int y);
    bool strzal(int x, int y);
    bool czyTrafiony(int x, int y);
    bool czyZatopiony() const;
};
