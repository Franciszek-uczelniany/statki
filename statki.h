#pragma once
#include <set>
#include <utility> // dla std::pair

class Statek {
private:
    // Zbiór par wspó³rzêdnych (x, y), które s¹ "zdrowe"
    std::set<std::pair<int, int>> pozycje;
    int rozmiarPoczatkowy;

public:
    Statek();
    //todo: brakuje konstruktora statek(statek poz*)
    // najlepiej wskaznik jesli wszystkie pozycje statkow mamy przech w plansza<statek poz*>

    // Dodaje segment do "zdrowych"
    void dodajSegment(int x, int y);

    // Rejestruje trafienie (usuwa segment ze zbioru)
    bool strzal(int x, int y);
    bool czyTrafiony(int x, int y);
    bool czyZatopiony() const;
};