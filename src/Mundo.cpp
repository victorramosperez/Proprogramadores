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
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	/*ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Esto es una prueba", -11, 19);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Dibujo en el mundo::dibuja()", 3.5, 19);*/
	
	/*
	glBegin(GL_POLYGON);
	glColor3ub(0, 255, 0);
	glVertex3f(-10.6f, 0.0f, 0.0f);
	glColor3ub(0, 255, 0);
	glVertex3f(-10.6f, 10.6f, 0.0f);
	glColor3ub(0, 255, 0);
	glVertex3f(10.6f, 10.6f, 0.0f);
	glColor3ub(0, 255, 0);
	glVertex3f(10.6f, 0.f, 0.0f);
	glEnd();*/
	cargarNivel();
}

bool Mundo::cargarNivel()
{
	nivel++;
	//Resetear la posicion, velocidad, destruir contenido
	
	if (nivel == 1)
	{
		//Crear mapa, enemigos
		
		//aqui es donde hay que poner el codigo de dibujo
		//NO CONSIGUE ENTRAR AL NVL 1
		glBegin(GL_POLYGON);
		glColor3ub(0, 255, 0);
		glVertex3f(-10.6f, 0.0f, 0.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(-10.6f, 10.6f, 0.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(10.6f, 10.6f, 0.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(10.6f, 0.f, 0.0f);
		glEnd();
		//plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
	}
	if (nivel == 2)
	{
		//Crear mapa, enemigos
		glBegin(GL_POLYGON);
		glColor3ub(0, 255, 0);
		glVertex3f(-10.6f, 0.0f, 0.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(-10.6f, 10.6f, 0.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(10.6f, 10.6f, 0.0f);
		glColor3ub(0, 255, 0);
		glVertex3f(10.6f, 0.f, 0.0f);
		glEnd();
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

}

void Mundo::inicializa()
{
	setNivel(0);
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 35;
	plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
	cargarNivel();

}

Mundo::~Mundo()
{
}

void Mundo::tecla(unsigned char key)
{
	
}

void Mundo::teclaEspecial(unsigned char key)
{

}
