#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>
#include <QSemaphore>

extern QMutex m[9];
extern QSemaphore semaforo_d;
extern QSemaphore semaforo_e;

class Trem : public QThread
{
    Q_OBJECT
public:
    Trem(int, int, int);
    void run();
    void setVelocidade(int);

signals:
    void updateGUI(int, int, int);

private:
    int x;
    int y;
    int ID;
    int velocidade;
};

#endif // TREM_H
