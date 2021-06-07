#pragma once
#include "Obstaculo.h"
#include "Hombre.h"
#include "Caja.h"
class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	static bool colision(Obstaculo o, Hombre h);
	static bool colision(Bonus b, Hombre h);
	static void rebote(Hombre& h, Caja c);
};

