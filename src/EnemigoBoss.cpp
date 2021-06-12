#include "EnemigoBoss.h"

void EnemigoBoss::mueve(float t)
{
	posicion = posicion + velocidad * t;
}

