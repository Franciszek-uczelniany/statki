#pragma once
#pragma once
#include "gracz.h"

class Manager {
private:
    Gracz* g1;
    Gracz* g2;
    int rozmiarPlanszy;

public:
    Manager(int rozmiar);
    ~Manager();

    void UtworzGraczy();   // wybór cz³owiek / SI
    void Start();          // start gry
};
