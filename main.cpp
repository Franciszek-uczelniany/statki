#include <iostream>
#include "gracz.h"

using namespace std;

int main() {
	// Tworzymy gracza
	Gracz gracz(10);

	cout << "Plansza strzalow gracza (poczatkowa):\n";
	cout << gracz.getPlanszaStrzalow() << endl;

	// Symulujemy strzały
	cout << "Strzal w (2,3)\n";
	gracz.strzel(2, 3);

	cout << "Strzal w (5,5)\n";
	gracz.strzel(5, 5);

	cout << "Strzal w (2,3) ponownie\n";
	gracz.strzel(2, 3);

	// Wypisujemy planszę strzałów
	cout << "\nPlansza strzalow po strzalach:\n";
	cout << gracz.getPlanszaStrzalow() << endl;

	return 0;
}
