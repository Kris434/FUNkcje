#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>
#include <QPixmap>
#include <QPushButton>
#include "klasy.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_10_clicked(); // menu boczne
    void on_pushButton_9_clicked();  // minimalizacja
    void on_pushButton_8_clicked();  // pelny/okno ekran
    void on_pushButton_7_clicked();  // zamykania porgramu

    void on_pushButton_2_clicked();
    void on_Liniowa_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void ZmianaWartoscSpinBox();
    void updateSkali();
    void updateSkali_2();
    void resetSkali();
    int setRozdzielczosc();

    void munuLiniowaOtwarte();
    void munuLogarOtwarte();
    void munuPierOtwarte();
    void munuSinusOtwarte();

private:
    Ui::MainWindow *ui;
    bool MenuWidok = true;
    bool duzeOkno = true;

    bool liniowaWidok = true;
    bool logarWidok = true;
    bool sinusWidok = true;
    bool pierWidok = true;

};
#endif // MAINWINDOW_H
