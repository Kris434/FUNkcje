#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "klasy.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800, 400);

    connect(ui->skalaX, SIGNAL(valueChanged(double)), this, SLOT(ZmianaWartoscSpinBox()));
    connect(ui->skalaY, SIGNAL(valueChanged(double)), this, SLOT(ZmianaWartoscSpinBox()));

    ui->skalaY->setValue(20.0);
    ui->skalaX->setValue(20.0);

    ui->liniowa_A->setValue(1.0);
    ui->liniowa_B->setValue(0.0);

    a = ui->liniowa_A->value();
    b = ui->liniowa_B->value();

    connect(ui->liniowa_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_Liniowa_clicked);
    connect(ui->liniowa_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::pobranieAorazB);
    connect(ui->liniowa_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLiniowaOtwarte);
    connect(ui->liniowa_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLiniowaOtwarte);

    connect(ui->Liniowa, SIGNAL(clicked()), this, SLOT(resetSkali()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(resetSkali()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(resetSkali()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(resetSkali()));

    ui->menu_liniowa->hide();
    ui->menu_logar->hide();
    ui->menu_pier->hide();
    ui->menu_sinus->hide();

    ui->customPlot->setBackground(QBrush(QColor(3, 6, 55)));

    ui->customPlot->xAxis->setBasePen(QPen(QColor(255, 255, 255)));
    ui->customPlot->xAxis->setTickPen(QPen(QColor(255, 255, 255)));
    ui->customPlot->xAxis->setSubTickPen(QPen(QColor(255, 255, 255)));

    ui->customPlot->yAxis->setBasePen(QPen(QColor(255, 255, 255)));
    ui->customPlot->yAxis->setTickPen(QPen(QColor(255, 255, 255)));
    ui->customPlot->yAxis->setSubTickPen(QPen(QColor(255, 255, 255)));

    ui->customPlot->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customPlot->yAxis->setTickLabelColor(QColor(255, 255, 255));

    ui->customPlot->xAxis->setLabelColor(QColor(255, 255, 255));
    ui->customPlot->yAxis->setLabelColor(QColor(255, 255, 255));

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(QColor(200, 4, 85)));
    ui->customPlot->graph(0)->setLayer("overlay");
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
    updateSkali(0);
}

void MainWindow::updateSkali(bool typFunkcji)
{
    double skalaX = ui->skalaX->value();
    double skalaY = ui->skalaY->value();

    if(typFunkcji == 0)
    {
        ui->customPlot->xAxis->setRange(-skalaX, skalaX);
        ui->customPlot->yAxis->setRange(-skalaY, skalaY);
        ui->customPlot->replot();
    }
    else if(typFunkcji == 1)
    {
        ui->customPlot->xAxis->setRange(0, skalaX);
        ui->customPlot->yAxis->setRange(0, skalaY);
        ui->customPlot->replot();
    }
}
void MainWindow::resetSkali()
{
    ui->skalaX->setValue(20.0);
    ui->skalaY->setValue(20.0);

    updateSkali(0);
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
    ui->menu_logar->hide();
    ui->menu_pier->hide();
    ui->menu_sinus->hide();
}

void MainWindow::on_Liniowa_clicked()
{
    if (!liniowaWidok) {
        ui->menu_liniowa->hide();
    } else {
        ui->menu_liniowa->show();
        ui->menu_logar->hide(); logarWidok = true;
        ui->menu_sinus->hide(); sinusWidok = true;
        ui->menu_pier->hide(); pierWidok = true;
    }
    liniowaWidok = !liniowaWidok;  // Zmiana stanu menu

    double liniowa_A = ui->liniowa_A->value();
    double liniowa_B = ui->liniowa_B->value();

    liniowa f(liniowa_A, liniowa_B);
    Wykres w(ui->skalaX->value(), ui->skalaY->value());
    int rozdzielczosc = 101;



    if (ui->rozdzielczosc->value() <= 0)
    {
        rozdzielczosc = 100;
    }
    else
    {
        rozdzielczosc = ui->rozdzielczosc->value();
    }

    QVector<double> x, y;

    int ilePunktow = w.getSkalaX() * 2 * rozdzielczosc;

    for(int i = 0; i <= ilePunktow; i++)
    {
        x.push_back(w.getSkalaX() * 2 * (double)i / (ilePunktow - 1) - w.getSkalaX());
        y.push_back(f.obliczY(x[i]));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    updateSkali(0);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->replot();
}
void MainWindow::on_pushButton_2_clicked()
{
    if (!logarWidok) {
        ui->menu_logar->hide();
    } else {
        ui->menu_logar->show();
        ui->menu_liniowa->hide(); liniowaWidok = true;
        ui->menu_sinus->hide(); sinusWidok = true;
        ui->menu_pier->hide(); pierWidok = true;
    }
    logarWidok = !logarWidok;

    logarytmiczna f(5, 5, 5);
    Wykres w(ui->skalaX->value(), ui->skalaY->value());
    int rozdzielczosc = 101;

    if (ui->rozdzielczosc->value() <= 0)
    {
        rozdzielczosc = 100;
    }

    QVector<double> x, y;

    int ilePunktow = w.getSkalaX() * rozdzielczosc;

    for(int i = 0; i <= ilePunktow; i++)
    {
        x.push_back(w.getSkalaX() * (double)i / (ilePunktow - 1));
        y.push_back(f.obliczY(x[i]));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    updateSkali(1);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->replot();
}
void MainWindow::on_pushButton_3_clicked()
{
    if (!pierWidok) {
        ui->menu_pier->hide();
    } else {
        ui->menu_pier->show();
        ui->menu_liniowa->hide(); liniowaWidok = true;
        ui->menu_logar->hide(); logarWidok = true;
        ui->menu_sinus->hide(); sinusWidok = true;
    }
    pierWidok = !pierWidok;

    pierwiastek f(5, 5);
    Wykres w(ui->skalaX->value(), ui->skalaY->value());
    int rozdzielczosc = 101;

    updateSkali(1);

    if (ui->rozdzielczosc->value() <= 0)
    {
        rozdzielczosc = 100;
    }

    QVector<double> x, y;

    int ilePunktow = w.getSkalaX() * 2 * rozdzielczosc;

    for(int i = 0; i <= ilePunktow; i++)
    {
        x.push_back(w.getSkalaX() * 2 * (double)i / (ilePunktow - 1) - w.getSkalaX());
        y.push_back(f.obliczY(x[i]));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->replot();
}
void MainWindow::on_pushButton_4_clicked()
{
    if (!sinusWidok) {
        ui->menu_sinus->hide();
    } else {
        ui->menu_sinus->show();
        ui->menu_liniowa->hide(); liniowaWidok = true;
        ui->menu_logar->hide(); logarWidok = true;
        ui->menu_pier->hide(); pierWidok = true;
    }
    sinusWidok = !sinusWidok;
    sinus f(1, 1, 1, 1);
    Wykres w(ui->skalaX->value(), ui->skalaY->value());
    int rozdzielczosc = 101;

    updateSkali(0);

    if (ui->rozdzielczosc->value() <= 0)
    {
        rozdzielczosc = 100;
    }

    QVector<double> x, y;

    int ilePunktow = w.getSkalaX() * 2 * rozdzielczosc;

    for(int i = 0; i <= ilePunktow; i++)
    {
        x.push_back(w.getSkalaX() * 2 * (double)i / (ilePunktow - 1) - w.getSkalaX());
        y.push_back(f.obliczY(x[i]));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");


    ui->customPlot->replot();
}

