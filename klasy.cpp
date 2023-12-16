#include "klasy.h"
#include "qcustomplot.cpp"
#include <cmath>

void Wykres::setSkala(double x, double y)
{
    if(x > 0 && y > 0)
    {
        this->skalaX = x;
        this->skalaY = y;
    }
    else
    {
        skalaX = 10;
        skalaY = 10;
    }
}

double Wykres::getSkalaX()
{
    return this->skalaX;
}

double Wykres::getSkalaY()
{
    return this->skalaY;
}

void Wykres::rysujWykres()
{
    QVector<double> x(101), y(101);

    switch(typ)
    {
        default:
        case typFunkcji::liniowa:
            liniowa f(5, 5, 5);

            for(int i = 0; i <= 100; i++)
            {
                x[i] = i/20;
                y[i] = f.obliczY();
            }
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");

    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    customPlot->replot();
}

Wykres::Wykres(double x, double y, typFunkcji t)
{
    setSkala(x, y);
    this->typ = t;
}

void Funkcje::setX(double n_x)
{
    this->x = n_x;
}

void Funkcje::setY(double n_y)
{
    this->y = n_y;
}

double Funkcje::getY()
{
    return this->y;
}

double Funkcje::getX()
{
    return this->x;
}

void Funkcje::setA(double n_a)
{
    this->a = n_a;
}

void Funkcje::setB(double n_b)
{
    this->b = n_b;
}

void Funkcje::setC(double n_c)
{
    this->c = n_c;
}

void Funkcje::setD(double n_d)
{
    this->d = n_d;
}

void Funkcje::setF(double n_f)
{
    this->f = n_f;
}

void Funkcje::setFi(double n_fi)
{
    this->fi = n_fi;
}

double liniowa::getA()
{
    return this->a;
}

double liniowa::getB()
{
    return this->b;
}

double liniowa::obliczY()
{
    double y;

    y = a * getX() + b;

    return y;
}

liniowa::liniowa(double x, double a, double b)
{
    setX(x);
    setA(a);
    setB(b);
}

double logarytmiczna::getA()
{
    return this->a;
}

double logarytmiczna::getB()
{
    return this->b;
}

double logarytmiczna::getC()
{
    return this->c;
}

double logarytmiczna::obliczY()
{
    double y;

    y = a * (log10(getX()) / log10(b)) + c;

    return y;
}

logarytmiczna::logarytmiczna(double n_x, double n_a, double n_b, double n_c)
{
    setX(n_x);
    setA(n_a);
    setB(n_b);
    setC(n_c);
}

double sinus::getA()
{
    return this->a;
}

double sinus::getB()
{
    return this->b;
}

double sinus::getF()
{
    return this->f;
}

double sinus::getFi()
{
    return this->fi;
}

double sinus::obliczY()
{
    double y;

    y = a * sin((2 * 3.14 * getX() * fi)) + b;

    return y;
}

sinus::sinus(double n_x, double n_a, double n_b, double n_f, double n_fi)
{
    setX(n_x);
    setA(n_a);
    setB(n_b);
    setF(n_f);
    setFi(n_fi);
}

double pierwiastek::getA()
{
    return this->a;
}

double pierwiastek::getD()
{
    return this->d;
}

double pierwiastek::obliczY()
{
    double y;

    y = a * sqrt(getX()) + d;

    return y;
}

pierwiastek::pierwiastek(double n_x, double n_a, double n_d)
{
    setX(n_x);
    setA(n_a);
    setD(n_d);
}
