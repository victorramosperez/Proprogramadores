#pragma once
#include "Enemigo.h"
#include "hombre.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class EnemigoBoss :
    public Enemigo
{
public:
    EnemigoBoss(float ix, float iy, float ixmin, float ixmax) :Enemigo(ix, iy, ixmin, ixmax){
        sprite.setCenter(2.8, 0);
        dim.limbot1 = dim.limbot1 *2.8f;
        dim.limbot2 = dim.limbot2 * 2.8f;
        dim.limtop1 = dim.limtop1 * 2.8f;
        dim.limtop2 = dim.limtop2 * 2.8f;
        sprite.setSize(dim.limbot2.x - dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
        Vida = 20;
    }
    SpriteSequence sprite{"imagenes/jefe2.png", 8 };
    void mueve(float t);
    void dibuja();
};

