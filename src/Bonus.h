#pragma once

#include "Dimensiones.h"
#include "ObjetoMovil.h"

class Bonus
{
protected:
    float lado;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    Dimensiones dim;
public:
    Bonus();
    ~Bonus();
    void dibuja();
    void mueve(float t);
    void setPos(float ix, float iy);
    Dimensiones getDim();
};
