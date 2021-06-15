#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <string>
using namespace std;
Coordinador::Coordinador()
{
	estado = INICIO;
}

Coordinador::~Coordinador()
{
}

void Coordinador::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		mundo.teclaEspecial(key);
}

void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e' || key=='E')
		{
			mundo.nivel = 0;
			mundo.inicializa();
			mundo.cargarNivel();
			estado = JUEGO;
		}

		if (key == 's' || key == 'S')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.tecla(key);
		if (key == 'p' || key == 'P')
			estado = PAUSA;
		
	}
	else if (estado == PAUSA)
	{
		if (key == 'c' || key == 'C')
			estado = JUEGO;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c' || key == 'C')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c' || key == 'C')
			estado = INICIO;
	}
}

void Coordinador::mueve()
{
	if (estado == JUEGO)
	{
		mundo.mueve();
		if (mundo.hombre.getPos().x >= 76.5f && mundo.hombre.getLlave())
		{
			if (!mundo.cargarNivel())
			{
				ETSIDI::stopMusica();
				ETSIDI::play("sonidos/ganaste.mp3");
				estado = FIN;
			}
		}
		if (!mundo.hombre.getVida())
		{
			ETSIDI::stopMusica();
			ETSIDI::play("sonidos/perdiste.mp3");
			estado = GAMEOVER;
		}
	}

}

void Coordinador::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		//dibujo del fondo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/portada4.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(-10, 0, 5);
		glTexCoord2d(1, 1); glVertex3d(10, 0, 5);
		glTexCoord2d(1, 0); glVertex3d(10, 15, 5);
		glTexCoord2d(0, 0); glVertex3d(-10, 15, 5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -7, 3);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -7, 2);
		ETSIDI::printxy("Proprogramadores", 2, 0);
	}
	else if (estado == JUEGO)
	{
		mundo.dibuja();
	}
	else if (estado == PAUSA)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		//dibujo del fondo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pausa2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(-10, 0, 5);
		glTexCoord2d(1, 1); glVertex3d(10, 0, 5);
		glTexCoord2d(1, 0); glVertex3d(10, 15, 5);
		glTexCoord2d(0, 0); glVertex3d(-10, 15, 5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);


		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -8, 7);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("En el juego, utiliza las flechas de direccion", -6, 5);
		ETSIDI::printxy("para desplazarte y saltar.", -4, 4);
		ETSIDI::printxy("Utiliza la barra espaciadora para disparar.", -6, 3);
		ETSIDI::printxy("Elimina a los enemigos para conseguir bonus.", -6, 2);
	}
	else if (estado == GAMEOVER)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		//dibujo del fondo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/gameover.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(-10, 0, 5);
		glTexCoord2d(1, 1); glVertex3d(10, 0, 5);
		glTexCoord2d(1, 0); glVertex3d(10, 15, 5);
		glTexCoord2d(0, 0); glVertex3d(-10, 15, 5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Has fracasado.", -2, 10);

		string spuntos = to_string(mundo.puntos);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Tu puntuacion ha sido: ",-2 , 7);
		ETSIDI::printxy(spuntos.c_str(),7 , 7);
		ETSIDI::printxy(" puntos", 9, 7);
		ETSIDI::printxy("Pulsa -C- para continuar", -2, 4);
	}
	else if (estado == FIN)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//dibujo del fondo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fin.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(-10, 0, 5);
		glTexCoord2d(1, 1); glVertex3d(10, 0, 5);
		glTexCoord2d(1, 0); glVertex3d(10, 15, 5);
		glTexCoord2d(0, 0); glVertex3d(-10, 15, 5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -1, 10);
		string spuntos = to_string(mundo.puntos);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Tu puntuacion ha sido: ", -2, 7);
		ETSIDI::printxy(spuntos.c_str(), 7, 7);
		ETSIDI::printxy(" puntos", 9, 7);
		ETSIDI::printxy("Pulsa -C- para continuar", 0, 1);
	}
}