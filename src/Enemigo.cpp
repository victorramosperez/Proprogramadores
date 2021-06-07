#include "Enemigo.h"
#include "freeglut.h"
Enemigo::Enemigo()
{
	Direccion = 0;
	Vivo = true;
	Vida = 1;
    	aceleracion.x = aceleracion.y = 0;
    	Altura = 1.8f;
   	sprite.setCenter(1, 0);
    	sprite.setSize(2, 2);
   
}

Enemigo::~Enemigo()
{

}

void Enemigo::dibuja()
{
	glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 10);
    glColor3f(1.0f, 0.0f, 0.0f);
    //glutSolidSphere(Altura, 20, 20);
    //gestion de direccion y animacion
    if (velocidad.x > 0.01)sprite.flip(false, false);
    if (velocidad.x < -0.01)sprite.flip(true, false);
    if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
        sprite.setState(0);
    else if (sprite.getState() == 0)
        sprite.setState(1, false);
    sprite.draw();
    glPopMatrix();
	
}
