#pragma once
#DEFINE MAX_ENEMIGOS 10
#include "Enemigo.h"

class ListaEnemigos
{
public:
	ListaEnemigos();
	virtual ~ListaEnemigos();
	bool agregar(Enemigo* e);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Esfera* e);
	
	int getNumero() { return numero; }
private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;
};
