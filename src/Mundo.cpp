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
			x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Esto es una prueba", -11, 19);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Dibujo en el mundo::dibuja()", 3.5, 19);
	
	/* MAPA 1:
Pared* aux = new Pared(-3.0f, 5.0f, -2.0f, 5.0f);
paredes.agregar(aux);
Pared* aux2 = new Pared(2.0f, 5.0f, 7.0f, 5.0f);
paredes.agregar(aux2);
Pared* aux3 = new Pared(4.0f, 9.0f, 5.0f, 9.0f);
paredes.agregar(aux3);
Pared* aux4 = new Pared(12.0f, 0.0f, 12.0f, 3.0f);
paredes.agregar(aux4);
Pared* aux5 = new Pared(12.0f, 3.0f, 14.0f, 3.0f);
paredes.agregar(aux5);
Pared* aux6 = new Pared(14.0f, 0.0f, 14.0f, 3.0f);
paredes.agregar(aux6);
Pared* aux7 = new Pared(15.0f, 5.0f, 18.0f, 5.0f);
paredes.agregar(aux7);
Pared* aux8 = new Pared(18.0f, 9.0f, 23.0f, 9.0f);
paredes.agregar(aux8);
Pared* aux9 = new Pared(26.0f, 9.0f, 30.0f, 9.0f);
paredes.agregar(aux9);
Pared* aux10 = new Pared(29.0f, 5.0f, 30.0f, 5.0f);
paredes.agregar(aux10);
Pared* aux11 = new Pared(35.0f, 5.0f, 37.0f, 5.0f);
paredes.agregar(aux11);
Pared* aux12 = new Pared(40.0f, 5.0f, 41.0f, 5.0f);
paredes.agregar(aux12);
Pared* aux13 = new Pared(43.0f, 5.0f, 44.0f, 5.0f);
paredes.agregar(aux13);
Pared* aux14 = new Pared(46.0f, 5.0f, 47.0f, 5.0f);
paredes.agregar(aux14);
Pared* aux15 = new Pared(51.0f, 5.0f, 52.0f, 5.0f);
paredes.agregar(aux15);
Pared* aux16 = new Pared(54.0f, 9.0f, 57.0f, 9.0f);
paredes.agregar(aux16);
Pared* aux17 = new Pared(61.0f, 9.0f, 65.0f, 9.0f);
paredes.agregar(aux17);
Pared* aux18 = new Pared(62.0f, 5.0f, 64.0f, 5.0f);
paredes.agregar(aux18);
Pared* aux19 = new Pared(67.0f, 0.0f, 67.0f, 2.0f);
paredes.agregar(aux19);
Pared* aux20 = new Pared(67.0f, 2.0f, 68.0f, 2.0f);
paredes.agregar(aux20);
Pared* aux21 = new Pared(68.0f, 2.0f, 68.0f, 4.0f);
paredes.agregar(aux21);
Pared* aux22 = new Pared(68.0f, 4.0f, 69.0f, 4.0f);
paredes.agregar(aux22);
Pared* aux23 = new Pared(69.0f, 4.0f, 69.0f, 6.0f);
paredes.agregar(aux23);
Pared* aux24 = new Pared(69.0f, 6.0f, 70.0f, 6.0f);
paredes.agregar(aux24);
Pared* aux25 = new Pared(70.0f, 6.0f, 70.0f, 8.0f);
paredes.agregar(aux25);
Pared* aux26 = new Pared(70.0f, 8.0f, 71.0f, 8.0f);
paredes.agregar(aux26);
*/

	Pared* aux27 = new Pared(-4.0f, 5.0f, -1.0f, 5.0f);
	paredes.agregar(aux27);
	Pared* aux28 = new Pared(4.0f, 0.0f, 4.0f, 5.0f);
	paredes.agregar(aux28);
	Pared* aux29 = new Pared(4.0f, 5.0f, 6.0f, 5.0f);
	paredes.agregar(aux29);
	Pared* aux30 = new Pared(6.0f, 0.0f, 6.0f, 5.0f);
	paredes.agregar(aux30);
	Pared* aux31 = new Pared(8.0f, 9.0f, 11.0f, 9.0f);
	paredes.agregar(aux31);
	Pared* aux32 = new Pared(9.0f, 5.0f, 10.0f, 5.0f);
	paredes.agregar(aux32);
	Pared* aux33 = new Pared(13.0f, 0.0f, 13.0f, 5.0f);
	paredes.agregar(aux33);
	Pared* aux34 = new Pared(13.0f, 5.0f, 15.0f, 5.0f);
	paredes.agregar(aux34);
	Pared* aux35 = new Pared(15.0f, 0.0f, 15.0f, 5.0f);
	paredes.agregar(aux35);
	Pared* aux36 = new Pared(17.0f, 5.0f, 19.0f, 5.0f);
	paredes.agregar(aux36);
	Pared* aux37 = new Pared(20.0f, 0.0f, 20.0f, 3.0f);
	paredes.agregar(aux37);
	Pared* aux38 = new Pared(20.0f, 3.0f, 24.0f, 3.0f);
	paredes.agregar(aux38);
	Pared* aux39 = new Pared(24.0f, 0.0f, 24.0f, 3.0f);
	paredes.agregar(aux39);
	Pared* aux40 = new Pared(29.0f, 0.0f, 29.0f, 5.0f);
	paredes.agregar(aux40);
	Pared* aux41 = new Pared(29.0f, 5.0f, 31.0f, 5.0f);
	paredes.agregar(aux41);
	Pared* aux42 = new Pared(31.0f, 0.0f, 31.0f, 5.0f);
	paredes.agregar(aux42);
	Pared* aux43 = new Pared(34.0f, 5.0f, 36.0f, 5.0f);
	paredes.agregar(aux43);
	Pared* aux44 = new Pared(39.0f, 0.0f, 39.0f, 6.0f);
	paredes.agregar(aux44);
	Pared* aux45 = new Pared(39.0f, 6.0f, 41.0f, 6.0f);
	paredes.agregar(aux45);
	Pared* aux46 = new Pared(41.0f, 0.0f, 41.0f, 6.0f);
	paredes.agregar(aux46);
	Pared* aux47 = new Pared(45.0f, 4.0f, 45.0f, 7.0f);
	paredes.agregar(aux47);
	Pared* aux48 = new Pared(45.0f, 7.0f, 47.0f, 7.0f);
	paredes.agregar(aux48);
	Pared* aux49 = new Pared(45.0f, 4.0f, 47.0f, 4.0f);
	paredes.agregar(aux49);
	Pared* aux50 = new Pared(47.0f, 4.0f, 47.0f, 7.0f);
	paredes.agregar(aux50);
	Pared* aux51 = new Pared(51.0f, 0.0f, 51.0f, 3.0f);
	paredes.agregar(aux51);
	Pared* aux52 = new Pared(51.0f, 3.0f, 53.0f, 3.0f);
	paredes.agregar(aux52);
	Pared* aux53 = new Pared(53.0f, 0.0f, 53.0f, 3.0f);
	paredes.agregar(aux53);
	Pared* aux54 = new Pared(51.0f, 9.0f, 56.0f, 9.0f);
	paredes.agregar(aux54);
	Pared* aux55 = new Pared(59.0f, 0.0f, 59.0f, 3.0f);
	paredes.agregar(aux55);
	Pared* aux56 = new Pared(59.0f, 3.0f, 61.0f, 3.0f);
	paredes.agregar(aux56);
	Pared* aux57 = new Pared(61.0f, 0.0f, 61.0f, 3.0f);
	paredes.agregar(aux57);
	Pared* aux58 = new Pared(62.0f, 9.0f, 67.0f, 9.0f);
	paredes.agregar(aux58);
	Pared* aux59 = new Pared(65.0f, 0.0f, 65.0f, 4.0f);
	paredes.agregar(aux59);
	Pared* aux60 = new Pared(65.0f, 4.0f, 67.0f, 4.0f);
	paredes.agregar(aux60);
	Pared* aux61 = new Pared(67.0f, 0.0f, 67.0f, 4.0f);
	paredes.agregar(aux61);
	Pared* aux62 = new Pared(70.0f, 0.0f, 70.0f, 3.0f);
	paredes.agregar(aux62);
	Pared* aux63 = new Pared(70.0f, 3.0f, 72.0f, 3.0f);
	paredes.agregar(aux63);
	Pared* aux64 = new Pared(72.0f, 0.0f, 72.0f, 3.0f);
	paredes.agregar(aux64);
	Pared* aux65 = new Pared(74.0f, 0.0f, 74.0f, 6.0f);
	paredes.agregar(aux65);
	Pared* aux66 = new Pared(74.0f, 6.0f, 76.0f, 6.0f);
	paredes.agregar(aux66);
	Pared* aux67 = new Pared(76.0f, 0.0f, 76.0f, 6.0f);
	paredes.agregar(aux67);


	paredes.dibuja();
	cajita.dibuja();
	hombre.dibuja();
	enemigo.dibuja();
	x_ojo = hombre.getPos().x;
}

bool Mundo::cargarNivel()
{
	nivel++;
	//Resetear la posicion, velocidad, destruir contenido
	
	if (nivel == 1)
	{
		//Crear mapa, enemigos
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Esto es una prueba del nivel 1", -11, 5);
	}
	if (nivel == 2)
	{
		//Crear mapa, enemigos
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Esto es una prueba del nivel 2", 0, 5);
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
	hombre.mueve(0.025f);
	Interaccion::rebote(hombre, cajita);
}

void Mundo::inicializa()
{
	//setNivel(0);
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 35;
	//cargarNivel();
	hombre.setPos(0, 0);
	hombre.setVel(0.0f, 0.0f);
}

Mundo::~Mundo()
{
}

void Mundo::tecla(unsigned char key)
{
	
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		//x_ojo = x_ojo - 2.5f;
		//x_ojo = hombre.getPos().x;
		hombre.setVel(-5.0f, 0.0f);
		

		break;
	case GLUT_KEY_RIGHT:
		//x_ojo=x_ojo+2.5f;
		hombre.setVel(5.0f, 0.0f);
		//x_ojo = hombre.getPos().x;
		//hombre.setPos(hombre.getPos().x + 2.5f, 0.0f);
		break;
	}
}
