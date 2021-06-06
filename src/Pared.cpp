#include "Pared.h"
#include "freeglut.h"
#include "ETSIDI.h"

Pared::Pared()
{
	color.r = color.b = 0;
	color.g = 255;
	//limite1.x = 0;
	//limite1.y = 0;
	//limite2.x = 0;
	//limite2.y = 0;
}

Pared::Pared(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
	color.r = color.g = 255;
	color.b = 0; //color distinto
}
Pared::~Pared()
{
}

void Pared::setColor(Byte r, Byte g, Byte b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}
void Pared::setPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
void Pared::dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);

	
	/*glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex3f(limite1.x,limite2.y, 0.0f);
	glVertex3f(limite1.x, limite1.y, 0.0f);
	glVertex3f(limite2.x, limite2.y, 0.0f);
	glVertex3f(limite2.x, limite1.y, 0.0f);
	glEnd();
	*/
	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(limite1.x, limite1.y);
	glTexCoord2d(1, 1); glVertex2f(limite2.x, limite1.y);
	glTexCoord2d(1, 0); glVertex2f(limite2.x, limite2.y);
	glTexCoord2d(0, 0); glVertex2f(limite1.x, limite2.y);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);*/
}
//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendrá
//el vector unitario saliente que indica la direccion de la
//recta más corta entre el punto y la pared. 
float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}