#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos()
{
	numero = 0;
	for (int i = 0; i < MAX_OBSTACULOS; i++)
		lista[i] = 0;
}

bool ListaObstaculos::agregar(Obstaculo *o)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == o)
			return false;

	if (numero < MAX_OBSTACULOS)
		lista[numero++] = o; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaObstaculos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaObstaculos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}




void ListaObstaculos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de Obstaculos contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

Obstaculo* ListaObstaculos::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión
}

Obstaculo* ListaObstaculos::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima i=numero-1;
		if (i < 0) //si el indice es negativo, devuelvo la primera 
			i = 0;
	return lista[i];
}