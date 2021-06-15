#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
#include <string>
using namespace std;

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
	if (nivel == 4 && enemigos[0]->getVida()>0)
	{
		string svidajefe = to_string(enemigos[0]->getVida());
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Vida de Jefe Marciano: ", hombre.getPos().x - 8, 17);
		ETSIDI::printxy(svidajefe.c_str(), hombre.getPos().x +1, 17);
	}
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
	hombre.setVel(0,0);
	ETSIDI::play("sonidos/subenivel.mp3");
	disparos.destruirContenido(); 
	enemigos.destruirContenido();
	plataformas.destruirContenido();
	obstaculos.destruirContenido();
	bonus.destruirContenido();
	hombre.setLlave(false);
	
	if (nivel == 1)
	{
		
		// MAPA 1:
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
		Plataforma* aux10 = new Plataforma(52, 4, 55, 5);
		plataformas.agregar(aux10);
		Plataforma* aux11 = new Plataforma(57, 8, 59, 9);
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
		Plataforma* aux26 = new Plataforma(50, 7, 55, 8);
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
		Enemigo* aux75 = new Enemigo(67.5f, 0.0f, 65.0f, 71.0f);
		enemigos.agregar(aux75);
		//OBSTACULOS
		Obstaculo* aux110 = new Obstaculo(5.0f, 0.0f, 9.0f, 1.0f);
		obstaculos.agregar(aux110);
		Obstaculo* aux111 = new Obstaculo(32.0f, 0.0f, 35.0f, 1.0f);
		obstaculos.agregar(aux111);
		Obstaculo* aux112 = new Obstaculo(47.0f, 0.0f, 50.0f, 1.0f);
		obstaculos.agregar(aux112);
		Obstaculo* aux113 = new Obstaculo(50.0f, 8.0f, 52.0f, 8.8f);
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
		//MAPA 3:
		Plataforma* aux31 = new Plataforma(1, 3, 6, 4);
		plataformas.agregar(aux31);
		Plataforma* aux32 = new Plataforma(8, 0, 9, 1);
		plataformas.agregar(aux32);
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
		Plataforma* aux39 = new Plataforma(35, 0, 36, 4);
		plataformas.agregar(aux39);
		Plataforma* aux40 = new Plataforma(40, 3, 44, 4);
		plataformas.agregar(aux40);
		Plataforma* aux41 = new Plataforma(44, 3, 46, 12);
		plataformas.agregar(aux41);
		Plataforma* aux42 = new Plataforma(50, 0, 52, 4);
		plataformas.agregar(aux42);
		Plataforma* aux43 = new Plataforma(55, 3, 56, 8);
		plataformas.agregar(aux43);
		Plataforma* aux44 = new Plataforma(55, 7, 60, 8);
		plataformas.agregar(aux44);
		Plataforma* aux45 = new Plataforma(60, 7, 61, 12);
		plataformas.agregar(aux45);
		Plataforma* aux46 = new Plataforma(56, 3, 61, 4);
		plataformas.agregar(aux46);
		Plataforma* aux47 = new Plataforma(65, 0, 66, 3);
		plataformas.agregar(aux47);
		Plataforma* aux48 = new Plataforma(69, 0, 74, 4);
		plataformas.agregar(aux48);
		Plataforma* aux50 = new Plataforma(0, 12, 80, 13);
		plataformas.agregar(aux50);
		//ENEMIGOS
		Enemigo* aux80 = new Enemigo(26.0f, 4.0f, 23.0f, 29.0f);
		enemigos.agregar(aux80);
		Enemigo* aux81 = new Enemigo(25.0f, 0.0f, 19.0f, 31.0f);
		enemigos.agregar(aux81);
		Enemigo* aux82 = new Enemigo(42.0f, 4.0f, 40.0f, 44.0f);
		enemigos.agregar(aux82);
		Enemigo* aux83 = new Enemigo(57.5f, 8.0f, 55.0f, 60.0f);
		enemigos.agregar(aux83);
		Enemigo* aux84 = new Enemigo(58.5f, 4.0f, 56.0f, 61.0f);
		enemigos.agregar(aux84);
		Enemigo* aux85 = new Enemigo(58.5f, 0.0f, 52.0f, 65.0f);
		enemigos.agregar(aux85);
		//OBSTACULOS
		Obstaculo* aux120 = new Obstaculo(10.0f, 0.0f, 14.0f, 1.0f);
		obstaculos.agregar(aux120);
		Obstaculo* aux121 = new Obstaculo(15.0f, 0.0f, 18.0f, 1.0f);
		obstaculos.agregar(aux121);
		Obstaculo* aux122 = new Obstaculo(32.0f, 0.0f, 35.0f, 1.0f);
		obstaculos.agregar(aux122);
		Obstaculo* aux123 = new Obstaculo(71.0f, 4.0f, 74.0f, 5.0f);
		obstaculos.agregar(aux123);
		Obstaculo* aux124 = new Obstaculo(66.0f, 0.0f, 69.0f, 1.0f);
		obstaculos.agregar(aux124);
		//LLAVE
		BonusLlave* aux422 = new BonusLlave(59.0f, 10.0f);
		bonus.agregar(aux422);
		//PUERTA
		PlataformaPuerta* aux152 = new PlataformaPuerta(77.0f, 0.0f, 79.0f, 3.0f);
		plataformas.agregar(aux152);
	}
	if (nivel == 4)
	{
		ETSIDI::stopMusica();
		ETSIDI::playMusica("sonidos/musicaboss.mp3", true);
		//PLATAFORMAS
		Plataforma* aux51 = new Plataforma(-8, 3, -5, 4);
		plataformas.agregar(aux51);
		Plataforma* aux52 = new Plataforma(0, 3, 10, 4);
		plataformas.agregar(aux52);
		Plataforma* aux53 = new Plataforma(15, 3, 25, 4);
		plataformas.agregar(aux53);
		Plataforma* aux54 = new Plataforma(30, 3, 40, 4);
		plataformas.agregar(aux54);
		Plataforma* aux55 = new Plataforma(45, 3, 55, 4);
		plataformas.agregar(aux55);
		Plataforma* aux56 = new Plataforma(60, 3, 70, 4);
		plataformas.agregar(aux56);
		Plataforma* aux57 = new Plataforma(75, 3, 78, 4);
		plataformas.agregar(aux57);
		//JEFE FINAL
		EnemigoBoss* aux666 = new EnemigoBoss(50.0f, 0.0f, -100.0f, 100.0f);
		aux666->setBoss(true);
		enemigos.agregar(aux666);
		//ENEMIGOS AUXILIARES
		Enemigo* aux91 = new Enemigo(5.0f, 4.0f, 0.0f, 10.0f);
		enemigos.agregar(aux91);
		Enemigo* aux92 = new Enemigo(20.0f, 4.0f, 15.0f, 25.0f);
		enemigos.agregar(aux92);
		Enemigo* aux93 = new Enemigo(35.0f, 4.0f, 30.0f, 40.0f);
		enemigos.agregar(aux93);
		Enemigo* aux94 = new Enemigo(50.0f, 4.0f, 45.0f, 55.0f);
		enemigos.agregar(aux94);
		Enemigo* aux95 = new Enemigo(65.0f, 4.0f, 60.0f, 70.0f);
		enemigos.agregar(aux95);
		//PUERTA
		PlataformaPuerta* aux153 = new PlataformaPuerta(77.0f, 0.0f, 79.0f, 3.0f);
		plataformas.agregar(aux153);
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
	
	for (int i = enemigos.getNumero();i >= 0;i--)
	{
		for (int j = disparos.getNumero();j > 0;j--)
		{
			if (Interaccion::colision(*disparos[j], *enemigos[i]))
			{
				disparos.eliminar(disparos[j]);
				enemigos[i]->restaVida();
				if (enemigos[i]->getBoss() && enemigos[i]->getVida()==0)
				{
					BonusLlave* aux639 = new BonusLlave(enemigos[i]->getPos().x, enemigos[i]->getPos().y+1.0f);
					bonus.agregar(aux639);
					puntos += 2000;
					ETSIDI::play("sonidos/muerteenemigo.mp3");
					enemigos.eliminar(enemigos[i]);
				}
				else if (!(enemigos[i]->getBoss()))
				{
					int valor = ETSIDI::lanzaDado(8);
					switch (valor)
					{
					case 1:
					{
						BonusVida* aux640 = new BonusVida(enemigos[i]->getPos().x, enemigos[i]->getPos().y + 0.8f);
						aux640->identificador = true;
						bonus.agregar(aux640);
						break;
					}
					case 2:
						BonusDisparo * aux641 = new BonusDisparo(enemigos[i]->getPos().x, enemigos[i]->getPos().y + 0.8f);
						bonus.agregar(aux641);
						break;
					}
					ETSIDI::play("sonidos/muerteenemigobasico.ogg");
					enemigos.eliminar(enemigos[i]);
					puntos += 100;
				}
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
	puntos = 0;
	ETSIDI::playMusica("sonidos/musicafondo.wav", true);
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
			ETSIDI::play("sonidos/laser.mp3");
		}
		else
		{
			Disparo* d = new Disparo();
			Vector2D pos = hombre.getPos();
			d->setPos(pos.x-1.5f, pos.y + 1.0f);
			d->setVel(-20.0f, 0.0f);
			disparos.agregar(d);
			ETSIDI::play("sonidos/laser.mp3");
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
			ETSIDI::play("sonidos/salto.mp3");
		}
		break;
	}
}
