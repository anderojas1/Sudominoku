#ifndef COORDENADA_H
#define COORDENADA_H


class Coordenada
{

private:

    int x;
    int y;

public:
    Coordenada(int x, int y);
    ~Coordenada();


    void setx(int x);
    void sety(int y);
    int getx();
    int gety();
};

#endif // COORDENADA_H
