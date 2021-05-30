#include "Enemigo.h"
Enemigo::Enemigo()
{
    Direccion = 0;
    Vivo = true;
    Vida = 1;
}

Enemigo::~Enemigo()
{

}

void Enemigo::dibuja()
{
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
		glVertex3f();
		glVertex3f();
		glVertex3f();
		glVertex3f();
	glEnd();
}
