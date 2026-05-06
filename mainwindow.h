#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void updateInterface(int, int, int);

private slots:
    void on_slider_T1_valueChanged(int value);
    void on_slider_T2_valueChanged(int value);
    void on_slider_T3_valueChanged(int value);
    void on_slider_T4_valueChanged(int value);
    void on_slider_T5_valueChanged(int value);
    void on_slider_T6_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    Trem *trem[6];
};
#endif // MAINWINDOW_H
