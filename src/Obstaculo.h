#pragma once
#include "Vector2D.h"
#include "Dimensiones.h"
#include "freeglut.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
class Obstaculo
{
protected:
	Dimensiones dim;

public:
	Obstaculo(float xmin, float ymin, float xmax, float ymax);
	void dibuja();
	Dimensiones getDim();
	SpriteSequence sprite{ "imagenes/pinchos.png", 1 };
friend class Interaccion;
};

