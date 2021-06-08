#include "Interaccion.h"
#include "Dimensiones.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}
bool Interaccion::rebote(Hombre& h, Caja c)
{
	float xmax = c.suelo.limite2.x;
	float xmin = c.suelo.limite1.x;
    float ymin = c.suelo.limite1.y;
    if (h.posicion.x > xmax)
    {
        h.posicion.x = xmax;
        return true;
    }
	if (h.posicion.x < xmin)
    {
        h.posicion.x = xmin;
        return true;
    }
    if (h.posicion.y < ymin)
    {
        h.posicion.y = ymin;
        return true;
    }
    return false;
}
bool Interaccion::rebote(Hombre& h, Plataforma& p)
{
    if (p.getDim().limbot1.x < h.getDim().limbot1.x < p.getDim().limbot2.x
        && p.getDim().limbot1.y < h.getDim().limbot1.y < p.getDim().limtop1.y)
    {
        h.setVel(0, h.getVel().y);
        return true;
    }
    if (p.getDim().limbot1.x < h.getDim().limbot2.x < p.getDim().limbot2.x
        && p.getDim().limbot1.y < h.getDim().limbot2.y < p.getDim().limtop1.y)
    {
        h.setVel(0, h.getVel().y);
        return true;
    }
    if (p.getDim().limbot1.x < h.getDim().limtop1.x < p.getDim().limbot2.x
        && p.getDim().limbot1.y < h.getDim().limtop1.y < p.getDim().limtop1.y)
    {
        h.setVel(h.getVel().x, 0);
        return true;
    }
    if (p.getDim().limbot1.x < h.getDim().limtop2.x < p.getDim().limbot2.x
        && p.getDim().limbot1.y < h.getDim().limtop2.y < p.getDim().limtop1.y)
    {
        h.setVel(h.getVel().x, 0);
        return true;
    }
    return false;
    /*float xmax = p.dim.limtop2.x;
    float xmin = p.dim.limtop1.x;
    float ymax = p.dim.limtop2.y;
    float ymin = p.dim.limbot2.y;
   
    if (h.posicion.y > ymax)
    {
        h.posicion.y = ymax;
        return true;
    }
    return false;*/
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