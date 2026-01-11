#include "gracz.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool Gracz::CzySrandZrobiony = false;

Gracz::Gracz(int rozmiar) {
    if (!CzySrandZrobiony) {
        srand(time(nullptr));
        CzySrandZrobiony = true;
    }

    PlanszaStrzalow = new Plansza<kratka>(rozmiar);
    PlanszaStatkow  = new Plansza<kratka>(rozmiar);
}

Gracz::~Gracz() {
    delete PlanszaStrzalow;
    delete PlanszaStatkow;
}

// ===== strzały =====

void Gracz::strzel(int x, int y) {
    try {
        kratka pole = PlanszaStrzalow->sprawdz(x, y);
        if (pole == PUSTA) {
            PlanszaStrzalow->ustaw(x, y, PUDLO);
            cout << "Pudlo!\n";
        } else {
            cout << "Tu juz strzelales!\n";
        }
    }
    catch (...) {
        cout << "Strzal poza plansze!\n";
    }
}

// ===== ręczne ustawianie statku =====
bool Gracz::ustawStatekRecznie(int x,int y,int dl,bool poziomo){
    if(!czyMoznaUstawic(x,y,dl,poziomo))
        return false;

    Statek s(dl);

    for(int i=0;i<dl;i++){
        int xx = poziomo ? x+i : x;
        int yy = poziomo ? y : y+i;
        PlanszaStatkow->ustaw(xx,yy,ZAJETE);
        s.dodajPozycje(xx,yy);
    }

    statki.push_back(s);
    return true;
}


// ===== automatyczne ustawianie =====
void Gracz::ustawOkretyLosowo(){
    int roz = PlanszaStatkow->rozmiar();

    std::random_device rd;
    std::mt19937 g(rd());

    for(int i=0;i<LICZBA_OKRETOW;i++){
        bool ustawiony = false;

        // pobieramy listę wolnych pól
        auto pola = PlanszaStatkow->wolnePola();

        // tasujemy kolejność
        std::shuffle(pola.begin(), pola.end(), g);

        for(auto &p : pola){
            int x = p.first;
            int y = p.second;

            bool orientacja[2] = {true,false};
            std::shuffle(orientacja, orientacja+2, g);

            for(bool poziomo : orientacja){
                if(ustawStatekRecznie(x,y,dlugosciOkretow[i],poziomo)){
                    ustawiony = true;
                    break;
                }
            }
            if(ustawiony) break;
        }
    }
}

// ===== gettery =====

const Plansza<kratka>* Gracz::getPlanszaStrzalow() const {
    return PlanszaStrzalow;
}

const Plansza<kratka>* Gracz::getPlanszaStatkow() const {
    return PlanszaStatkow;
}

bool Gracz::czyMoznaUstawic(int x,int y,int dl,bool poziomo){
    int roz = PlanszaStatkow->rozmiar();

    for(int i=0;i<dl;i++){
        int xx = poziomo ? x+i : x;
        int yy = poziomo ? y : y+i;

        if(xx<0 || yy<0 || xx>=roz || yy>=roz)
            return false;

        // sprawdzamy pole i wszystkie sąsiednie
        for(int dy=-1; dy<=1; dy++){
            for(int dx=-1; dx<=1; dx++){
                int nx = xx+dx;
                int ny = yy+dy;
                if(nx>=0 && ny>=0 && nx<roz && ny<roz){
                    if(PlanszaStatkow->sprawdz(nx,ny)==ZAJETE)
                        return false;
                }
            }
        }
    }
    return true;
}
