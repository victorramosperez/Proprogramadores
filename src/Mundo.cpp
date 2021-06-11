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
	
 //MAPA 1:
	Plataforma* aux = new Plataforma(1, 4, 2, 5);
	plataformas.agregar(aux);
	Plataforma* aux2 = new Plataforma(4, 4, 9, 5);
	plataformas.agregar(aux2);
	Plataforma* aux3 = new Plataforma(6, 8, 7, 9);
	plataformas.agregar(aux3);
	Plataforma* aux4 = new Plataforma(12, 0, 14, 3);
	plataformas.agregar(aux4);
	Plataforma* aux5 = new Plataforma(17, 4, 20, 5);
	plataformas.agregar(aux5);
	Plataforma* aux6 = new Plataforma(20, 8, 25, 9);
	plataformas.agregar(aux6);
	Plataforma* aux7 = new Plataforma(28, 8, 32, 9);
	plataformas.agregar(aux7);
	Plataforma* aux8 = new Plataforma(31, 4, 32, 5);
	plataformas.agregar(aux8);
	Plataforma* aux9 = new Plataforma(36, 4, 38, 5);
	plataformas.agregar(aux9);
	Plataforma* aux10 = new Plataforma(41, 4, 42, 5);
	plataformas.agregar(aux10);
	Plataforma* aux11 = new Plataforma(44, 4, 45, 5);
	plataformas.agregar(aux11);
	Plataforma* aux12 = new Plataforma(47, 4, 48, 5);
	plataformas.agregar(aux12);
	Plataforma* aux13 = new Plataforma(53, 4, 54, 5);
	plataformas.agregar(aux13);
	Plataforma* aux14 = new Plataforma(56, 8, 59, 9);
	plataformas.agregar(aux14);
	Plataforma* aux15 = new Plataforma(63, 8, 67, 9);
	plataformas.agregar(aux15);
	Plataforma* aux16 = new Plataforma(64, 4, 66, 5);
	plataformas.agregar(aux16);
	Plataforma* aux17 = new Plataforma(69, 0, 73, 1);
	plataformas.agregar(aux17);
	Plataforma* aux18 = new Plataforma(70, 1, 73, 2);
	plataformas.agregar(aux18);
	Plataforma* aux19 = new Plataforma(71, 2, 73, 3);
	plataformas.agregar(aux19);
	Plataforma* aux20 = new Plataforma(72, 3, 73, 4);
	plataformas.agregar(aux20);


