#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "klasy.h"

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


void MainWindow::on_pushButton_clicked()
{
    liniowa f(5, 5);
    Wykres w(ui->doubleSpinBox_2->value(), ui->doubleSpinBox->value(), typFunkcji::liniowa);
    QVector<double> x(101), y(101);

    for(int i = 0; i <= 100; i++)
    {
        x[i] = i / w.getSkalaX();
        y[i] = f.obliczY(x[i]);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0, x[100]);
    ui->customPlot->yAxis->setRange(0, y[100]);
    ui->customPlot->replot();
}

