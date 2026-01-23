#include "plansza.h"
#include "statki.h"
#include <vector>
#include <string>
#include "gracz.h"
#include <iostream>

// ===== konstruktor bazowy =====
Gracz::Gracz(std::string n, int rozmiar)
    : nazwa(n),
    planszaStatkow(rozmiar),
    planszaRadar(rozmiar)
{}
 

void Si::WykonajRuch(Gracz& przeciwnik){
        std::cout << "SI wykonuje ruch...\n";
        // tu póŸniej algorytm strza³u
}

void Si::UstawStatki() {
        std::cout << "SI ustawia statki losowo...\n";
        // tu póŸniej losowe ustawianie
}

