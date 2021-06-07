#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Esto es una prueba", -11, 19);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Dibujo en el mundo::dibuja()", 3.5, 19);
	
	Pared* aux = new Pared(-5.0f, 9.0f, 5.0f, 9.0f);
	paredes.agregar(aux);
	Pared* aux2 = new Pared(-5.0f, 5.0f, 5.0f, 5.0f);
	paredes.agregar(aux2);
	Pared* aux3 = new Pared(7.0f, 5.0f, 17.0f, 5.0f);
	paredes.agregar(aux3);

	paredes.dibuja();
	cajita.dibuja();
	hombre.dibuja();
	enemigo.dibuja();
}

bool Mundo::cargarNivel()
{
	nivel++;
	//Resetear la posicion, velocidad, destruir contenido
	
	if (nivel == 1)
	{
		//Crear mapa, enemigos
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Esto es una prueba del nivel 1", -11, 5);
	}
	if (nivel == 2)
	{
		//Crear mapa, enemigos
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Esto es una prueba del nivel 2", 0, 5);
	}
	if (nivel == 3)
	{
		//Crear mapa, enemigos
	}
	if (nivel <= 3)
		return true;
	return false;
}

void Mundo::setNivel(int n)
{
	nivel = n;
}

void Mundo::mueve()
{
	hombre.mueve(0.025f);
	Interaccion::rebote(hombre, cajita);
}

void Mundo::inicializa()
{
	//setNivel(0);
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 35;
	//cargarNivel();
	hombre.setPos(0, 0);
	hombre.setVel(0.0f, 0.0f);
}

Mundo::~Mundo()
{
}

void Mundo::tecla(unsigned char key)
{
	
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		x_ojo = x_ojo - 2.5f;
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		x_ojo=x_ojo+2.5f;
		hombre.setVel(5.0f, 0.0f);
		break;
	}
}
