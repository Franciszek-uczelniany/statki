#include <iostream>
#include <ctime>
#include "gracz.h"
#include "dziedziczenie.h"
#include "manager.h"

using namespace std;


int main() {
    Manager m(10);
    m.UtworzGraczy();
    m.Start();
    return 0;
}

int main222() {
    srand(time(nullptr));

    Czlowiek gracz1("Franio", 10);
    SI gracz2(10);

    gracz1.UstawStatki();
    gracz2.UstawStatki();

    cout << "Statki ustawione. Zaczynamy bitwe!\n";

    bool koniecGry = false;

    while (!koniecGry) {
        cout << "\n-----------------------------\n";
        cout << "RADAR GRACZA:\n" << gracz1.getPlanszaRadar() << endl;
        cout << "FLOTA GRACZA:\n" << gracz1.getPlanszaFlota() << endl;

        gracz1.WykonajRuch(gracz2);

        if (gracz2.CzyPrzegral()) {
            cout << "GRATULACJE! WYGRALES!\n";
            koniecGry = true;
            break;
        }

        cout << "\n-----------------------------\n";
        gracz2.WykonajRuch(gracz1);

        if (gracz1.CzyPrzegral()) {
            cout << "NIESTETY, PRZEGRALES Z KOMPUTEREM.\n";
            cout << "Flota komputera:\n" << gracz2.getPlanszaFlota() << endl;
            koniecGry = true;
            break;
        }
    }

    return 0;
}