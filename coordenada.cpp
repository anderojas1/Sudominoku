#include "coordenada.hpp"

Coordenada::Coordenada(int x, int y)
{
    this->x=x;
    this->y=y;

}

Coordenada::~Coordenada(){

}

void Coordenada::setx(int x){
    this->x=x;
}

void Coordenada::sety(int y){
    this->y=y;
}

int Coordenada::getx(){
    return x;
}
int Coordenada::gety(){
    return y;
}
