#include "klasy.h"

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

double liniowa::setB(double n_b)
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

liniowa::liniowa(double x, double a, double b)
{
    setX(x);
    setA(a);
    setB(b);
}