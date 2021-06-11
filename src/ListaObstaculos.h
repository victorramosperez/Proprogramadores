#pragma once
#include "Obstaculo.h"
#include "Interaccion.h"

#define MAX_OBSTACULOS 100 

class ListaObstaculos
{
public:
	ListaObstaculos();
	virtual ~ListaObstaculos();
	bool agregar(Obstaculo* o);
	void destruirContenido();
	void dibuja();
	void colision(Hombre& h);
	int getNumero() { return numero; }
	Obstaculo* operator[](int);
	void eliminar(int);
	void eliminar(Obstaculo* o);

private:
	Obstaculo * lista[MAX_OBSTACULOS];
	int numero;

friend class Interaccion;
};

