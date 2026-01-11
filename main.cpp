#include <iostream>
#include "gracz.h"

using namespace std;

int main() {
    Gracz g(10);

    g.ustawOkretyLosowo();

    cout << "=== Plansza statkow ===\n";
    cout << *g.getPlanszaStatkow() << endl;

    cout << "=== Plansza strzalow ===\n";
    cout << *g.getPlanszaStrzalow() << endl;

    g.strzel(3,4);
    g.strzel(3,4);

    cout << "=== Plansza strzalow po strzalach ===\n";
    cout << *g.getPlanszaStrzalow() << endl;

    return 0;
}
