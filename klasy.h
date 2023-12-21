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
    double a, b;
public:
    void setA(double n_a);
    void setB(double n_b);

    double getA();
    double getB();

};

class liniowa : public Funkcje
{
private:
    double a, b;
public:
    double obliczY(double n_x);

    liniowa(double a, double b);
};

class logarytmiczna : public Funkcje
{
private:
    double c;
public:
    double obliczY(double x);

    void setC(double n_c);

    double getC();

    logarytmiczna(double n_a, double n_b, double n_c);
};

class sinus : public Funkcje
{
private:
    double f, Fi;
public:
    double obliczY(double x);

    void setF(double n_f);
    void setFi(double n_fi);

    double getF();
    double getFi();

    sinus(double n_a, double n_b, double n_f, double n_fi);
};

class pierwiastek : public Funkcje
{
private:

public:
    double obliczY(double x);

    pierwiastek(double n_a, double n_b);
};

#endif // KLASY_H
