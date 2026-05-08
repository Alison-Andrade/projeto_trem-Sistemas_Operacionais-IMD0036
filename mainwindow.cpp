#include "mainwindow.h"
#include "./ui_mainwindow.h"

QMutex m[9];
QSemaphore semaforo_d(2);
QSemaphore semaforo_e(2);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem[0] = new Trem(1, 10, 90);
    trem[1] = new Trem(2, 260, 10);
    trem[2] = new Trem(3, 440, 10);
    trem[3] = new Trem(4, 10, 250);
    trem[4] = new Trem(5, 260, 330);
    trem[5] = new Trem(6, 440, 330);

    for (int i = 0; i < 6; ++i) {
        connect(trem[i], SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    }

    for (int i = 0; i < 6; ++i) {
        trem[i]->start();
    }


}

void MainWindow::updateInterface(int id, int x, int y) {
    switch (id) {
    case 1:
        ui->label_T1->setGeometry(x, y, 21, 21);
        break;
    case 2:
        ui->label_T2->setGeometry(x, y, 21, 21);
        break;
    case 3:
        ui->label_T3->setGeometry(x, y, 21, 21);
        break;
    case 4:
        ui->label_T4->setGeometry(x, y, 21, 21);
        break;
    case 5:
        ui->label_T5->setGeometry(x, y, 21, 21);
        break;
    case 6:
        ui->label_T6->setGeometry(x, y, 21, 21);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_slider_T1_valueChanged(int value)
{
    trem[0]->setVelocidade(value);
}

void MainWindow::on_slider_T2_valueChanged(int value)
{
    trem[1]->setVelocidade(value);
}

void MainWindow::on_slider_T3_valueChanged(int value)
{
    trem[2]->setVelocidade(value);
}

void MainWindow::on_slider_T4_valueChanged(int value)
{
    trem[3]->setVelocidade(value);
}

void MainWindow::on_slider_T5_valueChanged(int value)
{
    trem[4]->setVelocidade(value);
}

void MainWindow::on_slider_T6_valueChanged(int value)
{
    trem[5]->setVelocidade(value);
}

