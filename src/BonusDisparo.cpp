#include "BonusDisparo.h"

BonusDisparo::BonusDisparo()
{
    sprite.setCenter(0, 0);
    sprite.setSize(dim.limbot2.x - dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
    
}

void BonusDisparo::dibuja()
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
    glEnable(GL_LIGHTING);*/

    glPushMatrix();
    glTranslatef(dim.limbot1.x, dim.limbot1.y, 10);
    glColor3f(1.0f, 0.0f, 0.0f);
    sprite.draw();
    glPopMatrix();
}
