#include <iostream>
#include <vector>
#include <string>
#include "statki.h"

enum kratka { PUSTA, ZAJETE, TRAFIONY, PUDLO };



bool Statek::czyTrafiony(int x, int y) {
    auto tr = pozycje.find({ x,y });
    if (tr == pozycje.end()) {
        return true;
    }
    return false;
}


class Plansza {
private:
    int rozmiar;
    kratka** pola;

public:

    /*

class Okret {
statek *s
plansza<kratka>
plansza<OkretPos *>
statek s(3)


}

po co robimy szablon? ¿eby moc polozyc wskaŸnik na okret, bo jak bêdzie strzelanie to wtedy temu obiektowi zaznacze ze zosta³ trafiony, bo inaczej trzeba by przeszukiwac okretow ( np. w liœcie okretow - przypis red. Sprawdz(x,y) co tam jest)

//plansza ma byc ogolna dla kazdego typu.

std::ostream& operator<<(ostream& o, const Statpoz &s)

if(s.s == 0) cout << '~'; else 

//ogolna metoda wyswietlajaca a to jak ma byc wyswietlany ten dany typ to juz poza tym mainem napisac

*/



    Plansza(int r = 10) : rozmiar(r) {
        pola = new kratka * [rozmiar];
        for (int i = 0; i < rozmiar; i++) {
            pola[i] = new kratka[rozmiar];
            for (int j = 0; j < rozmiar; j++) pola[i][j] = PUSTA;
        }
    }

    bool kratka_sprawdz(int x, int y) {
        return x >= 0 && x < rozmiar && y >= 0 && y < rozmiar;
		// Jeœli kratka jest poza plansz¹, zwróæ false
    }

    bool ustaw_statek(Statek& s, int x, int y, bool poziom) {
        if (poziom) {
            if (x + s.dlugosc > rozmiar) return false;
            for (int i = 0; i < s.dlugosc; i++)
                if (pola[y][x + i] != PUSTA) return false;
            for (int i = 0; i < s.dlugosc; i++)
                pola[y][x + i] = ZAJETE;
        }
        else {
            if (y + s.dlugosc > rozmiar) return false;
            for (int i = 0; i < s.dlugosc; i++)
                if (pola[y + i][x] != PUSTA) return false;
            for (int i = 0; i < s.dlugosc; i++)
                pola[y + i][x] = ZAJETE;
        }
        return true;
    }

    bool strzal(int x, int y) {
        if (!kratka_sprawdz(x, y)) return false;
        if (pola[y][x] == ZAJETE) {
            pola[y][x] = TRAFIONY;
            return true;
        }
        if (pola[y][x] == PUSTA) {
            pola[y][x] = PUDLO;
        }
        return false;
    }

    bool wszystkie_trafione() {
        for (int i = 0; i < rozmiar; i++)
            for (int j = 0; j < rozmiar; j++)
                if (pola[i][j] == ZAJETE) return false;
        return true;
    }

    void wyswietl(bool ukryj = false) {
        std::cout << "  ";
        for (int i = 0; i < rozmiar; i++) std::cout << i << " ";
        std::cout << "\n";

        for (int i = 0; i < rozmiar; i++) {
            std::cout << i << " ";
            for (int j = 0; j < rozmiar; j++) {
                if (pola[i][j] == TRAFIONY) std::cout << "X ";
                else if (pola[i][j] == PUDLO) std::cout << "o ";
                else if (pola[i][j] == ZAJETE && !ukryj) std::cout << "# ";
                else std::cout << ". ";
            }
            std::cout << "\n";
        }
    }
};

class Gracz {
public:
    std::string nazwa;
    Plansza plansza;

    Gracz(std::string n) : nazwa(n), plansza(10) {}

    void rozstaw_statki() {
        std::vector<int> statki = { 4, 3, 3, 2, 2, 2 };

        std::cout << "\n--- Rozstaw statki (" << nazwa << ") ---\n";

        for (int dl : statki) {
            Statek s(dl);
            bool ok = false;

            while (!ok) {
                int x, y, p;
                std::cout << "Statek dlugosci " << dl << " - podaj x y oraz 1=poziomo, 0=pionowo: ";
                std::cin >> x >> y >> p;
                ok = plansza.ustaw_statek(s, x, y, p == 1);
                if (!ok) std::cout << "Nie mozna tam postawic statku!\n";
            }
            plansza.wyswietl(false);
        }
    }
};

class Gra {
public:
    Gracz p1;
    Gracz p2;

    Gra(std::string n1, std::string n2) : p1(n1), p2(n2) {}

    void rozpocznij() {
        p1.rozstaw_statki();
        p2.rozstaw_statki();

        bool tura_p1 = true;

        while (true) {
            Gracz& aktywny = tura_p1 ? p1 : p2;
            Gracz& przeciwnik = tura_p1 ? p2 : p1;

            std::cout << "\nTura gracza " << aktywny.nazwa << "\n";
            przeciwnik.plansza.wyswietl(true);

            int x, y;
            std::cout << "Podaj wspólrzedne strzalu: ";
            std::cin >> x >> y;

            bool trafienie = przeciwnik.plansza.strzal(x, y);
            if (trafienie) {
                std::cout << "TRAFIONY!\n";
            }
            else {
                std::cout << "PUDLO.\n";
                tura_p1 = !tura_p1;
            }

            if (przeciwnik.plansza.wszystkie_trafione()) {
                std::cout << "\nWygrywa " << aktywny.nazwa << "!\n";
                break;
            }
        }
    }
};

int main() {
    Gra g("Gracz1", "Gracz2");
    g.rozpocznij();
    return 0;

    int rozmiarPlanszy = 5;
    plansza<kratka> p(rozmiarPlanszy);
    plansza<OkretPos *> po(rozmiarPlanszy);
    Statek s(3);
    OkretPos po(2, 3);
    p.ustaw(2, 3, TRAFIONY);
    po.ustaw(4, 4, &okPos);
    // &OkretPos(&s,2,3)); w ten spsob aby pominac zmienna aby ustawic okret na danej pozycji
}