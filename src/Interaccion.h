#pragma once
#include "Obstaculo.h"
#include "Hombre.h"
class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	bool colision(Obstaculo o, Hombre h);
};

