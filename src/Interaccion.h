#pragma once
#include "Obstaculo.h"
#include "Hombre.h"
#include "Caja.h"
#include "Plataforma.h"
class Interaccion
{
public:
	Interaccion();
	~Interaccion();

	static bool colision(Obstaculo o, Hombre h);
	static bool colision(Bonus b, Hombre h);
	static bool rebote(Hombre& h, Caja c);
	static bool rebote(Hombre& h, Plataforma& p);
};

