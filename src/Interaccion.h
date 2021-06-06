#pragma once
#include "Obstaculo.h"
#include "Hombre.h"
class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	static bool colision(Obstaculo o, Hombre h);
	static bool colision(Bonus b, Hombre h);
};

