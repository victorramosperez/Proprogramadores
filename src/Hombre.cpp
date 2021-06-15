#include "Hombre.h"
#include "freeglut.h"

Hombre::Hombre()
{
    aceleracion.x = 0.0f;
    aceleracion.y = -19.6f;
    sprite.setCenter(1, 0);
    sprite.setSize(2, 2);
    vida = 1;
    vivo = true;
}

Hombre::~Hombre()
{
}

void Hombre::dibuja()
{
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 10);
    glColor3f(1.0f, 0.0f, 0.0f);

    //gestion de direccion y animacion
    if (velocidad.x > 0.01)sprite.flip(false, false);
    if (velocidad.x < -0.01)sprite.flip(true, false);
    if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
        sprite.setState(0);
    else if (sprite.getState() == 0)
        sprite.setState(1, false);
    sprite.draw();
    glPopMatrix();

    /*//POLIGONO DE DIMENSIONES
    glDisable(GL_LIGHTING);
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3d(dim.limbot1.x, dim.limbot1.y,9.9f);
    glVertex3d(dim.limtop1.x, dim.limtop1.y, 9.9f);
    glVertex3d(dim.limtop2.x, dim.limtop2.y, 9.9f);
    glVertex3d(dim.limbot2.x, dim.limbot1.y, 9.9f);
    glEnd();
    glEnable(GL_LIGHTING);*/
}

void Hombre::mueve(float t)
{
    //AJUSTE DE LOS LIMITES AL SPRITE
    dim.limtop1.x = posicion.x - 0.6f;
    dim.limtop1.y = posicion.y + 1.8f;
    
    dim.limtop2.x = posicion.x + 0.6f;
    dim.limtop2.y = posicion.y + 1.8f;
    
    dim.limbot1.x = posicion.x - 0.6f;
    dim.limbot1.y = posicion.y;
    
    dim.limbot2.x = posicion.x + 0.6f;
    dim.limbot2.y = posicion.y;

    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    if (velocidad.y >= -7.5f)
        velocidad = velocidad + aceleracion * t;
    else velocidad.y = -7.5f;
    sprite.loop();
}