/*	//MAPA 2:
	Plataforma* aux21 = new Plataforma(1, 4, 4, 5);
	plataformas.agregar(aux21);
	Plataforma* aux22 = new Plataforma(9, 0, 11, 5);
	plataformas.agregar(aux22);
	Plataforma* aux23 = new Plataforma(13, 8, 16, 9);
	plataformas.agregar(aux23);
	Plataforma* aux24 = new Plataforma(14, 4, 15, 5);
	plataformas.agregar(aux24);
	Plataforma* aux25 = new Plataforma(18, 0, 20, 5);
	plataformas.agregar(aux25);
	Plataforma* aux26 = new Plataforma(22, 5, 24, 8);
	plataformas.agregar(aux26);
	Plataforma* aux27 = new Plataforma(25, 0, 29, 3);
	plataformas.agregar(aux27);
	Plataforma* aux28 = new Plataforma(35, 0, 37, 5);
	plataformas.agregar(aux28);
	Plataforma* aux29 = new Plataforma(40, 4, 42, 5);
	plataformas.agregar(aux29);
	Plataforma* aux30 = new Plataforma(45, 0, 47, 6);
	plataformas.agregar(aux30);
	Plataforma* aux31 = new Plataforma(50, 0, 52, 2);
	plataformas.agregar(aux31);
	Plataforma* aux32 = new Plataforma(50, 8, 55, 9);
	plataformas.agregar(aux32);
	Plataforma* aux33 = new Plataforma(57, 0, 59, 2);
	plataformas.agregar(aux33);
	Plataforma* aux34 = new Plataforma(60, 8, 65, 9);
	plataformas.agregar(aux34);
	Plataforma* aux35 = new Plataforma(63, 0, 65, 3);
	plataformas.agregar(aux35);
	Plataforma* aux36 = new Plataforma(65, 3, 66, 4);
	plataformas.agregar(aux36);
	Plataforma* aux37 = new Plataforma(68, 0, 70, 2);
	plataformas.agregar(aux37);
	Plataforma* aux38 = new Plataforma(71, 0, 73, 6);
	plataformas.agregar(aux38);
	*/
	/*
	//Plataformas nivel 3
	Plataforma* aux39 = new Plataforma(1, 4, 6, 5);
	plataformas.agregar(aux39);
	Plataforma* aux40 = new Plataforma(8, 0, 9, 1);
	plataformas.agregar(aux40);
	Plataforma* aux41 = new Plataforma(10, 0, 11, 2);
	plataformas.agregar(aux41);
	Plataforma* aux42 = new Plataforma(12, 0, 13, 3);
	plataformas.agregar(aux42);
	Plataforma* aux43 = new Plataforma(14, 0, 15, 4);
	plataformas.agregar(aux43);
	Plataforma* aux44 = new Plataforma(18, 0, 19, 3);
	plataformas.agregar(aux44);
	Plataforma* aux45 = new Plataforma(22, 3, 23, 6);
	plataformas.agregar(aux45);
	Plataforma* aux46 = new Plataforma(23, 3, 25, 4);
	plataformas.agregar(aux46);
	Plataforma* aux47 = new Plataforma(24, 4, 25, 6);
	plataformas.agregar(aux47);
	Plataforma* aux48 = new Plataforma(25, 5, 28, 6);
	plataformas.agregar(aux48);
	Plataforma* aux49 = new Plataforma(27, 3, 28, 5);
	plataformas.agregar(aux49);
	Plataforma* aux50 = new Plataforma(28, 3, 30, 4);
	plataformas.agregar(aux50);
	Plataforma* aux51 = new Plataforma(29, 4, 30, 6);
	plataformas.agregar(aux51);
	Plataforma* aux52 = new Plataforma(35, 3, 39, 4);
	plataformas.agregar(aux52);
	Plataforma* aux53 = new Plataforma(35, 4, 37, 12);
	plataformas.agregar(aux53);
	Plataforma* aux54 = new Plataforma(37, 2, 39, 3);
	plataformas.agregar(aux54);
	Plataforma* aux55 = new Plataforma(41, 3, 46, 4);
	plataformas.agregar(aux55);
	Plataforma* aux56 = new Plataforma(44, 4, 46, 12);
	plataformas.agregar(aux56);
	Plataforma* aux57 = new Plataforma(49, 3, 52, 4);
	plataformas.agregar(aux57);
	Plataforma* aux58 = new Plataforma(49, 4, 50, 12);
	plataformas.agregar(aux58);
	Plataforma* aux59 = new Plataforma(51, 4, 52, 5);
	plataformas.agregar(aux59);
	Plataforma* aux60 = new Plataforma(54, 3, 56, 8);
	plataformas.agregar(aux60);
	Plataforma* aux61 = new Plataforma(58, 8, 61, 12);
	plataformas.agregar(aux61);
	Plataforma* aux62 = new Plataforma(58, 3, 61, 4);
	plataformas.agregar(aux62);
	Plataforma* aux63 = new Plataforma(65, 0, 67, 3);
	plataformas.agregar(aux63);
	Plataforma* aux64 = new Plataforma(69, 0, 71, 4);
	plataformas.agregar(aux64);
	Plataforma* aux65 = new Plataforma(74, 0, 79, 1);
	plataformas.agregar(aux65);
	Plataforma* aux66 = new Plataforma(75, 1, 79, 2);
	plataformas.agregar(aux66);
	Plataforma* aux67 = new Plataforma(76, 2, 79, 3);
	plataformas.agregar(aux67);
	Plataforma* aux68 = new Plataforma(77, 3, 79, 4);
	plataformas.agregar(aux68);
	Plataforma* aux69 = new Plataforma(78, 4, 79, 5);
	plataformas.agregar(aux69);

	Plataforma* aux70 = new Plataforma(0, 12, 80, 13);
	plataformas.agregar(aux70);
	*/
	/*
	Plataforma* aux = new Plataforma(0, 3, 80, 4);
	plataformas.agregar(aux);
	Plataforma* aux2 = new Plataforma(-5, 0, -4, 4);
	plataformas.agregar(aux2);
	*/

	paredes.dibuja();
	plataformas.dibuja();
	disparos.dibuja();
	enemigos.dibuja();
	caja.dibuja();
	hombre.dibuja();
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
	disparos.mueve(0.025f);
	enemigos.mueve(0.025f);
	Interaccion::rebote(hombre, caja);
	plataformas.rebote(hombre);
	disparos.colision(caja);
	for (int i = 0; i < plataformas.getNumero();i++)
		disparos.colision(*plataformas[i]);
	
	for (int i = disparos.getNumero();i > 0;i--)
	{
		for (int j = disparos.getNumero();j > 0;j--)
		{
			if (Interaccion::colision(*disparos[j], *enemigos[i]))
			{
				enemigos.eliminar(enemigos[i]);
				disparos.eliminar(disparos[j]);
				//puntos += 100;
			}
		}
	}
	/*for (int i = 0;i < enemigos.getNumero();i++)
	{
		if (Interaccion::colision(hombre, *enemigos[i]))
		{
			hombre.setVel(hombre.getVel().x, 3);
			if (hombre.getVel().x >= 0.0f)
			{
				hombre.setPos(enemigos[i]->getDim().limtop1.x-0.5f, enemigos[i]->getDim().limtop1.y);
				hombre.setVel(-3.0f, hombre.getVel().y);
			}
			else
			{
				hombre.setPos(enemigos[i]->getDim().limtop2.x+0.5f, enemigos[i]->getDim().limtop2.y);
				hombre.setVel(3.0f, hombre.getVel().y);
			}
		}
			

	}*/
	enemigos.colision(hombre);
}

