#include "PlataformaPuerta.h"

void PlataformaPuerta::dibuja()
{
	/*glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite1.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite1.y, 10);
	glEnd();
	glEnable(GL_LIGHTING);*/

	/*
	glDisable(GL_LIGHTING);
	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex3d(dim.limbot1.x, dim.limtop1.y, 10.2f);
	glVertex3d(dim.limbot1.x, dim.limtop2.y, 10.2f);
	glVertex3d(dim.limbot2.x, dim.limtop2.y, 10.2f);
	glVertex3d(dim.limbot2.x, dim.limtop1.y, 10.2f);
	glEnd();
	glEnable(GL_LIGHTING);*/

	
	glPushMatrix();
	glTranslatef(dim.limbot1.x, dim.limbot1.y, 7.1);
	glColor3f(1.0f, 0.0f, 0.0f);
	sprite.draw();
	glPopMatrix();
}
