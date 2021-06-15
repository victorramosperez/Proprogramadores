#include "EnemigoBoss.h"

void EnemigoBoss::mueve(float t)
{
	posicion = posicion + velocidad * t;
    //AJUSTE DE LOS LIMITES AL SPRITE
    dim.limtop1.x = posicion.x - 1.2f;
    dim.limtop1.y = posicion.y + 5.1f;

    dim.limtop2.x = posicion.x + 2.5f;
    dim.limtop2.y = posicion.y + 5.1f;

    dim.limbot1.x = posicion.x - 1.2f;
    dim.limbot1.y = posicion.y;
   
    dim.limbot2.x = posicion.x + 2.5f;
    dim.limbot2.y = posicion.y;
    sprite.loop();
}

void EnemigoBoss::dibuja()
{
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 10.2);
    glColor3f(1.0f, 0.0f, 0.0f);
    //gestion de direccion y animacion
    if (velocidad.x < 0.01)sprite.flip(false, false);
    if (velocidad.x > -0.01)sprite.flip(true, false);
    if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
        sprite.setState(0);
    else if (sprite.getState() == 0)
        sprite.setState(1, false);
    sprite.draw();
    glPopMatrix();

    /*//POLIGONO DE LIMITES
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

