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
        h.velocidad.y = 0.0f;
        return true;
    }
    if (h.posicion.x < xmin && h.posicion.y < ymin)
    {
        h.posicion.x = xmin;
        h.posicion.y = ymin;
        h.velocidad.y = 0.0f;
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
        h.velocidad.y = 0.0f;
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

    //Cayendo
    if (resultado && h.posicion.y+0.8 > p.dim.limtop1.y && h.velocidad.y<=0.0f)
    {
        h.setPos(h.getPos().x, p.dim.limtop1.y );
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

bool Interaccion::colision(Disparo d, Enemigo e)
{
    bool resultado = true;
    if (d.dim.limtop1.x >= e.dim.limtop2.x)
        resultado = false;
    else if (d.dim.limtop2.x <= e.dim.limtop1.x)
        resultado = false;
    else if (d.dim.limbot1.y >= e.dim.limtop1.y)
        resultado = false;
    else if (d.dim.limtop1.y <= e.dim.limbot1.y)
        resultado = false;
    return resultado;
}

bool Interaccion::colision(Hombre &h, Enemigo e)
{
    bool resultado = true;
    if (h.dim.limtop1.x >= e.dim.limtop2.x)
        resultado = false;
    else if (h.dim.limtop2.x <= e.dim.limtop1.x)
        resultado = false;
    else if (h.dim.limbot1.y >= e.dim.limtop1.y)
        resultado = false;
    else if (h.dim.limtop1.y <= e.dim.limbot1.y)
        resultado = false;

    //Cayendo
    if (resultado && h.posicion.y + 0.8 > e.dim.limtop1.y)
    {
        h.setPos(h.getPos().x, e.dim.limtop1.y);
        h.setVel(h.getVel().x, 10.0f);
        return resultado;
    }
    //Saltando
    if (resultado && h.posicion.y < e.dim.limbot1.y)
    {
        h.setPos(h.getPos().x, e.dim.limbot1.y - 2.0f);
        return resultado;
    }
    //hacia la derecha
    if (resultado && h.posicion.x < e.dim.limtop1.x)
    {
        h.setPos(e.dim.limtop1.x - 0.6f, h.getPos().y);
        h.setVel(-5.0f, h.getVel().y);
        return resultado;
    }
    //hacia la izquierda
    if (resultado && h.posicion.x > e.dim.limtop2.x)
    {
        h.setPos(e.dim.limtop2.x + 0.6f, h.getPos().y);
        h.setVel(5.0f, h.getVel().y);
        return resultado;
    }
    return resultado;
}

bool Interaccion::colision(Hombre& h, Obstaculo o)
{
    bool resultado = true;
    if (h.dim.limtop1.x >= o.dim.limtop2.x)
        resultado = false;
    else if (h.dim.limtop2.x <= o.dim.limtop1.x)
        resultado = false;
    else if (h.dim.limbot1.y >= o.dim.limtop1.y)
        resultado = false;
    else if (h.dim.limtop1.y <= o.dim.limbot1.y)
        resultado = false;
    //Cayendo
    if (resultado && h.posicion.y + 0.8 > o.dim.limtop1.y)
    {
        h.setPos(h.getPos().x, o.dim.limtop1.y);
        h.setVel(h.getVel().x, 10.0f);
        return resultado;
    }
    //Saltando
    if (resultado && h.posicion.y < o.dim.limbot1.y)
    {
        h.setPos(h.getPos().x, o.dim.limbot1.y - 2.0f);
        return resultado;
    }
    //hacia la derecha
    if (resultado && h.posicion.x < o.dim.limtop1.x)
    {
        h.setPos(o.dim.limtop1.x - 0.6f, h.getPos().y);
        h.setVel(-5.0f, h.getVel().y);
        return resultado;
    }
    //hacia la izquierda
    if (resultado && h.posicion.x > o.dim.limtop2.x)
    {
        h.setPos(o.dim.limtop2.x + 0.6f, h.getPos().y);
        h.setVel(5.0f, h.getVel().y);
        return resultado;
    }
    return resultado;
}

bool Interaccion::colision(Hombre& h, Bonus b)
{
    bool resultado = true;
    if (h.dim.limtop1.x >= b.dim.limtop2.x)
        resultado = false;
    else if (h.dim.limtop2.x <= b.dim.limtop1.x)
        resultado = false;
    else if (h.dim.limbot1.y >= b.dim.limtop1.y)
        resultado = false;
    else if (h.dim.limtop1.y <= b.dim.limbot1.y)
        resultado = false;
    return resultado;
}

