#pragma once
#include "Bonus.h"
using ETSIDI::SpriteSequence;
class BonusLlave :
    public Bonus
{
public:
    BonusLlave();
    BonusLlave(float ix, float iy) :Bonus(ix, iy) {
        sprite.setCenter(0, 0);
        sprite.setSize(dim.limbot2.x - dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
        identificador = 3;
    };
    SpriteSequence sprite{ "imagenes/llave.png", 1 };
    void dibuja();
};

