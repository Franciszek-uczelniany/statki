#pragma once
#include <set>
#include <utility>
#include <ostream>

class Statek
{
private:

    // todo: uproscic logike kodu poprzez usuniecie 'pozycji' z obiektu statek
    // nastepnie uproszczenie kodu tam gdzie jest uzywana 'pozycje' czyli wylacznie w statek.cpp
    std::set<std::pair<int, int>> pozycje;          // pozycje statków
    // Statek jest jednym obiektem a tutaj przechowujemy pozycje iluś statków?
    // Jest to dlatego aby móc robic strzały itd

    // wtedy zrobic strukture okret ktora 

    // struct Okret {
//    int dlugosc;                              // dlugosc czyli ile dokladnie pól zajmuje
//    std::set<std::pair<int,int>> pozycje;     // Pola zajmowane przez jeden statek
//    std::set<std::pair<int,int>> trafione;    // Pola trafione przez wrogiego gracza
//};


/// jeszcze raz caly kod przerobic sobie i wyczyscic zbedne komentarze, kod sformatowac itd


public:
    Statek(int len, std::pair<int,int>* pola);
 
    void dodajSegment(int x, int y);                // zajmij kolejne pola przez 1 statek
                                                    // StatPoz sluzy po to aby kazde pole mozna bylo
                                                    // jednoznacznie zidentyfikowac z danym statkiem

    // ale  pozycje to jest set, par <int, int> a nie set StatPoz
    // i fun dodaj segment nie dodaje *s, co musi byc
    // 
    bool strzal(int x, int y);
    bool czyTrafiony(int x, int y);
    bool czyZatopiony() const;
};

class StatPoz {
private:
    Statek* s;
    int x;
    int y;

public:
    StatPoz() : s(nullptr), x(0), y(0) {}
    StatPoz(Statek *statek, int x, int y) : s(statek), x(x), y(y) {}
    bool operator!=(const kratka& p);
    bool operator==(const kratka& p);
};

//Jak chcemy porównac StatPoz z kratką

bool StatPoz::operator==(const kratka& p) {
    switch(p) {
        case ZAJETE:
           if(this->s==nullptr) return false;
           return true;
        break;
        case PUSTA:
            if(this->s==nullptr) return true;
            return false;
        break;
        case TRAFIONY:
            if(this->s->czyTrafiony(x, y)==true) return true;
            return false; 
        break;

        PUDLO:
        return false;
        // cokolwiek, to i tak nie bedzie wołane
        break;
    }

}

bool StatPoz::operator!=(const kratka& p){
    return !(*this==p);
}


// enum kratka { PUSTA, ZAJETE, TRAFIONY, PUDLO };
// Jesli s!= nullptr to wtedy jest pusta, a jesli jest trafiony? jesli pozycje jest rowny null dla danej pary x, y
// czyli operator!=(const kratka& p)