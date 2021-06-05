#pragma once
#include "Obstaculo.h"
#include "Interaccion.h"

#define MAX_OBSTACULOS 100 

class ListaObstaculos
{
public:
	ListaObstaculos();
	bool agregar(Obstaculo *o);
	void mueve(float t);
	void dibuja();
	void destruirContenido();
	Obstaculo* colision(Hombre& h);
	Obstaculo* operator [](int i);
	int getNumero() { return numero; }

private:
	Obstaculo * lista[MAX_OBSTACULOS];
	int numero;

friend class Interaccion;
};

