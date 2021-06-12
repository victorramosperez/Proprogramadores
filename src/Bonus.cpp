#include "Bonus.h"
#include "freeglut.h"

Bonus::Bonus()
{
    lado = 0.2f;
}
Bonus::Bonus(float ix, float iy)
{
    lado = 0.4f;
    posicion.x = ix;
    posicion.y = iy;

    dim.limbot1.x = posicion.x - lado;
    dim.limbot1.y = posicion.y - lado;
    dim.limbot2.x = posicion.x + lado;
    dim.limbot2.y = posicion.y - lado;
    dim.limtop1.x = posicion.x - lado;
    dim.limtop1.y = posicion.y + lado;
    dim.limtop2.x = posicion.x + lado;
    dim.limtop2.y = posicion.y + lado;
}
Bonus::~Bonus()
{
}

void Bonus::dibuja()
{
    /*
    glDisable(GL_LIGHTING);
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3d(dim.limbot1.x, dim.limbot1.y, 9.9f);
    glVertex3d(dim.limtop1.x, dim.limtop1.y, 9.9f);
    glVertex3d(dim.limtop2.x, dim.limtop2.y, 9.9f);
    glVertex3d(dim.limbot2.x, dim.limbot1.y, 9.9f);
    glEnd();
    glEnable(GL_LIGHTING);

    glPushMatrix();
    glTranslatef(dim.limbot1.x, dim.limbot1.y, 10);
    glColor3f(1.0f, 0.0f, 0.0f);
    sprite.draw();
    glPopMatrix();*/
}


void Bonus::setPos(float ix, float iy)
{
    posicion.x = ix;
    posicion.y = iy;
}

Dimensiones Bonus::getDim()
{
    return dim;
}