#pragma once
#include "plansza.h"
#include "statki.h"
#include <iostream>
#include <utility>
#include <vector>
#define LICZBA_OKRETOW 5      // Liczba typów okrętów

class Gracz {
private:
	Plansza<kratka>* PlanszaStrzalow;       // Plansza naszych statków
	Plansza<kratka>* PlanszaStatkow;        // Plansza naszych strzałów 
	vector<Statek> statki;
	int dlugosciOkretow[LICZBA_OKRETOW] = { 5, 4, 3, 3, 2 };

public:
	static bool CzySrandZrobiony;
	Gracz(int rozmiar);     // rozmiar = rozmiar planszy
	~Gracz();
	void strzel(int x, int y);
	const Plansza<kratka>* getPlanszaStrzalow() const;
	void ustawOkretyLosowo();
	bool ustawStatekRecznie(int x, int y, int dlugosc, bool poziomo);
};

// napisac funkcje ktora zwraca z planszy wolne pola
// czyli (0,1), (1,0), (1,1)
// tablica indeksow i te indeksy mieszamy
// i wtedy dla kazdego indeksu probobujemy rozstawic okret.
// i mozna jeszcze flage czy ma przylegac do statku lub nie
// ta funkcja ma byc do strzalow i do rozstawiania


// PODZIELIC trudny problem na mniejsze problemy tak aby mozna bylo to wkoncu zrobic i zrozumiec.
