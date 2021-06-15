#include "Obstaculo.h"
#include "ETSIDI.h"


Obstaculo::Obstaculo(float xmin, float ymin, float xmax, float ymax)
{
	dim.limbot1 = { xmin,ymin };
	dim.limbot2 = { xmax,ymin };
	dim.limtop1 = { xmin,ymax };
	dim.limtop2 = { xmax,ymax };
	sprite.setCenter(0, 0);
	sprite.setSize(dim.limbot2.x - dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
}


void Obstaculo::dibuja() {
	/*//POLIGONO DE DIMENSIONES
	glDisable(GL_LIGHTING);
	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex3d(dim.limbot1.x, dim.limbot1.y, 10.2f);
	glVertex3d(dim.limtop1.x, dim.limtop1.y, 10.2f);
	glVertex3d(dim.limtop2.x, dim.limtop2.y, 10.2f);
	glVertex3d(dim.limbot2.x, dim.limbot1.y, 10.2f);
	glEnd();
	glEnable(GL_LIGHTING);*/

	glPushMatrix();
	glTranslatef(dim.limbot1.x, dim.limbot1.y, 10);
	glColor3f(1.0f, 0.0f, 0.0f);
	sprite.draw();
	glPopMatrix();
}


Dimensiones Obstaculo::getDim()
{
	return dim;
}