void Mundo::inicializa()
{
	//setNivel(0);
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 35;
	//cargarNivel();
	hombre.setPos(-7.0f, 0.0f);
	hombre.setVel(0.0f, 0.0f);
	Enemigo* aux64 = new Enemigo();
	enemigos.agregar(aux64);
}

Mundo::~Mundo()
{
}

void Mundo::tecla(unsigned char key)
{
	if (key == ' ') 
	{
		if (hombre.getVel().x >= 0.00)
		{
			Disparo* d = new Disparo();
			Vector2D pos = hombre.getPos();
			d->setPos(pos.x, pos.y + 1.2f);
			disparos.agregar(d);
			ETSIDI::play("sonidos/disparo.wav");
		}
		else
		{
			Disparo* d = new Disparo();
			Vector2D pos = hombre.getPos();
			d->setPos(pos.x, pos.y + 1.2f);
			d->setVel(-20.0f, 0.0f);
			disparos.agregar(d);
			ETSIDI::play("sonidos/disparo.wav");
		}
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel(-5.0f, hombre.getVel().y);
		//hombre.setPos(hombre.getPos().x - 0.2f, hombre.getPos().y);

		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(5.0f, hombre.getVel().y);
		//hombre.setPos(hombre.getPos().x + 0.2f, hombre.getPos().y);
		break;
	case GLUT_KEY_UP: //&& Interaccion::rebote(hombre, caja)
		hombre.setVel(hombre.getVel().x, 14);
		break;
	}
}
