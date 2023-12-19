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



void MainWindow::on_Liniowa_clicked()
{
    liniowa f(1, 0);
    Wykres w(ui->doubleSpinBox_2->value(), ui->doubleSpinBox->value(), typFunkcji::liniowa);
    int rozdzielczosc = 101;

    if(ui->doubleSpinBox_3->value() > 10001)
    {
        rozdzielczosc = 10001;
    }
    else if (ui->doubleSpinBox_3->value() <= 0)
    {
        rozdzielczosc = 101;
    }
    else
    {
        rozdzielczosc = static_cast<int>(ui->doubleSpinBox_3->value());
    }

    QVector<double> x(10001), y(10001);

    for(int i = 0; i <= rozdzielczosc; i++)
    {
        x[i] = i / w.getSkalaX();
        y[i] = f.obliczY(x[i]);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0, w.getSkalaX());
    ui->customPlot->yAxis->setRange(0, w.getSkalaY());
    ui->customPlot->replot();
}




void MainWindow::on_pushButton_2_clicked()
{
    logarytmiczna f(5, 5, 5);
    Wykres w(ui->doubleSpinBox_2->value(), ui->doubleSpinBox->value(), typFunkcji::liniowa);
    int rozdzielczosc = 101;

    if(ui->doubleSpinBox_3->value() > 10001)
    {
        rozdzielczosc = 10001;
    }
    else if (ui->doubleSpinBox_3->value() <= 0)
    {
        rozdzielczosc = 101;
    }
    else
    {
        rozdzielczosc = static_cast<int>(ui->doubleSpinBox_3->value());
    }

    QVector<double> x(10001), y(10001);

    for(int i = 0; i <= rozdzielczosc; i++)
    {
        x[i] = i / w.getSkalaX();
        y[i] = f.obliczY(x[i]);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0, w.getSkalaX());
    ui->customPlot->yAxis->setRange(0, w.getSkalaY());
    ui->customPlot->replot();
}
void MainWindow::on_pushButton_3_clicked()
{
    pierwiastek f(5, 5);
    Wykres w(ui->doubleSpinBox_2->value(), ui->doubleSpinBox->value(), typFunkcji::liniowa);
    int rozdzielczosc = 101;

    if(ui->doubleSpinBox_3->value() > 10001)
    {
        rozdzielczosc = 10001;
    }
    else if (ui->doubleSpinBox_3->value() <= 0)
    {
        rozdzielczosc = 101;
    }
    else
    {
        rozdzielczosc = static_cast<int>(ui->doubleSpinBox_3->value());
    }

    QVector<double> x(10001), y(10001);

    for(int i = 0; i <= rozdzielczosc; i++)
    {
        x[i] = i / w.getSkalaX();
        y[i] = f.obliczY(x[i]);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0, w.getSkalaX());
    ui->customPlot->yAxis->setRange(0, w.getSkalaY());
    ui->customPlot->replot();
}


void MainWindow::on_pushButton_4_clicked()
{
    sinus f(1, 1, 1, 1);
    Wykres w(ui->doubleSpinBox_2->value(), ui->doubleSpinBox->value(), typFunkcji::liniowa);
    int rozdzielczosc = 101;

    if(ui->doubleSpinBox_3->value() > 10001)
    {
        rozdzielczosc = 10001;
    }
    else if (ui->doubleSpinBox_3->value() <= 0)
    {
        rozdzielczosc = 101;
    }
    else
    {
        rozdzielczosc = static_cast<int>(ui->doubleSpinBox_3->value());
    }

    QVector<double> x(10001), y(10001);

    for(int i = 0; i <= rozdzielczosc; i++)
    {
        x[i] = i / w.getSkalaX();
        y[i] = f.obliczY(x[i]);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(0, w.getSkalaX());
    ui->customPlot->yAxis->setRange(0, w.getSkalaY());
    ui->customPlot->replot();
}

