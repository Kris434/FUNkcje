#ifndef KLASY_H
#define KLASY_H

class Wykres
{
private:
    double skalaX;
    double skalaY;
    double x;

public:
    void setSkala(double x, double y);
    void setX(double n_x);

    double getSkalaX();
    double getSkalaY();

    Wykres(double x, double y);
};

class Funkcje
{
private:
    double a, b, c, d, Fi, f;
public:
    void setA(double n_a);
    void setB(double n_b);
    void setC(double n_c);
    void setD(double n_d);
    void setF(double n_f);
    void setFi(double n_fi);

    double getA();
    double getB();
    double getC();
    double getD();
    double getF();
    double getFi();
};

class liniowa : public Funkcje
{
private:

public:
    double obliczY(double n_x);

    liniowa(double a, double b);
};

class logarytmiczna : public Funkcje
{
private:

public:
    double obliczY(double x);

    logarytmiczna(double n_a, double n_b, double n_c);
};

class sinus : public Funkcje
{
private:

public:
    double obliczY(double x);

    sinus(double n_a, double n_b, double n_f, double n_fi);
};

class pierwiastek : public Funkcje
{
private:

public:
    double obliczY(double x);

    pierwiastek(double n_a, double n_d);
};

#endif // KLASY_H
