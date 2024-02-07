#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "klasy.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1700, 930);

    QFrame *frame = ui->frame;
    frame->setFixedWidth(250);
    //frame->setFixedHeight(600);

    QFrame *frame_3 = ui->frame_3;
    frame_3->setFixedHeight(70);

    QFrame *frame_6 = ui->frame_6;
    frame_6->setFixedHeight(115);

    QPixmap menuImage("G:/QT/projekty/PROGRAMOWANIE_PK/FUNkcje/menu.png");
    QSize desiredSize(30, 30);
    QPixmap scaledMenuImage = menuImage.scaled(desiredSize, Qt::KeepAspectRatio);
    ui->pushButton_10->setIcon(QIcon(menuImage));
    ui->pushButton_10->setIconSize(desiredSize);
    ui->pushButton_10->setFixedSize(desiredSize);

    QSize desiredSize2(20, 20);
    QPixmap minImage("G:/QT/projekty/PROGRAMOWANIE_PK/FUNkcje/min.png");
    QPixmap scaledMinImage = minImage.scaled(desiredSize, Qt::KeepAspectRatio);
    ui->pushButton_9->setIcon(QIcon(minImage));
    ui->pushButton_9->setIconSize(desiredSize2);
    ui->pushButton_9->setFixedSize(30,30);

    QPixmap fullImage("G:/QT/projekty/PROGRAMOWANIE_PK/FUNkcje/full.png");
    QPixmap scaledFullImage = fullImage.scaled(desiredSize, Qt::KeepAspectRatio);
    ui->pushButton_8->setIcon(QIcon(fullImage));
    ui->pushButton_8->setIconSize(desiredSize2);
    ui->pushButton_8->setFixedSize(30,30);

    QPixmap closeImage("G:/QT/projekty/PROGRAMOWANIE_PK/FUNkcje/close.png");
    QPixmap scaledCloseImage = closeImage.scaled(desiredSize, Qt::KeepAspectRatio);
    ui->pushButton_7->setIcon(QIcon(closeImage));
    ui->pushButton_7->setIconSize(desiredSize2);
    ui->pushButton_7->setFixedSize(30,30);

    connect(ui->skalaX, SIGNAL(valueChanged(double)), this, SLOT(ZmianaWartoscSpinBox()));
    connect(ui->skalaY, SIGNAL(valueChanged(double)), this, SLOT(ZmianaWartoscSpinBox()));
    connect(ui->skalaXmin, SIGNAL(valueChanged(double)), this, SLOT(ZmianaWartoscSpinBox()));
    connect(ui->skalaYmin, SIGNAL(valueChanged(double)), this, SLOT(ZmianaWartoscSpinBox()));
    connect(ui->rozdzielczosc, SIGNAL(valueChanged(int)), this, SLOT(setRozdzielczosc()));

    ui->skalaY->setValue(10.0);
    ui->skalaX->setValue(10.0);
    ui->skalaYmin->setValue(-10.0);
    ui->skalaXmin->setValue(-10.0);

    ui->liniowa_A->setValue(1.0);
    ui->liniowa_B->setValue(0.0);
    ui->logar_A->setValue(5.0);
    ui->logar_B->setValue(5.0);
    ui->logar_C->setValue(5.0);
    ui->pier_A->setValue(2.0);
    ui->pier_B->setValue(0.0);
    ui->sinus_A->setValue(1.0);
    ui->sinus_B->setValue(0.0);
    ui->sinus_F->setValue(1.0);
    ui->sinus_Fi->setValue(0.0);

    connect(ui->liniowa_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_Liniowa_clicked);
    connect(ui->liniowa_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_Liniowa_clicked);
    connect(ui->liniowa_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLiniowaOtwarte);
    connect(ui->liniowa_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLiniowaOtwarte);
    connect(ui->rozdzielczosc, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_Liniowa_clicked);

    connect(ui->logar_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->logar_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->logar_C, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->logar_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLogarOtwarte);
    connect(ui->logar_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLogarOtwarte);
    connect(ui->logar_C, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuLogarOtwarte);
    connect(ui->rozdzielczosc, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_2_clicked);

    connect(ui->pier_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_3_clicked);
    connect(ui->pier_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_3_clicked);
    connect(ui->pier_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuPierOtwarte);
    connect(ui->pier_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuPierOtwarte);
    connect(ui->rozdzielczosc, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_3_clicked);

    connect(ui->sinus_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_4_clicked);
    connect(ui->sinus_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_4_clicked);
    connect(ui->sinus_F, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_4_clicked);
    connect(ui->sinus_Fi, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_4_clicked);
    connect(ui->sinus_A, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuSinusOtwarte);
    connect(ui->sinus_B, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuSinusOtwarte);
    connect(ui->sinus_F, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuSinusOtwarte);
    connect(ui->sinus_Fi, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::munuSinusOtwarte);
    connect(ui->rozdzielczosc, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::on_pushButton_4_clicked);



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
    if (!ui->menu_liniowa->isHidden() || !ui->menu_sinus->isHidden())
    {
        updateSkali();
    }
    else if(!ui->menu_pier->isHidden() || !ui->menu_logar->isHidden())
    {
        updateSkali_2();
    }
    else
    {
        updateSkali();
    }
}
void MainWindow::updateSkali()
{
    double skalaX = ui->skalaX->value();
    double skalaY = ui->skalaY->value();
    double skalaXmin = ui->skalaXmin->value();
    double skalaYmin = ui->skalaYmin->value();

    ui->customPlot->xAxis->setRange(skalaXmin, skalaX);
    ui->customPlot->yAxis->setRange(skalaYmin, skalaY);
    ui->customPlot->replot();
}
void MainWindow::updateSkali_2()
{
    double skalaX2 = ui->skalaX->value();
    double skalaY2 = ui->skalaY->value();
    //double skalaX2min = ui->skalaXmin->value();
    double skalaY2min = ui->skalaYmin->value();

    ui->skalaXmin->setValue(0.0);
    ui->customPlot->xAxis->setRange(0.0, skalaX2);
    ui->customPlot->yAxis->setRange(skalaY2min, skalaY2);
    ui->customPlot->replot();
}

