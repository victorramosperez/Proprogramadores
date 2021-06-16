#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"

#include <fstream>
#include <iostream>
using namespace std;
Coordinador::Coordinador()
{
	estado = INICIO;

	//abrir fichero
	ifstream fin;
	fin.open("score.txt");
	if (!fin)
		cout << "Error abriendo el el archivo de puntuaciones" << endl;
	else
	{
		int num = 0;
		while (fin >> puntuaciones[num])
		{
			//fin >> puntuaciones[num];
			num++;
		}
	}
	fin.close();
}

Coordinador::~Coordinador()
{
	//GUARDAR PUNTUACIONES
	//abrir fichero
	ofstream fout;
	fout.open("score.txt");
	if (!fout)
		cout << "Error abriendo el el archivo de puntuaciones" << endl;
	else
	{
		for (int i = 0;i < MAX_PUNTUACIONES;i++)
			fout << puntuaciones[i] << endl;
	}
	fout.close();
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
		if (key == 's' || key == 'S')
			estado = SCORE;
	}
	else if (estado == SCORE)
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
				anadeScore(mundo.puntos, puntuaciones);
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
		ETSIDI::printxy("Pulsa -S- para ver puntuaciones", -1, 0);
	}
	else if (estado == SCORE)
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
	ETSIDI::setFont("fuentes/Bitwise.ttf", 22);
	ETSIDI::printxy("Mejores soldados:", -4, 12);

	string spuntos1 = to_string(puntuaciones[0]);
	string spuntos2 = to_string(puntuaciones[1]);
	string spuntos3 = to_string(puntuaciones[2]);
	string spuntos4 = to_string(puntuaciones[3]);
	string spuntos5 = to_string(puntuaciones[4]);
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 14);

	ETSIDI::printxy(spuntos1.c_str(), -2, 9);
	ETSIDI::printxy(" puntos", 0, 9);

	ETSIDI::printxy(spuntos2.c_str(), -2, 8);
	ETSIDI::printxy(" puntos", 0, 8);

	ETSIDI::printxy(spuntos3.c_str(), -2, 7);
	ETSIDI::printxy(" puntos", 0, 7);

	ETSIDI::printxy(spuntos4.c_str(), -2, 6);
	ETSIDI::printxy(" puntos", 0, 6);

	ETSIDI::printxy(spuntos5.c_str(), -2, 5);
	ETSIDI::printxy(" puntos", 0, 5);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 22);
	ETSIDI::printxy("Pulsa -C- para continuar", -6, 2);
	}
}

void Coordinador::ordenaPuntuaciones(int p[MAX_PUNTUACIONES])
{
	//METODO DE LA BURBUJA
	for (int i = 0; i < MAX_PUNTUACIONES - 1; i++)
	{
		for (int j = i + 1; j < MAX_PUNTUACIONES; j++)
		{
			if (p[i] < p[j])
			{
				int aux = p[i];
				p[i] =p[j];
				p[j] = aux;
			}
		}
	}
}

void Coordinador::anadeScore(int score, int lista[MAX_PUNTUACIONES])
{
	lista[MAX_PUNTUACIONES-1] = score;
	ordenaPuntuaciones(lista);
}
