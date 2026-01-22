// get plansza radar i get plansza flota
// czepia sie tez konstruktora klasy Si, nie wiem czemu


#include "manager.h"
#include <iostream>

using namespace std;

Manager::Manager(int rozmiar)
    : g1(nullptr), g2(nullptr), rozmiarPlanszy(rozmiar) {}

Manager::~Manager() {
    delete g1;
    delete g2;
}

void Manager::UtworzGraczy() {
    int wybor;

    cout << "Gracz 1: (1) Czlowiek (2) SI: ";
    cin >> wybor;
    if (wybor == 2)
        g1 = new Si(rozmiarPlanszy);
    else
        g1 = new Gracz(rozmiarPlanszy);

    cout << "Gracz 2: (1) Czlowiek (2) SI: ";
    cin >> wybor;
    if (wybor == 2)
        g2 = new Si(rozmiarPlanszy);
    else
        g2 = new Gracz(rozmiarPlanszy);

    // automatycznie rozstawiamy okrêty
    g1->ustawOkretyLosowo();
    g2->ustawOkretyLosowo();
}

void Manager::Start() {
    cout << "\n=== START GRY ===\n";

    cout << "\nPlansza statkow Gracza 1:\n";
    cout << *g1->getPlanszaStatkow() << endl;

    cout << "\nPlansza statkow Gracza 2:\n";
    cout << *g2->getPlanszaStatkow() << endl;

}
