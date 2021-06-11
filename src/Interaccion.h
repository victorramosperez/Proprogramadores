#pragma once
#include "Obstaculo.h"
#include "Hombre.h"
#include "Caja.h"
#include "Plataforma.h"
#include "Enemigo.h"
#include "Disparo.h"
class Interaccion
{
public:
	Interaccion();
	~Interaccion();

	static bool colision(Obstaculo o, Hombre h);
	static bool colision(Bonus b, Hombre h);
	static bool colision(Enemigo e, Hombre h);
	static bool rebote(Hombre& h, Caja c);
	static bool rebote(Hombre& h, Plataforma& p);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
	static bool colision(Disparo d, Plataforma p);
	static bool colision(Disparo d, Enemigo p);
	static bool colision(Hombre& h, Enemigo e);
};

