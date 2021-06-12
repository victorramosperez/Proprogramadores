#include "Obstaculo.h"
#include "ETSIDI.h"

Obstaculo::Obstaculo()
{
	dim.limbot1 = { 0,0 };
	dim.limbot2 = { 0,0 };
	dim.limtop1 = { 0,0 };
	dim.limtop2 = { 0,0 };
	dano=0;
	sprite.setCenter(1, 0);
	sprite.setSize(dim.limbot2.x-dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
}

Obstaculo::Obstaculo(float xmin, float ymin, float xmax, float ymax)
{
	dim.limbot1 = { xmin,ymin };
	dim.limbot2 = { xmax,ymin };
	dim.limtop1 = { xmin,ymax };
	dim.limtop2 = { xmax,ymax };
	dano = 0;
	sprite.setCenter(0, 0);
	sprite.setSize(dim.limbot2.x - dim.limbot1.x, dim.limtop2.y - dim.limbot1.y);
}


void Obstaculo::dibuja() {
	/*glDisable(GL_LIGHTING);
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

	/*
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/lava1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex3d(dim.limbot1.x, dim.limtop1.y, 10.0f);
	glTexCoord2d(1, 0); glVertex3d(dim.limtop2.x, dim.limtop2.y, 10.0f);
	glTexCoord2d(1, 1); glVertex3d(dim.limbot2.x, dim.limbot1.y, 10.0f);
	glTexCoord2d(0, 1); glVertex3d(dim.limbot1.x, dim.limbot1.y, 10.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);*/
}


Dimensiones Obstaculo::getDim()
{
	return dim;
}
