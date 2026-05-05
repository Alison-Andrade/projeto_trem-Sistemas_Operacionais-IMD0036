#include "trem.h"
#include <QtCore>

Trem::Trem(int ID, int x, int y) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::run() {
    while(true) {
        switch (ID) {
        case 1:
            if (y == 10 && x < 170) {
                x+=10;
            } else if (x == 170 && y < 160) {
                y+=10;
            } else if (y == 160 && x > 10) {
                x-=10;
            } else {
                y-=10;
            }
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}
