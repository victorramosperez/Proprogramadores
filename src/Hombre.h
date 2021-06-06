#pragma once
#include "Dimensiones.h"
#include "ObjetoMovil.h"
#include "Bonus.h"
#include "Obstaculo.h"

class Hombre :public ObjetoMovil
{
protected:
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    Dimensiones dim;
    float Altura;
    int Vida;
    bool Vivo;

public:
    Hombre();
    ~Hombre();
    void dibuja();
    void mueve(float t);
    void setVel(float vx, float vy);
    float getAltura();
    Vector2D getPos();
    Dimensiones getDim();
    //bool cogerBonus(Bonus b);
    //bool recibeDano(Obstaculo o);

    friend class Interaccion;
};