void MainWindow::resetSkali()
{
    ui->skalaX->setValue(10.0);
    ui->skalaY->setValue(10.0);
    ui->skalaXmin->setValue(-10.0);
    ui->skalaYmin->setValue(-10.0);
    updateSkali();
}

int MainWindow::setRozdzielczosc()
{
    int rozdzielczosc;

    if(ui->rozdzielczosc->value() > 0)
    {
        rozdzielczosc = ui->rozdzielczosc->value();
    }
    else
    {
        rozdzielczosc = 100;
    }

    return rozdzielczosc;
}

void MainWindow::munuLiniowaOtwarte()
{
    ui->menu_liniowa->show();
    ui->menu_logar->hide();
    ui->menu_pier->hide();
    ui->menu_sinus->hide();
}
void MainWindow::munuLogarOtwarte()
{
    ui->menu_liniowa->hide();
    ui->menu_logar->show();
    ui->menu_pier->hide();
    ui->menu_sinus->hide();
}
void MainWindow::munuPierOtwarte()
{
    ui->menu_liniowa->hide();
    ui->menu_logar->hide();
    ui->menu_pier->show();
    ui->menu_sinus->hide();
}
void MainWindow::munuSinusOtwarte()
{
    ui->menu_liniowa->hide();
    ui->menu_logar->hide();
    ui->menu_pier->hide();
    ui->menu_sinus->show();
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
    int rozdzielczosc = setRozdzielczosc();

    QVector<double> x, y;

    int ilePunktow = w.getSkalaX() * 2 * rozdzielczosc;

    for(int i = 0; i <= ilePunktow; i++)
    {
        x.push_back(w.getSkalaX() * 2 * (double)i / (ilePunktow - 1) - w.getSkalaX());
        y.push_back(f.obliczY(x[i]));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    updateSkali();

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

    double logar_A = ui->logar_A->value();
    double logar_B = ui->logar_B->value();
    double logar_C = ui->logar_C->value();

    logarytmiczna f(logar_A, logar_B, logar_C);
    Wykres w(ui->skalaX->value(), ui->skalaY->value());
    int rozdzielczosc = setRozdzielczosc();

    QVector<double> x, y;

    int ilePunktow = w.getSkalaX() * rozdzielczosc;

    for(int i = 1; i <= ilePunktow; i++)
    {
        x.push_back(w.getSkalaX() * (double)i / (ilePunktow - 1));
        y.push_back(f.obliczY(x[i-1]));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    updateSkali_2();

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

    double pier_A = ui->pier_A->value();
    double pier_B = ui->pier_B->value();

    pierwiastek f(pier_A, pier_B);
    Wykres w(ui->skalaX->value(), ui->skalaY->value());
    int rozdzielczosc = setRozdzielczosc();

    updateSkali_2();

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

    double sinus_A = ui->sinus_A->value();
    double sinus_B = ui->sinus_B->value();
    double sinus_F = ui->sinus_F->value();
    double sinus_Fi = ui->sinus_Fi->value();

    sinus f(sinus_A, sinus_B, sinus_F, sinus_Fi);
    Wykres w(ui->skalaX->value(), ui->skalaY->value());
    int rozdzielczosc = setRozdzielczosc();

    updateSkali();

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

