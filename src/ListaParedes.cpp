#include "ListaParedes.h"

ListaParedes::ListaParedes()
{
	numero = 0;
	for (int i = 0; i < MAX_PAREDES; i++)
		lista[i] = 0;
}

bool ListaParedes::agregar(Pared* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
			return false;

	if (numero < MAX_PAREDES)
		lista[numero++] = p; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaParedes::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}




void ListaParedes::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de Paredes contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

Pared* ListaParedes::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		//if (Interaccion::colision(*(lista[i]), h))
			//return lista[i];
	}
	return 0; //no hay colisión
}

Pared* ListaParedes::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima i=numero-1;
		if (i < 0) //si el indice es negativo, devuelvo la primera 
			i = 0;
	return lista[i];
}