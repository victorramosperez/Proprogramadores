#pragma once
#define MAX_BONUS 100
#include "Interaccion.h"
#include "Bonus.h"
class ListaBonus
{
public:
	ListaBonus();
	virtual ~ListaBonus();
	bool agregar(Bonus* e);
	void destruirContenido();
	void dibuja();
	void colision(Hombre& h);
	int getNumero() { return numero; }
	Bonus* operator[](int);
	void eliminar(int);
	void eliminar(Bonus* b);
private:
	Bonus* lista[MAX_BONUS];
	int numero;
};