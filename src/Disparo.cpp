#include "Disparo.h"
#include "freeglut.h"
Disparo::Disparo()
{
	radio = 0.25f;
	velocidad.x = 20.0f;
	sprite.setCenter(1, 0);
	sprite.setSize(0.5, 0.5);
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

	/*
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 10);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
	glBegin(GL_LINES);
	glVertex3f(origen.x, origen.y, 10);
	glVertex3f(posicion.x, posicion.y, 10);
	glEnd();
	*/

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
