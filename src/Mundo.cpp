#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

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
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
}

bool Mundo::cargarNivel()
{
	nivel++;
	//Resetear la posicion, velocidad, destruir contenido
	
	if (nivel == 1)
	{
		//Crear mapa, enemigos
		//aqui es donde hay que poner el codigo de dibujo
		glBegin(GL_POLYGON);
		glColor3ub(0, 255, 0);
		glVertex3f(-10.6f, 0.0f, -10.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(-10.6f, 10.6f, -10.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(10.6f, 10.6f, -10.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(10.6f, 0.f, -10.0f);
		glEnd();
	}
	if (nivel == 2)
	{
		//Crear mapa, enemigos
		suelo21.dibuja();
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
	//
nivel = n;
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	setNivel(0);
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;
}

Mundo::~Mundo()
{
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case '2':
		nivel = 2;
		cargarNivel();
		break;
	case '3':
		nivel = 3;
		cargarNivel();
		break;
	}
}

void Mundo::teclaEspecial(unsigned char key)
{

}
