#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
#include <string>
using namespace std;

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
	ETSIDI::printxy("Pulse -P- para pausar", -11, 19);
	ETSIDI::setTextColor(1, 1, 1);
	
	string spuntos = to_string(puntos);
	string svida = to_string(hombre.getVida());
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Puntos: ", hombre.getPos().x + 5, 19);
	ETSIDI::printxy(spuntos.c_str(), hombre.getPos().x + 8, 19);
	if (!(hombre.getLlave()) && hombre.getPos().x > 76.0f)
		ETSIDI::printxy("Aun no has encontrado la llave", hombre.getPos().x + 5, 18);
	if (hombre.getLlave())
		ETSIDI::printxy("Tienes la llave ", hombre.getPos().x + 5, 18);
	ETSIDI::printxy("Vidas: ", hombre.getPos().x + 5, 17);
	ETSIDI::printxy(svida.c_str(), hombre.getPos().x + 7, 17);

	plataformas.dibuja();
	disparos.dibuja();
	enemigos.dibuja();
	obstaculos.dibuja();
	caja.dibuja();
	hombre.dibuja();
	bonus.dibuja();
	x_ojo = hombre.getPos().x;
}

bool Mundo::cargarNivel()
{
	nivel++;
	hombre.setPos(0, 0);
	disparos.destruirContenido();
	enemigos.destruirContenido();
	plataformas.destruirContenido();
	obstaculos.destruirContenido();
	bonus.destruirContenido();
	hombre.setLlave(false);
	
	if (nivel == 1)
	{
		Plataforma* aux = new Plataforma(1, 3, 4, 4);
		plataformas.agregar(aux);
		Plataforma* aux2 = new Plataforma(6, 7, 9, 8);
		plataformas.agregar(aux2);
		Plataforma* aux3 = new Plataforma(12, 0, 14, 3);
		plataformas.agregar(aux3);
		Plataforma* aux4 = new Plataforma(17, 4, 20, 5);
		plataformas.agregar(aux4);
		Plataforma* aux5 = new Plataforma(23, 8, 26, 9);
		plataformas.agregar(aux5);
		Plataforma* aux6 = new Plataforma(29, 8, 32, 9);
		plataformas.agregar(aux6);
		Plataforma* aux7 = new Plataforma(35, 3, 37, 4);
		plataformas.agregar(aux7);
		Plataforma* aux8 = new Plataforma(41, 0, 42, 4);
		plataformas.agregar(aux8);
		Plataforma* aux9 = new Plataforma(45, 4, 48, 5);
		plataformas.agregar(aux9);
		Plataforma* aux10 = new Plataforma(52, 4, 54, 5);
		plataformas.agregar(aux10);
		Plataforma* aux11 = new Plataforma(56, 8, 59, 9);
		plataformas.agregar(aux11);
		Plataforma* aux12 = new Plataforma(58, 0, 61, 3);
		plataformas.agregar(aux12);
		Plataforma* aux13 = new Plataforma(63, 8, 67, 9);
		plataformas.agregar(aux13);
		Plataforma* aux14 = new Plataforma(64, 4, 66, 5);
		plataformas.agregar(aux14);
		Plataforma* aux15 = new Plataforma(71, 0, 72, 5);
		plataformas.agregar(aux15);
		//ENEMIGOS
		Enemigo* aux60 = new Enemigo(20.0f, 0.0f, 15.0f, 25.0f);
		enemigos.agregar(aux60);
		Enemigo* aux61 = new Enemigo(34.5f, 0.0f, 31.0f, 39.0f);
		enemigos.agregar(aux61);
		Enemigo* aux62 = new Enemigo(47.5f, 0.0f, 43.0f, 52.0f);
		enemigos.agregar(aux62);
		Enemigo* aux63 = new Enemigo(66.0f, 0.0f, 62.0f, 70.0f);
		enemigos.agregar(aux63);
		Enemigo* aux64 = new Enemigo(65.0f, 9.0f, 63.0f, 67.0f);
		enemigos.agregar(aux64);
		//OBSTACULOS
		Obstaculo* aux100 = new Obstaculo(26.0f, 0.0f, 30.0f, 1.0f);
		obstaculos.agregar(aux100);
		Obstaculo* aux101 = new Obstaculo(5.0f, 0.0f, 10.0f, 1.0f);
		obstaculos.agregar(aux101);
		Obstaculo* aux102 = new Obstaculo(53.0f, 0.0f, 58.0f, 1.0f);
		obstaculos.agregar(aux102);
		//LLAVE
		BonusLlave* aux200 = new BonusLlave(70.0f, 14.0f);
		bonus.agregar(aux200);
		//PUERTA
		PlataformaPuerta* aux150 = new PlataformaPuerta(77.0f, 0.0f,79.0f, 3.0f);
		plataformas.agregar(aux150);
		
	}
	if (nivel == 2)
	{
		//Crear mapa, enemigos
		//MAPA 2:
		Plataforma* aux16 = new Plataforma(1, 3, 4, 4);
		plataformas.agregar(aux16);
		Plataforma* aux17 = new Plataforma(9, 0, 11, 4);
		plataformas.agregar(aux17);
		Plataforma* aux18 = new Plataforma(13, 7, 16, 8);
		plataformas.agregar(aux18);
		Plataforma* aux19 = new Plataforma(18, 0, 20, 4);
		plataformas.agregar(aux19);
		Plataforma* aux20 = new Plataforma(23, 6, 24, 8);
		plataformas.agregar(aux20);
		Plataforma* aux21 = new Plataforma(27, 0, 29, 3);
		plataformas.agregar(aux21);
		Plataforma* aux22 = new Plataforma(35, 0, 37, 4);
		plataformas.agregar(aux22);
		Plataforma* aux23 = new Plataforma(40, 5, 42, 6);
		plataformas.agregar(aux23);
		Plataforma* aux24 = new Plataforma(45, 0, 47, 6);
		plataformas.agregar(aux24);
		Plataforma* aux25 = new Plataforma(50, 0, 52, 2);
		plataformas.agregar(aux25);
		Plataforma* aux26 = new Plataforma(49, 7, 55, 8);
		plataformas.agregar(aux26);
		Plataforma* aux28 = new Plataforma(60, 7, 65, 8);
		plataformas.agregar(aux28);
		Plataforma* aux29 = new Plataforma(63, 0, 65, 3);
		plataformas.agregar(aux29);
		Plataforma* aux30 = new Plataforma(71, 0, 73, 6);
		plataformas.agregar(aux30);
		//ENEMIGOS
		Enemigo* aux70 = new Enemigo(14.5f, 0.0f, 11.0f, 18.0f);
		enemigos.agregar(aux70);
		Enemigo* aux71 = new Enemigo(23.5f, 0.0f, 20.0f, 27.0f);
		enemigos.agregar(aux71);
		Enemigo* aux72 = new Enemigo(41.0f, 0.0f, 37.0f, 45.0f);
		enemigos.agregar(aux72);
		Enemigo* aux73 = new Enemigo(57.5f, 0.0f, 52.0f, 63.0f);
		enemigos.agregar(aux73);
		Enemigo* aux74 = new Enemigo(62.5f, 8.0f, 60.0f, 65.0f);
		enemigos.agregar(aux74);
		//OBSTACULOS
		Obstaculo* aux110 = new Obstaculo(5.0f, 0.0f, 9.0f, 1.0f);
		obstaculos.agregar(aux110);
		Obstaculo* aux111 = new Obstaculo(32.0f, 0.0f, 35.0f, 1.0f);
		obstaculos.agregar(aux111);
		Obstaculo* aux112 = new Obstaculo(47.0f, 0.0f, 50.0f, 1.0f);
		obstaculos.agregar(aux112);
		Obstaculo* aux113 = new Obstaculo(49.0f, 8.0f, 51.5f, 8.8f);
		obstaculos.agregar(aux113);
		//LLAVE
		BonusLlave* aux421 = new BonusLlave(70.0f, 2.0f);
		bonus.agregar(aux421);
		//PUERTA
		PlataformaPuerta* aux151 = new PlataformaPuerta(77.0f, 0.0f, 79.0f, 3.0f);
		plataformas.agregar(aux151);
	}

	if (nivel == 3)
	{
		//Crear mapa, enemigos
		//MAPA 3:
		Plataforma* aux31 = new Plataforma(1, 4, 6, 5);
		plataformas.agregar(aux31);
		Plataforma* aux32 = new Plataforma(8, 0, 9, 1);
		plataformas.agregar(aux32);
		Plataforma* aux33 = new Plataforma(11, 0, 12, 3);
		plataformas.agregar(aux33);
		Plataforma* aux34 = new Plataforma(14, 0, 15, 5);
		plataformas.agregar(aux34);
		Plataforma* aux35 = new Plataforma(18, 0, 19, 3);
		plataformas.agregar(aux35);
		Plataforma* aux36 = new Plataforma(22, 3, 23, 6);
		plataformas.agregar(aux36);
		Plataforma* aux37 = new Plataforma(23, 3, 29, 4);
		plataformas.agregar(aux37);
		Plataforma* aux38 = new Plataforma(29, 3, 30, 6);
		plataformas.agregar(aux38);
		Plataforma* aux39 = new Plataforma(35, 4, 37, 12);
		plataformas.agregar(aux39);
		Plataforma* aux40 = new Plataforma(41, 3, 44, 4);
		plataformas.agregar(aux40);
		Plataforma* aux41 = new Plataforma(44, 3, 46, 12);
		plataformas.agregar(aux41);
		Plataforma* aux42 = new Plataforma(50, 3, 52, 4);
		plataformas.agregar(aux42);
		Plataforma* aux43 = new Plataforma(49, 3, 50, 12);
		plataformas.agregar(aux43);
		Plataforma* aux44 = new Plataforma(55, 3, 56, 8);
		plataformas.agregar(aux44);
		Plataforma* aux45 = new Plataforma(60, 8, 61, 12);
		plataformas.agregar(aux45);
		Plataforma* aux46 = new Plataforma(59, 3, 61, 4);
		plataformas.agregar(aux46);
		Plataforma* aux47 = new Plataforma(65, 0, 67, 3);
		plataformas.agregar(aux47);
		Plataforma* aux48 = new Plataforma(69, 0, 71, 4);
		plataformas.agregar(aux48);
		Plataforma* aux50 = new Plataforma(0, 12, 80, 13);
		plataformas.agregar(aux50);
		//ENEMIGOS

		//OBSTACULOS

		//LLAVE
		BonusLlave* aux422 = new BonusLlave(0.0f, 10.0f);
		bonus.agregar(aux422);
		//PUERTA
		PlataformaPuerta* aux152 = new PlataformaPuerta(77.0f, 0.0f, 79.0f, 3.0f);
		plataformas.agregar(aux152);
	}
	if (nivel == 4)
	{
		EnemigoBoss* aux666 = new EnemigoBoss(10.0f, 0.0f, -100.0f, 100.0f);
		aux666->setBoss(true);
		enemigos.agregar(aux666);
	}
	if (nivel <= 4)
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
				if (enemigos[i]->getBoss())
				{
					BonusLlave* aux639 = new BonusLlave(enemigos[i]->getPos().x, enemigos[i]->getPos().y);
					bonus.agregar(aux639);
					puntos += 1900;
				}
				else
				{
					int valor = ETSIDI::lanzaDado(10);
					switch (valor)
					{
					case 1:
					{
						BonusVida* aux640 = new BonusVida(enemigos[i]->getPos().x, enemigos[i]->getPos().y);
						aux640->identificador = true;
						bonus.agregar(aux640);
						break;
					}
					case 2:
						BonusDisparo * aux641 = new BonusDisparo(enemigos[i]->getPos().x, enemigos[i]->getPos().y);
						bonus.agregar(aux641);
						break;
					}
				}
				enemigos.eliminar(enemigos[i]);
				disparos.eliminar(disparos[j]);
				puntos += 100;
			}
		}
	}
	enemigos.colision(hombre);
	obstaculos.colision(hombre);
	bonus.colision(hombre);
}

