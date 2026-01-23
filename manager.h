#pragma once
#include "gracz.h"

class Manager {
    Gracz* g1;
    Gracz* g2;
    int rozmiarPlanszy;

public:
    Manager(int rozmiar);
    ~Manager();

    void UtworzGraczy();
    void Start();
};
