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
