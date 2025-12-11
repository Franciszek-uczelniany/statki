#include <iostream>
#include <vector>
#include <string>
#include "statki.h"
#include "plansza.h"

using namespace std;

void Statek::dodajSegment(int x, int y) {
    pozycje.insert({ x, y });
    len++;
}

// dokonujemy strzalu i jesli trafilismy to ta pozycja jest czyszczona
bool Statek::strzal(int x, int y) {
    auto it = pozycje.find({ x, y });
    if (it != pozycje.end()) {
        pozycje.erase(it);
        return true;
    }
    return false;
}

bool Statek::czyTrafiony(int x, int y) {
    auto tr = pozycje.find({ x,y });
    if (tr == pozycje.end()) {
        return true;
    }
    return false;
}




/*

statek s(3)


po co robimy szablon? ¿eby moc polozyc wskaŸnik na okret, bo jak bêdzie strzelanie to wtedy temu obiektowi zaznacze ze zosta³ trafiony, bo inaczej trzeba by przeszukiwac okretow ( np. w liœcie okretow - przypis red. Sprawdz(x,y) co tam jest)
plansza ma byc ogolna dla kazdego typu.
ogolna metoda wyswietlajaca a to jak ma byc wyswietlany ten dany typ to juz poza tym mainem napisac
*/





