#pragma once
#include "Enemigo.h"
#include "hombre.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class EnemigoBoss :
    public Enemigo
{
public:
    EnemigoBoss(float ix, float iy, float ixmin, float ixmax):Enemigo(ix, iy, ixmin,ixmax){
        sprite.setCenter(1, 0);
        dim.limbot1 = dim.limbot1 *2.0f;
        dim.limbot2 = dim.limbot2 * 2.0f;
        dim.limtop1 = dim.limtop1 * 2.0f;
        dim.limtop2 = dim.limtop2 * 2.0f;
        sprite.setSize(dim.limbot2.x - dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
    }
    SpriteSequence sprite{"imagenes/boss4.png", 4 };
    void mueve(float t);
    void dibuja();
};

