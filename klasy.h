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
    double x, y, a, b, c, d, Fi, f;
public:
    void setX(double n_x);
    void setY(double n_y);
    void setA(double n_a);
    void setB(double n_b);
    void setC(double n_c);
    void setD(double n_d);
    void setF(double n_f);
    void setFi(double n_fi);


    double getX();
    double getY();
};

class liniowa : public Funkcje
{
private:

public:
    double obliczY();

    double getA();
    double getB();

    liniowa(double x, double a, double b);
};

class logarytmiczna : public Funkcje
{
private:

public:
    double getA();
    double getB();
    double getC();

    double obliczY();

    logarytmiczna(double n_x, double n_a, double n_b, double n_c);
};

class sinus : public Funkcje
{
private:

public:
    double getA();
    double getB();
    double getF();
    double getFi();

    double obliczY();

    sinus(double n_x, double n_a, double n_b, double n_f, double n_fi);
};

class pierwiastek : public Funkcje
{
private:

public:
    double getA();
    double getD();

    double obliczY();

    pierwiastek(double n_x, double n_a, double n_d);
};

#endif // KLASY_H