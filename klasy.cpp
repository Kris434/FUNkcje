#include "klasy.h"
#include <cmath>

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

void liniowa::setA(double n_a)
{
    this->a = n_a;
}

void liniowa::setB(double n_b)
{
    this->b = n_b;
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

void logarytmiczna::setA(double n_a)
{
    this->a = n_a;
}

void logarytmiczna::setB(double n_b)
{
    this->b = n_b;
}

void logarytmiczna::setC(double n_c)
{
    this->c = n_c;
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

void sinus::setA(double n_a)
{
    this->a = n_a;
}

void sinus::setB(double n_b)
{
    this->b = n_b;
}

void sinus::setF(double n_f)
{
    this->f = n_f;
}

void sinus::setFi(double n_fi)
{
    this->fi = n_fi;
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

void pierwiastek::setA(double n_a)
{
    this->a = n_a;
}

void pierwiastek::setD(double n_d)
{
    this->d = n_d;
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