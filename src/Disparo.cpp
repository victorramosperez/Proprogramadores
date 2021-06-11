#include "Disparo.h"
#include "freeglut.h"
Disparo::Disparo()
{
	radio = 0.25f;
	velocidad.x = 20.0f;
}
Disparo::~Disparo()
{
}
void Disparo::dibuja()
{
	dim.limbot1.x = posicion.x - radio;
	dim.limbot1.y = posicion.y - radio;
	dim.limbot2.x = posicion.x + radio;
	dim.limbot2.y = posicion.y - radio;
	dim.limtop1.x = posicion.x - radio;
	dim.limtop1.y = posicion.y + radio;
	dim.limtop2.x = posicion.x + radio;
	dim.limtop2.y = posicion.y + radio;


	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 10);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
	glBegin(GL_LINES);
	glVertex3f(origen.x, origen.y, 10);
	glVertex3f(posicion.x, posicion.y, 10);
	glEnd();
}

float Disparo::getRadio()
{
	return radio;
}

void Disparo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
	origen.x = ix;
	origen.y = iy;
}

void Disparo::setPos(Vector2D pos)
{
	posicion.x = pos.x;
	posicion.y = pos.y;
}
