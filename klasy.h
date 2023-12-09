#ifndef KLASY_H
#define KLASY_H

class Funkcje
{
private:
    double x;
    double y;
public:
    double getX()
    {
        return this->x;
    }

    double getY()
    {
        return this->y;
    }
};

class liniowa : public Funkcje
{
private:
    double a;
    double b;

public:
    double getA()
    {
        return this->a;
    }

    double getB()
    {
        return this->b;
    }
};

#endif // KLASY_H
