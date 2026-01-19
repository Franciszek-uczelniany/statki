#pragma once
#include "gracz.h"
#include <iostream>

class Czlowiek : public Gracz {
public:
    Czlowiek(std::string n, int roz) : Gracz(n, roz) {}

    void WykonajRuch(Gracz& przeciwnik) override {
        int x, y;
        bool poprawnyRuch = false;

        std::cout << "Ruch gracza " << imie << ".\n";
        while (!poprawnyRuch) {
            std::cout << "Podaj wspolrzedne strzalu: ";
            std::cin >> x >> y;

            if (x < 0 || y < 0 || x >= planszaRadar.rozmiar() || y >= planszaRadar.rozmiar()) {
                std::cout << "Poza plansza!\n";
                continue;
            }

            if (planszaRadar.sprawdz(x, y) != PUSTA) {
                std::cout << "Juz tu strzelales!\n";
                continue;
            }
            poprawnyRuch = true;
        }

        bool trafiony = przeciwnik.OtrzymajStrzal(x, y);

        if (trafiony) {
            std::cout << "TRAFIONY!\n";
            planszaRadar.ustaw(x, y, TRAFIONY);
        }
        else {
            std::cout << "Pudlo.\n";
            planszaRadar.ustaw(x, y, PUDLO);
        }
    }

    void UstawStatki() override {
        std::cout << "Ustawianie statkow dla " << imie << " automatyczne\n";
        rozmiescLosowo();
    }
};

class SI : public Gracz {
public:
    SI(int roz) : Gracz("Komputer", roz) {}

    void WykonajRuch(Gracz& przeciwnik) override {
        std::cout << "Ruch komputera\n";
        int roz = planszaRadar.rozmiar();
        int x, y;

        do {
            x = rand() % roz;
            y = rand() % roz;
        } while (planszaRadar.sprawdz(x, y) != PUSTA);

        std::cout << "Komputer strzela w: " << x << " " << y << "\n";

        bool trafiony = przeciwnik.OtrzymajStrzal(x, y);

        if (trafiony) {
            std::cout << "Komputer TRAFIL!\n";
            planszaRadar.ustaw(x, y, TRAFIONY);
        }
        else {
            std::cout << "Komputer spudlowal.\n";
            planszaRadar.ustaw(x, y, PUDLO);
        }
    }

    void UstawStatki() override {
        rozmiescLosowo();
    }
};
