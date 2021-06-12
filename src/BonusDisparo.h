#pragma once
#include "Bonus.h"
using ETSIDI::SpriteSequence;
class BonusDisparo :
    public Bonus
{
public:
    BonusDisparo();
    BonusDisparo(float ix, float iy) :Bonus(ix, iy) {
        sprite.setCenter(0, 0);
        sprite.setSize(dim.limbot2.x - dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
        identificador = 2;
    };
    SpriteSequence sprite{ "imagenes/bonus.png", 1 };
    void dibuja();
};

