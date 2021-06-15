#include "PlataformaPuerta.h"

void PlataformaPuerta::dibuja()
{
	glPushMatrix();
	glTranslatef(dim.limbot1.x, dim.limbot1.y, 7.1);
	glColor3f(1.0f, 0.0f, 0.0f);
	sprite.draw();
	glPopMatrix();
}
