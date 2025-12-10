#pragma once

#include "resource.h"

/*
 Obiekty: statek, plansza, gracz, gra
 metody: plansza(int), wyczysc(), kratka sprawdz(int, int), wyswietl(),
		 statek(int, int, bool), ustaw(int, int), czy_zatopiony(),
		 gracz(string), ustaw_statek(statek, int, int, bool), strzel(int, int),
		 gra(gracz, gracz), rozpocznij(), tura(int, int), sprawdz_zwyciezce()
		 bool kontyunuj_gry()

		 */

// Statki maj¹ byæ mozliwie prosto zrobione... jak saper w ms xp 
// kazdy ma byc w oddzielnym.

enum kratka {PUSTA, ZAJETE, TRAFIONY, PUDLO };
enum statek {}; // typy statku 

class Statek {

};

class Plansza {
private:
	int rozmiar;
	char** kratki;

public:
	Plansza(int rozmiar);
	void wyczysc();
	bool kratka_sprawdz(int x, int y);
	void wyswietl();
};

class Gracz {
	
};

class Gra {

};


