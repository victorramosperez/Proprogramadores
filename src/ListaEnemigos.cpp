#include "ListaEnemigos.h"


ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = 0;
}

ListaEnemigos::~ListaEnemigos()
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

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de enemigos contenidos
		delete lista[i];
	numero = 0; // inicializa lista
}
void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

	
