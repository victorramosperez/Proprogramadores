#pragma once
#include "Plataforma.h"
#include "Hombre.h"
#define MAX_PLATAFORMAS 100 
#include "Interaccion.h"
class ListaPlataformas
{
public:
	ListaPlataformas();
	bool agregar(Plataforma* p);
	//void mueve(float t);
	void dibuja();
	void destruirContenido();
	Plataforma* colision(Hombre& h);
	Plataforma* operator [](int i);
	int getNumero() { return numero; }
	void rebote(Hombre h);
private:
	Plataforma* lista[MAX_PLATAFORMAS];
	int numero;

	friend class Interaccion;
};