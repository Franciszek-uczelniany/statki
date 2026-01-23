#include "plansza.h"
#include "statki.h"
#include <vector>
#include <string>
#include "gracz.h"
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

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

Czlowiek::Czlowiek(std::string imie, int rozmiar)
    : Gracz(imie, rozmiar)
{}

void Czlowiek::WykonajRuch(Gracz& przeciwnik) {
    std::cout << nazwa << " wykonuje ruch...\n";
    // podstawowa implementacja strza³u
}

void Czlowiek::UstawStatki() {
    std::cout << nazwa << " ustawia statki...\n";
    // np. rêczne ustawianie
}

bool Gracz::czyMoznaPostawic(int x, int y, int dl, bool poziomo) {
    int roz = planszaStatkow.rozmiar();
    if (poziomo) {
        if (x + dl > roz) return false;
    }
    else {
        if (y + dl > roz) return false;
    }

    for (int i = 0; i < dl; i++) {
        int cx = poziomo ? x + i : x;
        int cy = poziomo ? y : y + i;

        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                int nx = cx + dx;
                int ny = cy + dy;
                if (nx >= 0 && ny >= 0 && nx < roz && ny < roz) {
                    if (planszaStatkow.sprawdz(nx, ny) != PUSTA) return false;
                }
            }
        }
    }
    return true;
   

}

void Gracz::rozmiescLosowo()
{
    int roz = planszaStatkow.rozmiar();
    random_device rd;
    mt19937 gen(rd());

    for (int dl : dlugosciOkretow) {
        bool ustawiony = false;
        while (!ustawiony) {
            int x = gen() % roz;
            int y = gen() % roz;
            bool pionowo = gen() % 2;

            if (czyMoznaPostawic(x, y, dl, !pionowo)) {
                Statek s(dl);
                for (int i = 0; i < dl; i++) {
                    int xx = (!pionowo) ? x + i : x;
                    int yy = (!pionowo) ? y : y + i;
                    planszaStatkow.ustaw(xx, yy, ZAJETE);
                    s.dodajPozycje(xx, yy);
                }
                statki.push_back(s);
                ustawiony = true;
            }
        }
    }
}

