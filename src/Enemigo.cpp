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
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCube(5);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
