#pragma once
#include "statki.h"
#include <iostream>
#include <vector>
using namespace std;

enum kratka { PUSTA, ZAJETE, TRAFIONY, PUDLO };

template <typename T>
class Plansza {
private:
	int roz;
	std::vector<std::vector<T>> pola;

public:
	Plansza(int r);
	T sprawdz(int x, int y) const;
	void ustaw(int x, int y, T wartosc);
	int rozmiar() const { return roz; }

	// Deklarujemy szablon operatora jako friend
	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const Plansza<U>& p);
};

// Konstruktor
template <typename T>
Plansza<T>::Plansza(int r) : roz(r) {
	pola.assign(r, std::vector<T>(r));
}

template <typename T>
T Plansza<T>::sprawdz(int x, int y) const {
	if (x >= 0 && x < roz && y >= 0 && y < roz) {
		return pola[y][x];
	}
	throw std::out_of_range("Poza plansza");
}

template <typename T>
void Plansza<T>::ustaw(int x, int y, T wartosc) {
	pola[y][x] = wartosc;
}

// operator<<
template <typename T>
std::ostream& operator<<(std::ostream& o, const Plansza<T>& p) {
	o << "  ";
	// litery kolumn
	for (int col = 0; col < p.rozmiar(); col++)
		o << char('A' + col) << " ";
	o << "\n";

	for (int y = 0; y < p.rozmiar(); y++) {
		// numery wierszy
		o << (y + 1 < 10 ? " " : "") << (y + 1) << " ";
		for (int x = 0; x < p.rozmiar(); x++) {
			o << p.sprawdz(x, y) << " ";
		}
		o << "\n";
	}
	return o;
}

