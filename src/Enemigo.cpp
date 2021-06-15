#include "Enemigo.h"
#include "freeglut.h"
Enemigo::Enemigo()
{
	Direccion = 0;
	Vivo = true;
	Vida = 0;
    	aceleracion.x = aceleracion.y = 0;
    	Altura = 1.8f;
   	sprite.setCenter(1, 0);
    	sprite.setSize(2, 2);
   
}

Enemigo::Enemigo(float ix, float iy, float ixmin, float ixmax)
{
    Direccion = 0;
    Vivo = true;
    Vida = 0;
    velocidad.x = 2.5f;
    aceleracion.x = aceleracion.y = 0;
    Altura = 1.8f;
    posicion.x = ix;
    posicion.y = iy;
    sprite.setCenter(1, 0);
    sprite.setSize(2, 2);
    xmax = ixmax;
    xmin = ixmin;
    //dim.limtop1 = (posicion.x - 0.25f, posicion.y + 0.9f);
    dim.limtop1.x = posicion.x - 1.0f;
    dim.limtop1.y = posicion.y + 2.0f;
    //dim.limtop2 = (posicion.x + 0.25f, posicion.y + 0.9f);
    dim.limtop2.x = posicion.x + 1.0f;
    dim.limtop2.y = posicion.y + 2.0f;
    //dim.limbot1 = (posicion.x - 0.25f, posicion.y - 0.9f);
    dim.limbot1.x = posicion.x - 1.0f;
    dim.limbot1.y = posicion.y;//-0.3f
    //dim.limbot2 = (posicion.x + 0.25f, posicion.y - 0.9f);
    dim.limbot2.x = posicion.x + 1.0f;
    dim.limbot2.y = posicion.y;//
}

Enemigo::~Enemigo()
{

}

void Enemigo::dibuja()
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

    //dim.limtop1 = (posicion.x - 0.25f, posicion.y + 0.9f);
    dim.limtop1.x = posicion.x - 1.0f;
    dim.limtop1.y = posicion.y + 2.0f;
    //dim.limtop2 = (posicion.x + 0.25f, posicion.y + 0.9f);
    dim.limtop2.x = posicion.x + 1.0f;
    dim.limtop2.y = posicion.y + 2.0f;
    //dim.limbot1 = (posicion.x - 0.25f, posicion.y - 0.9f);
    dim.limbot1.x = posicion.x - 1.0f;
    dim.limbot1.y = posicion.y;//-0.3f
    //dim.limbot2 = (posicion.x + 0.25f, posicion.y - 0.9f);
    dim.limbot2.x = posicion.x + 1.0f;
    dim.limbot2.y = posicion.y;//
	/*
    glDisable(GL_LIGHTING);
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3d(dim.limbot1.x, dim.limbot1.y, 9.9f);
    glVertex3d(dim.limtop1.x, dim.limtop1.y, 9.9f);
    glVertex3d(dim.limtop2.x, dim.limtop2.y, 9.9f);
    glVertex3d(dim.limbot2.x, dim.limbot1.y, 9.9f);
    glEnd();
    glEnable(GL_LIGHTING);*/
}

void Enemigo::mueve(float t)
{
    if (dim.limbot1.x <= xmin)
        velocidad.x = 2.5f;
    if (dim.limbot2.x >= xmax)
        velocidad.x = -2.5f;
    posicion = posicion + velocidad * t;
    sprite.loop();
}
