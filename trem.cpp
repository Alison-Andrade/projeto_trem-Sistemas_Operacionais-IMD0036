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
            emit updateGUI(ID, x, y);
            break;
        case 2:
            if (y == 10 && x < 350) {
                x+=10;
            } else if (x == 350 && y < 230) {
                y+=10;
            } else if (y == 230 && x > 170) {
                x-=10;
            } else {
                y-=10;
            }
            emit updateGUI(ID, x, y);
            break;
        case 3:
            if (y == 10 && x < 520) {
                x+=10;
            } else if (x == 520 && y < 160) {
                y+=10;
            } else if (y == 160 && x > 350) {
                x-=10;
            } else {
                y-=10;
            }
            emit updateGUI(ID, x, y);
            break;
        case 4:
            if (y == 160 && x < 170) {
                x+=10;
            } else if (x == 170 && y < 330) {
                y+=10;
            } else if (y == 330 && x > 10) {
                x-=10;
            } else {
                y-=10;
            }
            emit updateGUI(ID, x, y);
            break;
        case 5:
            if (y == 230 && x < 350) {
                x+=10;
            } else if (x == 350 && y < 330) {
                y+=10;
            } else if (y == 330 && x > 170) {
                x-=10;
            } else {
                y-=10;
            }
            emit updateGUI(ID, x, y);
            break;
        case 6:
            if (y == 160 && x < 520) {
                x+=10;
            } else if (x == 520 && y < 330) {
                y+=10;
            } else if (y == 330 && x > 350) {
                x-=10;
            } else {
                y-=10;
            }
            emit updateGUI(ID, x, y);
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}
