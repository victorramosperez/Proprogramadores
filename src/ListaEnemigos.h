#pragma once
#define MAX_ENEMIGOS 100
#include "Interaccion.h"
#include "Enemigo.h"
class ListaEnemigos
{
public:
	ListaEnemigos();
	virtual ~ListaEnemigos();
	bool agregar(Enemigo* e);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
	void colision(Hombre &h);
	int getNumero() { return numero; }
	Enemigo* operator[](int);
	void eliminar(int);
	void eliminar(Enemigo *e);
private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;
};