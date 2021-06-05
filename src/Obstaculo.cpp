#include "Obstaculo.h"


Obstaculo::Obstaculo()
{
	posicion={ 0,0 };
	velocidad = { 0,0 };
	aceleracion = { 0,0 };
	dim = { 0,0,0,0 };
	dano=0;
}

void Obstaculo::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Obstaculo::dibuja() {
	glBegin(GL_POLYGON);
	glVertex3d(dim.limbot1.x, dim.limbot1.y, 10);
	glVertex3d(dim.limbot2.x, dim.limbot2.y, 10);
	glVertex3d(dim.limtop1.x, dim.limtop1.y, 10);
	glVertex3d(dim.limtop2.x, dim.limtop2.y, 10);
	glEnd();
}

void Obstaculo::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

Dimensiones Obstaculo::getDim()
{
	return dim;
}

Vector2D Obstaculo::getPos()
{
	return posicion;
}
