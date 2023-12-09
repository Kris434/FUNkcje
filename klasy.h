#ifndef KLASY_H
#define KLASY_H

class Funkcje
{
private:
    double x;
    double y;
public:
    void setX(double n_x);
    void setY(double n_y);

    double getX();
    double getY();
};

class liniowa : public Funkcje
{
private:
    double a;
    double b;

public:
    double obliczY();

    void setA(double n_a);
    void setB(double n_a);

    double getA();
    double getB();

    liniowa(double x, double a, double b);
};

class logarytmiczna : public Funkcje
{
    
};

#endif // KLASY_H
