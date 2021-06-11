#include "Hombre.h"
#include "freeglut.h"

Hombre::Hombre()
{
    aceleracion.x = 0.0f;
    aceleracion.y = -19.6f;
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

    glDisable(GL_LIGHTING);
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3d(dim.limbot1.x, dim.limbot1.y,10.2f);
    glVertex3d(dim.limtop1.x, dim.limtop1.y, 10.2f);
    glVertex3d(dim.limtop2.x, dim.limtop2.y, 10.2f);
    glVertex3d(dim.limbot2.x, dim.limbot1.y, 10.2f);
    glEnd();
    glEnable(GL_LIGHTING);
}

void Hombre::mueve(float t)
{
    //dim.limtop1 = (posicion.x - 0.25f, posicion.y + 0.9f);
    dim.limtop1.x = posicion.x - 0.6f;
    dim.limtop1.y = posicion.y + 1.8f;
    //dim.limtop2 = (posicion.x + 0.25f, posicion.y + 0.9f);
    dim.limtop2.x = posicion.x + 0.6f;
    dim.limtop2.y = posicion.y + 1.8f;
    //dim.limbot1 = (posicion.x - 0.25f, posicion.y - 0.9f);
    dim.limbot1.x = posicion.x - 0.6f;
    dim.limbot1.y = posicion.y-0.3f;
    //dim.limbot2 = (posicion.x + 0.25f, posicion.y - 0.9f);
    dim.limbot2.x = posicion.x + 0.6f;
    dim.limbot2.y = posicion.y-0.3f;
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    if (velocidad.y >= -7.5f)
        velocidad = velocidad + aceleracion * t;
    else velocidad.y = -7.5f;
    sprite.loop();
    
}
void Hombre::setPos(float ix, float iy)
{
    posicion.x = ix;
    posicion.y = iy;
}
void Hombre::setVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

float Hombre::getAltura()
{
    return altura;
}

Vector2D Hombre::getVel()
{
    return velocidad;
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