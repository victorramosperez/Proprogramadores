#pragma once
#include "Plataforma.h"
using ETSIDI::SpriteSequence;
class PlataformaPuerta : public Plataforma
{
public:
    PlataformaPuerta(float x1, float y1, float x2, float y2) :Plataforma(x1, y1, x2, y2) {
        sprite.setCenter(0, 0);
        sprite.setSize(limite2.x - limite1.x, limite2.y - limite1.y);
    };
    SpriteSequence sprite{ "imagenes/puerta.png", 1 };
    void dibuja();
};

