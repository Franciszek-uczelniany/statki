#include <iostream>
#include "plansza.h"
#include "statki.h"

int main() {
    std::pair<int,int> pola[3] = {
        {4,1}, {4,2}, {4,3}
    };

    Statek s1(3, pola);

    Plansza<StatPoz> p(10);

    for (auto& poz : pola) {
        p.ustaw(poz.first, poz.second, StatPoz(&s1, poz.first, poz.second));
    }

    std::cout << p << std::endl;
}
