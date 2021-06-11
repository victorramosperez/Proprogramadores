#include "Caja.h"
#include "ETSIDI.h" 
Caja::Caja()
{
	suelo.setColor(141, 73, 37);
	suelo.setPos(-10.0f, 0, 80.0f, 0);
	//techo.setColor(0, 100, 0);
	//techo.setPos(-10.0f, 15.0f, 10.0f, 15.0f);

	pared_dcha.setColor(0, 0, 0);
	pared_dcha.setPos(-10.0f, 0, -10.0f, 15.0f);
	pared_izq.setColor(0, 0, 0);
	pared_izq.setPos(80.0f, 0, 80.0f, 15.0f);
}
Caja::~Caja()
{
}
void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo30.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(-10, 0,5);
	glTexCoord2d(1, 1); glVertex3d(80, 0,5);
	glTexCoord2d(1, 0); glVertex3d(80, 15,5);
	glTexCoord2d(0, 0); glVertex3d(-10, 15,5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}