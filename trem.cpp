#include "trem.h"

Trem::Trem(int ID, int x, int y) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 0;
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
                    if (x == 150) {
                        semaforo_e.acquire(1);
                        m[0].lock();
                    }
                    x+=10;
                } else if (x == 170 && y < 160) {
                    if (y == 140) m[2].lock();
                    y+=10;
                } else if (y == 160 && x > 10) {
                    x-=10;
                    if (x == 150) m[0].unlock();
                } else {
                    y-=10;
                    if (y == 140) {
                        semaforo_e.release(1);
                        m[2].unlock();
                    }
                }
                break;
            case 2:
                if (y == 10 && x < 350) {
                    if (x == 190) {
                        m[0].unlock();
                    }
                    if (x == 330) {
                        semaforo_d.acquire(1);
                        semaforo_e.acquire(1);
                        m[1].lock();
                    }
                    x+=10;
                } else if (x == 350 && y < 230) {
                    if (y == 210) {
                        m[7].lock();
                    }
                    if (y == 140) m[5].lock();
                    y+=10;
                } else if (y == 230 && x > 170) {
                    if (x == 190) m[4].lock();
                    x-=10;
                    if (x == 330) {
                        semaforo_d.release(1);
                        m[1].unlock();
                        m[5].unlock();
                    }
                } else {
                    if (y == 180) m[0].lock();
                    y-=10;
                    if (y == 210) {
                        m[7].unlock();
                    }
                    if (y == 140) {
                        semaforo_e.release(1);
                        m[4].unlock();
                    }
                }
                break;
            case 3:
                if (y == 10 && x < 520) {
                    x+=10;
                    if (x == 370) {
                        semaforo_d.release(1);
                        m[1].unlock();
                    }
                } else if (x == 520 && y < 160) {
                    if (y == 140) {
                        semaforo_d.acquire(1);
                        m[3].lock();
                    }
                    y+=10;
                } else if (y == 160 && x > 350) {
                    if (x == 370) m[1].lock();
                    x-=10;
                } else {
                    y-=10;
                    if (y == 140) m[3].unlock();
                }
                break;
            case 4:
                if (y == 160 && x < 170) {
                    if (x == 150) m[4].lock();
                    x+=10;
                } else if (x == 170 && y < 330) {
                    if (y == 170) m[6].lock();
                    y+=10;
                    if (y == 180) m[2].unlock();
                    if (y == 250) {
                        semaforo_e.release(1);
                        m[4].unlock();
                    }
                } else if (y == 330 && x > 10) {
                    x-=10;
                    if (x == 150) {
                        m[6].unlock();
                    }
                } else {
                    if (y == 180) {
                        semaforo_e.acquire(1);
                        m[2].lock();
                    }
                    y-=10;
                }
                break;
            case 5:
                if (y == 230 && x < 350) {
                    if (x == 330) m[8].lock();
                    x+=10;
                    if (x == 190) m[6].unlock();
                } else if (x == 350 && y < 330) {
                    y+=10;
                    if (y == 250) {
                        semaforo_e.release(1);
                        semaforo_d.release(1);
                        m[7].unlock();
                    }
                } else if (y == 330 && x > 170) {
                    if (x == 190) {
                        semaforo_e.acquire(1);
                        semaforo_d.acquire(1);
                        m[6].lock();
                    }
                    x-=10;
                    if (x == 330) m[8].unlock();
                } else {
                    if (y == 250) {
                        m[7].lock();
                    }
                    y-=10;
                }
                break;
            case 6:
                if (y == 160 && x < 520) {
                    x+=10;
                    if (x == 370) m[5].unlock();
                } else if (x == 520 && y < 330) {
                    y+=10;
                    if (y == 180) {
                        semaforo_d.release(1);
                        m[3].unlock();
                    }
                } else if (y == 330 && x > 350) {
                    if (x == 370) {
                        semaforo_d.acquire(1);
                        m[8].lock();
                    }
                    x-=10;
                } else {
                    if (y == 180) m[3].lock();
                    if (y == 250) m[5].lock();
                    y-=10;
                    if (y == 210) m[8].unlock();
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
