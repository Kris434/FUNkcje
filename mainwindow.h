#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool MenuWidok = true;
    bool duzeOkno = true;
};
#endif // MAINWINDOW_H
