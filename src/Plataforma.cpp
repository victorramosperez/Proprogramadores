#include "Plataforma.h"
#include "freeglut.h"
#include "ETSIDI.h"

Plataforma::Plataforma()
{
	color.r = color.b = 0;
	color.g = 255;
}

Plataforma::Plataforma(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
	dim.limbot1.x = x1;
	dim.limbot1.y = y1;
	dim.limbot2.x = x2;
	dim.limbot2.x = y1;
	dim.limtop1.x = x1;
	dim.limtop1.y = y2;
	dim.limtop2.x = x2;
	dim.limtop2.y = y2;
	color.r = color.g = 255;
	color.b = 0; //color distinto
}
Plataforma::~Plataforma()
{
}

void Plataforma::setColor(Byte r, Byte g, Byte b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}
void Plataforma::setPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
void Plataforma::dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tile5.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(limite1.x, limite1.y, 10);
	glTexCoord2d(1, 1); glVertex3d(limite1.x, limite2.y, 10);
	glTexCoord2d(1, 0); glVertex3d(limite2.x, limite2.y, 10);
	glTexCoord2d(0, 0); glVertex3d(limite2.x, limite1.y, 10);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

Dimensiones Plataforma::getDim()
{
	return dim;
}