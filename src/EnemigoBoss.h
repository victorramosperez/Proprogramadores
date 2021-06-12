#pragma once
#include "Enemigo.h"
#include "hombre.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class EnemigoBoss :
    public Enemigo
{
public:
    EnemigoBoss(float ix, float iy, float ixmin, float ixmax):Enemigo(ix, iy, ixmin,ixmax){}
    SpriteSequence sprite{ "imagenes/enemigo8.png", 3 };
    void mueve(float t);
};

