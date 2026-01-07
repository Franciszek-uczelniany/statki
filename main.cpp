#include <iostream>
#include "gracz.h"

using namespace std;

int main() {
	// Tworzymy gracza
	Gracz gracz(10);

	const Plansza<kratka> *strzaly_gracza;
	strzaly_gracza =  gracz.getPlanszaStrzalow();		//getPlanszaStrzalow sluzy do debugowania

	cout << "Plansza strzalow gracza (poczatkowa):\n";
	cout << *strzaly_gracza << endl;

	// Symulujemy strzały
	cout << "Strzal w (2,3)\n";
	gracz.strzel(2, 3);

	cout << "Strzal w (5,5)\n";
	gracz.strzel(5, 5);

	cout << "Strzal w (2,3) ponownie\n";
	gracz.strzel(2, 3);

	// Wypisujemy planszę strzałów
	cout << "\nPlansza strzalow po strzalach:\n";
	cout << *strzaly_gracza << endl;

	return 0;
}
