#pragma once
#include "Enemigo.h"

class EnemigoSimple:public Enemigo
{
private:

public:
	EnemigoSimple();
	void mueve(float t);
};
