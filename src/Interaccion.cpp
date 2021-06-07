#include "Interaccion.h"
#include "Dimensiones.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}
void Interaccion::rebote(Hombre& h, Caja c)
{
	float xmax = c.suelo.limite2.x;
	float xmin = c.suelo.limite1.x;
	if (h.posicion.x > xmax)h.posicion.x = xmax;
	if (h.posicion.x < xmin)h.posicion.x = xmin;
}
bool Interaccion::colision(Obstaculo o, Hombre h)
{
    if (o.getDim().limbot1.x < h.getDim().limbot1.x < o.getDim().limbot2.x
        && o.getDim().limbot1.y < h.getDim().limbot1.y < o.getDim().limtop1.y)
        return true;
    if (o.getDim().limbot1.x < h.getDim().limbot2.x < o.getDim().limbot2.x
        && o.getDim().limbot1.y < h.getDim().limbot2.y < o.getDim().limtop1.y)
        return true;
    if (o.getDim().limbot1.x < h.getDim().limtop1.x < o.getDim().limbot2.x
        && o.getDim().limbot1.y < h.getDim().limtop1.y < o.getDim().limtop1.y)
        return true;
    if (o.getDim().limbot1.x < h.getDim().limtop2.x < o.getDim().limbot2.x
        && o.getDim().limbot1.y < h.getDim().limtop2.y < o.getDim().limtop1.y)
        return true;
    return false;
}
bool Interaccion::colision(Bonus b, Hombre h)
{
    if (b.getDim().limbot1.x < h.getDim().limbot1.x < b.getDim().limbot2.x
        && b.getDim().limbot1.y < h.getDim().limbot1.y < b.getDim().limtop1.y)
        return true;
    if (b.getDim().limbot1.x < h.getDim().limbot2.x < b.getDim().limbot2.x
        && b.getDim().limbot1.y < h.getDim().limbot2.y < b.getDim().limtop1.y)
        return true;
    if (b.getDim().limbot1.x < h.getDim().limtop1.x < b.getDim().limbot2.x
        && b.getDim().limbot1.y < h.getDim().limtop1.y < b.getDim().limtop1.y)
        return true;
    if (b.getDim().limbot1.x < h.getDim().limtop2.x < b.getDim().limbot2.x
        && b.getDim().limbot1.y < h.getDim().limtop2.y < b.getDim().limtop1.y)
        return true;
    return false;
}