#ifndef FICHA_H
#define FICHA_H


class Ficha
{
public:
    Ficha(int num1, int num2);
    ~Ficha();
    int getNumero1();
    int getNumero2();

private:
    int numero1;
    int numero2;
};

#endif // FICHA_H
