#pragma once

#include "Dimensiones.h"
#include "ObjetoMovil.h"

class Bonus
{
protected:
    float lado;
    Vector2D posicion;
    Dimensiones dim;
public:
    Bonus();
    Bonus(float ix, float iy);
    ~Bonus();
    void dibuja();
    void setPos(float ix, float iy);
    Dimensiones getDim();
    friend class Interaccion;
};
