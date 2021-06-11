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
    if (h.posicion.x > xmax && h.posicion.y< ymin)
    {
        h.posicion.x = xmax;
        h.posicion.y = ymin;
        return true;
    }
    if (h.posicion.x < xmin && h.posicion.y < ymin)
    {
        h.posicion.x = xmin;
        h.posicion.y = ymin;
        return true;
    }
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
    
    bool resultado=true;
    if (h.dim.limtop1.x >= p.dim.limtop2.x)
    resultado=false;
    else if (h.dim.limtop2.x <= p.dim.limtop1.x)
    resultado=false;
    else if (h.dim.limbot1.y >= p.dim.limtop1.y)
    resultado=false;
    else if (h.dim.limtop1.y <= p.dim.limbot1.y)
    resultado=false;
    
    /*
    bool resultado = false;
    if (p.getDim().limbot1.x < h.getDim().limbot1.x < p.getDim().limbot2.x
        && p.getDim().limbot1.y < h.getDim().limbot1.y < p.getDim().limtop1.y)
    {
        //h.setVel(0, h.getVel().y);
        resultado = true;
    }
    else if (p.getDim().limbot1.x < h.getDim().limbot2.x < p.getDim().limbot2.x
        && p.getDim().limbot1.y < h.getDim().limbot2.y < p.getDim().limtop1.y)
    {
        //h.setVel(0, h.getVel().y);
        resultado = true;
    }
    else if (p.getDim().limbot1.x < h.getDim().limtop1.x < p.getDim().limbot2.x
        && p.getDim().limbot1.y < h.getDim().limtop1.y < p.getDim().limtop1.y)
    {
        //h.setVel(h.getVel().x, 0);
        resultado = true;
    }
    else if (p.getDim().limbot1.x < h.getDim().limtop2.x < p.getDim().limbot2.x
        && p.getDim().limbot1.y < h.getDim().limtop2.y < p.getDim().limtop1.y)
    {
        //h.setVel(h.getVel().x, 0);
        resultado = true;
    }
    else resultado = false;
    //return false;
   */

    //Cayendo
    if (resultado && h.posicion.y > p.dim.limtop1.y)
    {
        h.setPos(h.getPos().x, p.dim.limtop1.y + 0.3f);
        h.setVel(h.getVel().x, 0.0f);
        return resultado;
    }
    //Saltando
    if (resultado && h.posicion.y < p.dim.limbot1.y)
    {
        h.setPos(h.getPos().x, p.dim.limbot1.y - 2.0f);
        h.setVel(h.getVel().x, 0.0f);
        return resultado;
    }
    //hacia la derecha
    if (resultado && h.posicion.x < p.dim.limtop1.x)
    {
        h.setPos(p.dim.limtop1.x-0.6f, h.getPos().y);
        h.setVel(0.0f, h.getVel().y);
        return resultado;
    }
    //hacia la izquierda
    if (resultado && h.posicion.x > p.dim.limtop2.x)
    {
        h.setPos(p.dim.limtop2.x+0.6f, h.getPos().y);
        h.setVel(0.0f, h.getVel().y);
        return resultado;
    }

    return resultado;
}
bool Interaccion::colision(Disparo d, Pared p)
{
    Vector2D dir;
    float dif = p.distancia(d.posicion, &dir) - d.radio;
    if (dif <= 0.0f)
    {
        return true;
    }
    return false;
}
bool Interaccion::colision(Disparo d, Caja c)
{
    if (Interaccion::colision(d, c.suelo) || Interaccion::colision(d, c.pared_izq) || Interaccion::colision(d, c.pared_dcha) || Interaccion::colision(d, c.techo))
        return true;
    return false;
}


bool Interaccion::colision(Disparo d, Plataforma p)
{
    bool resultado = true;
    if (d.dim.limtop1.x >= p.dim.limtop2.x)
        resultado = false;
    else if (d.dim.limtop2.x <= p.dim.limtop1.x)
        resultado = false;
    else if (d.dim.limbot1.y >= p.dim.limtop1.y)
        resultado = false;
    else if (d.dim.limtop1.y <= p.dim.limbot1.y)
        resultado = false;
    return resultado;
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

bool Interaccion::colision(Enemigo e, Hombre h)
{

    if (e.getDim().limbot1.x < h.getDim().limbot1.x < e.getDim().limbot2.x
        && e.getDim().limbot1.y < h.getDim().limbot1.y < e.getDim().limtop1.y)
        return true;
    if (e.getDim().limbot1.x < h.getDim().limbot2.x < e.getDim().limbot2.x
        && e.getDim().limbot1.y < h.getDim().limbot2.y < e.getDim().limtop1.y)
        return true;
    if (e.getDim().limbot1.x < h.getDim().limtop1.x < e.getDim().limbot2.x
        && e.getDim().limbot1.y < h.getDim().limtop1.y < e.getDim().limtop1.y)
        return true;
    if (e.getDim().limbot1.x < h.getDim().limtop2.x < e.getDim().limbot2.x
        && e.getDim().limbot1.y < h.getDim().limtop2.y < e.getDim().limtop1.y)
        return true;
    return false;
}
