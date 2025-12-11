#include <iostream>
#include <vector>
#include <string>
#include "statki.h"
#include "plansza.h"

using namespace std;

bool Statek::czyTrafiony(int x, int y) {
    auto tr = pozycje.find({ x,y });
    if (tr == pozycje.end()) {
        return true;
    }
    return false;
}




/*
class Okret {
statek *s
plansza<kratka>
plansza<OkretPos *>
statek s(3)


po co robimy szablon? ¿eby moc polozyc wskaŸnik na okret, bo jak bêdzie strzelanie to wtedy temu obiektowi zaznacze ze zosta³ trafiony, bo inaczej trzeba by przeszukiwac okretow ( np. w liœcie okretow - przypis red. Sprawdz(x,y) co tam jest)
plansza ma byc ogolna dla kazdego typu.
ogolna metoda wyswietlajaca a to jak ma byc wyswietlany ten dany typ to juz poza tym mainem napisac
*/





