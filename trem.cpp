#include "trem.h"
#include <QtCore>

extern QMutex m[9];

Trem::Trem(int ID, int x, int y) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::setVelocidade(int velocidade) {
    this->velocidade = velocidade;
}

void Trem::run() {
    while(true) {
        if(velocidade > 0) {
            switch (ID) {
            case 1:
                if (y == 10 && x < 170) {
                    if (x == 150) m[0].lock();
                    x+=10;
                } else if (x == 170 && y < 160) {
                    if (y == 140) m[1].lock();
                    y+=10;
                } else if (y == 160 && x > 10) {
                    x-=10;
                    if (x == 150) m[0].unlock();
                } else {
                    y-=10;
                    if (y == 140) m[1].unlock();
                }
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
                    if (y == 170) m[0].lock();
                    if (y == 10) m[0].unlock();
                }
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
                break;
            default:
                break;
            }
            emit updateGUI(ID, x, y);
        }
        int tempo = (velocidade == 0) ? 200 : (200-velocidade);
        msleep(tempo);
    }
}
