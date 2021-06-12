#pragma once
#include "Bonus.h"
using ETSIDI::SpriteSequence;

class BonusVida :
    public Bonus
{
public:
    BonusVida();
    BonusVida(float ix, float iy) :Bonus(ix, iy) {
        sprite.setCenter(0, 0);
        sprite.setSize(dim.limbot2.x - dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
    };
    SpriteSequence sprite{ "imagenes/bonus2.png", 1 };
    void dibuja();
};

