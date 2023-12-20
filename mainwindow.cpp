#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "klasy.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->skalaX, SIGNAL(valueChanged(double)), this, SLOT(ZmianaWartoscSpinBox()));
    connect(ui->skalaY, SIGNAL(valueChanged(double)), this, SLOT(ZmianaWartoscSpinBox()));

    ui->skalaY->setValue(20.0);
    ui->skalaX->setValue(20.0);

    ui->liniowa_A->setValue(1.0);
    ui->liniowa_B->setValue(0.0);

    a = ui->liniowa_A->value();
    b = ui->liniowa_B->value();

    connect(ui->liniowa_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::pobranieAorazB);
    connect(ui->liniowa_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::pobranieAorazB);
    connect(ui->liniowa_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLiniowaOtwarte);
    connect(ui->liniowa_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLiniowaOtwarte);

    connect(ui->Liniowa, SIGNAL(clicked()), this, SLOT(resetSkali()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(resetSkali()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(resetSkali()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(resetSkali()));

    ui->menu_liniowa->hide();
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

void MainWindow::ZmianaWartoscSpinBox()
{
    updateSkali();
}
void MainWindow::updateSkali()
{
    double skalaX = ui->skalaX->value();
    double skalaY = ui->skalaY->value();

    ui->customPlot->xAxis->setRange(0, skalaX);
    ui->customPlot->yAxis->setRange(0, skalaY);
    ui->customPlot->replot();
}
void MainWindow::resetSkali()
{
    ui->skalaX->setValue(20.0);
    ui->skalaY->setValue(20.0);

    updateSkali();
}

void MainWindow::pobranieAorazB()
{
    a = ui->liniowa_A->value();
    b = ui->liniowa_B->value();
    on_Liniowa_clicked();
}
void MainWindow::munuLiniowaOtwarte()
{
    ui->menu_liniowa->show();
}

void MainWindow::on_Liniowa_clicked()
{
    if (!liniowaWidok) {
        ui->menu_liniowa->hide();
    } else {
        ui->menu_liniowa->show();
    }
    liniowaWidok = !liniowaWidok;  // Zmiana stanu menu

    double liniowa_A = ui->liniowa_A->value();
    double liniowa_B = ui->liniowa_B->value();

    liniowa f(liniowa_A, liniowa_B);
    Wykres w(ui->skalaX->value(), ui->skalaY->value(), typFunkcji::liniowa);
    int rozdzielczosc = 101;

    if(ui->rozdzielczosc->value() > 10001)
    {
        rozdzielczosc = 10001;
    }
    else if (ui->rozdzielczosc->value() <= 0)
    {
        rozdzielczosc = 101;
    }
    else
    {
        rozdzielczosc = static_cast<int>(ui->rozdzielczosc->value());
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

    //updateSkali();
    ui->customPlot->replot();
}
void MainWindow::on_pushButton_2_clicked()
{
    logarytmiczna f(5, 5, 5);
    Wykres w(ui->skalaX->value(), ui->skalaY->value(), typFunkcji::liniowa);
    int rozdzielczosc = 101;

    if(ui->rozdzielczosc->value() > 10001)
    {
        rozdzielczosc = 10001;
    }
    else if (ui->rozdzielczosc->value() <= 0)
    {
        rozdzielczosc = 101;
    }
    else
    {
        rozdzielczosc = static_cast<int>(ui->rozdzielczosc->value());
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
    Wykres w(ui->skalaX->value(), ui->skalaY->value(), typFunkcji::liniowa);
    int rozdzielczosc = 101;

    if(ui->rozdzielczosc->value() > 10001)
    {
        rozdzielczosc = 10001;
    }
    else if (ui->rozdzielczosc->value() <= 0)
    {
        rozdzielczosc = 101;
    }
    else
    {
        rozdzielczosc = static_cast<int>(ui->rozdzielczosc->value());
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
    Wykres w(ui->skalaX->value(), ui->skalaY->value(), typFunkcji::liniowa);
    int rozdzielczosc = 101;

    if(ui->rozdzielczosc->value() > 10001)
    {
        rozdzielczosc = 10001;
    }
    else if (ui->rozdzielczosc->value() <= 0)
    {
        rozdzielczosc = 101;
    }
    else
    {
        rozdzielczosc = static_cast<int>(ui->rozdzielczosc->value());
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

