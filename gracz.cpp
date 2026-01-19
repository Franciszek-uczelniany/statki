#include "gracz.h"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

Gracz::Gracz(std::string n, int rozmiar)
    : imie(n), planszaRadar(rozmiar), planszaFlota(rozmiar) {
}

bool Gracz::OtrzymajStrzal(int x, int y) {
    kratka stan = planszaFlota.sprawdz(x, y);

    if (stan == ZAJETE) {
        planszaFlota.ustaw(x, y, TRAFIONY);
        for (auto& s : statki) {
            if (s.strzal(x, y)) break;
        }
        return true;
    }
    else if (stan == PUSTA) {
        planszaFlota.ustaw(x, y, PUDLO);
        return false; 
    }
    return false;
}

bool Gracz::czyMoznaPostawic(int x, int y, int dl, bool poziomo) {
    int roz = planszaFlota.rozmiar();
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
                    if (planszaFlota.sprawdz(nx, ny) != PUSTA) return false;
                }
            }
        }
    }
    return true;
}

void Gracz::rozmiescLosowo() {
    int roz = planszaFlota.rozmiar();
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
                    planszaFlota.ustaw(xx, yy, ZAJETE);
                    s.dodajPozycje(xx, yy);
                }
                statki.push_back(s);
                ustawiony = true;
            }
        }
    }
}

bool Gracz::CzyPrzegral() const {
    for (const auto& s : statki) {
        if (!s.czyZatopiony()) return false;
    }
    return true;
}