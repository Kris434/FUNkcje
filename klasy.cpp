#include "klasy.h"
#include "mainwindow.h"
#include "qcustomplot.h"
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

void Wykres::setX(double n_x)
{
    this->x = n_x;
}

double Wykres::getSkalaX()
{
    return this->skalaX;
}

double Wykres::getSkalaY()
{
    return this->skalaY;
}

Wykres::Wykres(double s_x, double s_y)
{
    setSkala(s_x, s_y);
}

void Funkcje::setA(double n_a)
{
    this->a = n_a;
}

void Funkcje::setB(double n_b)
{
    this->b = n_b;
}

double Funkcje::getA()
{
    return this->a;
}

double Funkcje::getB()
{
    return this->b;
}

double liniowa::obliczY(double n_x)
{
    double y;

    y = getA() * n_x + getB();

    return y;
}

liniowa::liniowa(double a, double b)
{
    setA(a);
    setB(b);
}

void logarytmiczna::setC(double n_c)
{
    this->c = n_c;
}

double logarytmiczna::getC()
{
    return this->c;
}

double logarytmiczna::obliczY(double x)
{
    double y;

    y = getA() * (log10(x) / log10(getB())) + getC();

    return y;
}

logarytmiczna::logarytmiczna(double n_a, double n_b, double n_c)
{
    setA(n_a);
    setB(n_b);
    setC(n_c);
}

void sinus::setF(double n_f)
{
    this->f = n_f;
}

void sinus::setFi(double n_fi)
{
    this->Fi = n_fi;
}

double sinus::getF()
{
    return this->f;
}

double sinus::getFi()
{
    return this->Fi;
}

double sinus::obliczY(double x)
{
    double y;

    y = getA() * sin((2 * 3.14 * getF() * x + getFi())) + getB();

    return y;
}

sinus::sinus(double n_a, double n_b, double n_f, double n_fi)
{
    setA(n_a);
    setB(n_b);
    setF(n_f);
    setFi(n_fi);
}

double pierwiastek::obliczY(double x)
{
    double y;

    y = getA() * sqrt(x) + getB();

    return y;
}

pierwiastek::pierwiastek(double n_a, double n_b)
{
    setA(n_a);
    setB(n_b);
}
