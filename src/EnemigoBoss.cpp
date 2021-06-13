#include "EnemigoBoss.h"

void EnemigoBoss::mueve(float t)
{
	posicion = posicion + velocidad * t;

    //dim.limtop1 = (posicion.x - 0.25f, posicion.y + 0.9f);
    dim.limtop1.x = posicion.x - 2.0f;
    dim.limtop1.y = posicion.y + 4.0f;
    //dim.limtop2 = (posicion.x + 0.25f, posicion.y + 0.9f);
    dim.limtop2.x = posicion.x + 2.0f;
    dim.limtop2.y = posicion.y + 4.0f;
    //dim.limbot1 = (posicion.x - 0.25f, posicion.y - 0.9f);
    dim.limbot1.x = posicion.x - 2.0f;
    dim.limbot1.y = posicion.y;//-0.3f
    //dim.limbot2 = (posicion.x + 0.25f, posicion.y - 0.9f);
    dim.limbot2.x = posicion.x + 2.0f;
    dim.limbot2.y = posicion.y;//
    sprite.loop();
}

void EnemigoBoss::dibuja()
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
    glVertex3d(dim.limbot1.x, dim.limbot1.y, 10.2f);
    glVertex3d(dim.limtop1.x, dim.limtop1.y, 10.2f);
    glVertex3d(dim.limtop2.x, dim.limtop2.y, 10.2f);
    glVertex3d(dim.limbot2.x, dim.limbot1.y, 10.2f);
    glEnd();
    glEnable(GL_LIGHTING);
}

