#pragma once
#include "Vector2D.h"
#include "Dimensiones.h"
#include "freeglut.h"

class Obstaculo
{
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Dimensiones dim;
	int dano;

public:

	Obstaculo();
	void dibuja();
	void mueve(float t);
	void setVel(float vx, float vy);
	void setPos(float posx, float posy);
	Dimensiones getDim();
	Vector2D getPos();

friend class Interaccion;
};

