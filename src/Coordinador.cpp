#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"

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
		if (key == 'e')
		{
			mundo.inicializa();
			mundo.cargarNivel();
			estado = JUEGO;
		}

		if (key == '2')
		{
			mundo.inicializa();
			mundo.nivel = 1;
			mundo.cargarNivel();
			estado = JUEGO;
		}

		if (key == '3')
		{
			mundo.inicializa();
			mundo.nivel = 2;
			mundo.cargarNivel();
			estado = JUEGO;
		}

		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.tecla(key);
		if (key == 'p')
			estado = PAUSA;
		
	}
	else if (estado == PAUSA)
	{
		if (key == 'c')
			estado = JUEGO;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
}

void Coordinador::mueve()
{
	if (estado == JUEGO)
	{
		mundo.mueve();
		/*mundo.mueve();
		if (mundo.getNumEsferas() == 0)
		{
			if (!mundo.cargarNivel())
				estado = FIN;
		}
		if (mundo.getImpacto())
		{
			estado = GAMEOVER;
		}*/
	}

}

void Coordinador::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Erjueguito 1.1", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", 0, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", 0, 6);
		ETSIDI::printxy("Proprogramadores", 2, 1);
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
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -6, 7);
	}
	else if (estado == GAMEOVER)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, �Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}