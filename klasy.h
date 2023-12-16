#ifndef KLASY_H
#define KLASY_H

enum class typFunkcji
{
    liniowa,
    logarytmiczna,
    pierwiastkowa,
    sinus
};

class Wykres
{
private:
    double skalaX;
    double skalaY;
    typFunkcji typ;

public:
    void setSkala(double x, double y);

    double getSkalaX();
    double getSkalaY();

    void rysujWykres();

    Wykres(double x, double y, typFunkcji t);
};

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
private:
    double a;
    double b;
    double c;

public:
    void setA(double n_a);
    void setB(double n_b);
    void setC(double n_c);

    double getA();
    double getB();
    double getC();

    double obliczY();
};

class sinus : public Funkcje
{
private:
    double a;
    double b;
    double f;
    double fi;

public:
    void setA(double n_a);
    void setB(double n_b);
    void setF(double n_f);
    void setFi(double n_fi);

    double getA();
    double getB();
    double getF();
    double getFi();

    double obliczY();
};

class pierwiastek : public Funkcje
{
private:
    double a;
    double d;

public:
    void setA(double n_a);
    void setD(double n_d);

    double getA();
    double getD();

    double obliczY();
};

#endif // KLASY_H