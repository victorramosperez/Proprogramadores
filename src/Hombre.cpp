#include "Hombre.h"
#include "freeglut.h"

Hombre::Hombre()
{
    aceleracion.x = aceleracion.y = 0;
    Altura = 1.8f;
    sprite.setCenter(1, 0);
    sprite.setSize(2, 2);
    Vida = 1;
    Vivo = true;
}

Hombre::~Hombre()
{
}

void Hombre::dibuja()
{
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 10);
    glColor3f(1.0f, 0.0f, 0.0f);
    //glutSolidSphere(Altura, 20, 20);
    //gestion de direccion y animacion
    if (velocidad.x > 0.01)sprite.flip(false, false);
    if (velocidad.x < -0.01)sprite.flip(true, false);
    if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
        sprite.setState(0);
    else if (sprite.getState() == 0)
        sprite.setState(1, false);
    sprite.draw();
    glPopMatrix();
}

void Hombre::mueve(float t)
{
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
    sprite.loop();
}

void Hombre::setVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

float Hombre::getAltura()
{
    return Altura;
}

Vector2D Hombre::getPos()
{
    return posicion;
}

Dimensiones Hombre::getDim()
{
    return dim;
}
/*
bool Hombre::cogerBonus(Bonus b)
{
    if (Interaccion::colision(b, h))
    {
        Vida += 1;
        return true;
    }
    return false;
}


bool Hombre::recibeDano(Obstaculo o)
{
    if (Interaccion::colision(o, h))
    {
        Vida -= 1;
        return true;
    }
    return false;
}*/