#include "ListaEnemigos.h"


ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = 0;
}

ListaEsferas::~ListaEsferas()
{
	destruirContenido();
}


bool ListaEnemigos::agregar(Enemigo* e)
{
	if (numero < MAX_ENEMIGOS) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == e)
				return false; //Enemigo ya incluido
		}
		lista[numero++] = e; // último puesto sin rellenar 
	}
	else
		return false; // capacidad máxima alcanzada 
	return true;
}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