void Mundo::inicializa()
{
	setNivel(0);
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 35;
	hombre.setPos(-7.0f, 0.0f);
	hombre.setVel(0.0f, 0.0f);
	hombre.setVida(1);
	hombre.setDispEspecial(false);
	/*Enemigo* aux64 = new Enemigo(1.0f,10.0f,-1.0f,10.0f);
	enemigos.agregar(aux64);*/
	Obstaculo* aux88 = new Obstaculo(0.0f,0.0f,5.0f,1.0f);
	obstaculos.agregar(aux88);
	puntos = 0;
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
			d->setPos(pos.x+1.5f, pos.y + 1.0f);
			disparos.agregar(d);
			ETSIDI::play("sonidos/disparo.wav");
		}
		else
		{
			Disparo* d = new Disparo();
			Vector2D pos = hombre.getPos();
			d->setPos(pos.x-1.5f, pos.y + 1.0f);
			d->setVel(-20.0f, 0.0f);
			disparos.agregar(d);
			ETSIDI::play("sonidos/disparo.wav");
		}
	}
	if (key == ' ' && hombre.getDispEspecial())
	{
		if (hombre.getVel().x >= 0.00)
		{
			Disparo* d = new Disparo();
			Disparo* d2 = new Disparo();
			Disparo* d3 = new Disparo();
			Vector2D pos = hombre.getPos();
			d->setPos(pos.x + 1.5f, pos.y + 1.0f);
			d2->setPos(pos.x + 1.5f, pos.y + 1.5f);
			d3->setPos(pos.x + 1.5f, pos.y + 0.5f);
			disparos.agregar(d);
			disparos.agregar(d2);
			disparos.agregar(d3);
			ETSIDI::play("sonidos/disparo.wav");
		}
		else
		{
			Disparo* d = new Disparo();
			Disparo* d2 = new Disparo();
			Disparo* d3 = new Disparo();
			Vector2D pos = hombre.getPos();
			d->setRadio(d->getRadio() + 1.5f);
			d->setPos(pos.x - 1.5f, pos.y + 1.0f);
			d2->setPos(pos.x - 1.5f, pos.y + 1.5f);
			d3->setPos(pos.x - 1.5f, pos.y + 0.5f);
			d->setVel(-20.0f, 0.0f);
			d2->setVel(-20.0f, 0.0f);
			d3->setVel(-20.0f, 0.0f);
			disparos.agregar(d);
			disparos.agregar(d2);
			disparos.agregar(d3);
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
		if (hombre.getVel().y>=-0.5f && hombre.getVel().y <= 0.1f)
		{
			hombre.setVel(hombre.getVel().x, 14);
		}
		break;
	}
}
