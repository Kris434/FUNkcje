#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>

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
    void updateSkali(char typFunkcji);
    void resetSkali();

    void pobranieAorazB();
    void munuLiniowaOtwarte();

private:
    Ui::MainWindow *ui;
    bool MenuWidok = true;
    bool duzeOkno = true;

    bool liniowaWidok = true;
    bool logarWidok = true;
    bool sinusWidok = true;
    bool pierWidok = true;

    QDoubleSpinBox *liniowa_A;
    QDoubleSpinBox *liniowa_B;

    double a;
    double b;
};
#endif // MAINWINDOW_H
