#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_10_clicked() // wyswietlanie menu bocznegol
{
    if (MenuWidok) {
        ui->frame->hide();
    } else {
        ui->frame->show();
    }
    MenuWidok = !MenuWidok;  // Zmiana stanu menu
}
void MainWindow::on_pushButton_9_clicked() // przycisk minimalizacji
{
    showMinimized();
}
void MainWindow::on_pushButton_8_clicked() // przycisk pelny/okno ekran
{
    if (duzeOkno) {
        showFullScreen();
    } else {
        showNormal();
    }
    duzeOkno = !duzeOkno;
}
void MainWindow::on_pushButton_7_clicked() // przycik do zamykania porgramu
{
    close();
}

