#pragma once
#include "Vector2D.h"
#include "Dimensiones.h"
#include "freeglut.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
class Obstaculo
{
protected:
	Vector2D posicion;
	Dimensiones dim;
	int dano;

public:
	Obstaculo();
	Obstaculo(float xmin, float ymin, float xmax, float ymax);
	void dibuja();
	void setPos(float posx, float posy);
	Dimensiones getDim();
	Vector2D getPos();
	SpriteSequence sprite{ "imagenes/lava4.png", 1 };
friend class Interaccion;
};

