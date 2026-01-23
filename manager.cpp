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
    cout << "Tworze graczy...\n";

    // Na razie: obaj SI
    g1 = new Si(rozmiarPlanszy);
    g2 = new Si(rozmiarPlanszy);

    g1->UstawStatki();
    g2->UstawStatki();
}

void Manager::Start() {
    cout << "\nPlansza statkow gracza 1:\n";
    cout << g1->getPlanszaStatkow() << endl;

    cout << "\nPlansza statkow gracza 2:\n";
    cout << g2->getPlanszaStatkow() << endl;

    cout << "\nStart rozgrywki...\n";
}
