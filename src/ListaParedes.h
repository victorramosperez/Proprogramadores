#pragma once
#include "Pared.h"
#include "Hombre.h"
#define MAX_PAREDES 100 

class ListaParedes
{
public:
	ListaParedes();
	bool agregar(Pared* p);
	//void mueve(float t);
	void dibuja();
	void destruirContenido();
	Pared* colision(Hombre& h);
	Pared* operator [](int i);
	int getNumero() { return numero; }

private:
	Pared* lista[MAX_PAREDES];
	int numero;

	friend class Interaccion;
};