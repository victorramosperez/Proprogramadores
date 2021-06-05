#include "Interaccion.h"
#include "Dimensiones.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

bool Interaccion::colision(Obstaculo o, Hombre h)
{
    if (o.dim.limbot1.x < h.dim.limbot1.x < o.dim.limbot2.x
        && o.dim.limbot1.y < h.dim.limbot1.y < o.dim.limtop1.y)
        return true;
    if (o.dim.limbot1.x < h.dim.limbot2.x < o.dim.limbot2.x
        && o.dim.limbot1.y < h.dim.limbot2.y < o.dim.limtop1.y)
        return true;
    if (o.dim.limbot1.x < h.dim.limtop1.x < o.dim.limbot2.x
        && o.dim.limbot1.y < h.dim.limtop1.y < o.dim.limtop1.y)
        return true;
    if (o.dim.limbot1.x < h.dim.limtop2.x < o.dim.limbot2.x
        && o.dim.limbot1.y < h.dim.limtop2.y < o.dim.limtop1.y)
        return true;
    return false;
}
