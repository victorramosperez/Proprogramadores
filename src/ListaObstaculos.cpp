#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos()
{
	numero = 0;
	for (int i = 0; i < MAX_OBSTACULOS; i++)
		lista[i] = 0;
}

ListaObstaculos::~ListaObstaculos()
{
}

bool ListaObstaculos::agregar(Obstaculo *o)
{
	if (numero < MAX_OBSTACULOS)
	{
		for (int i = 0;i < numero;i++)
			if (&o == &(lista[i]))return false;
		lista[numero++] = o; // último puesto sin rellenar
	}
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaObstaculos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaObstaculos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de Obstaculos contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaObstaculos::colision(Hombre& h)
{
	for (int i = 0;i < numero;i++)
	{
		Interaccion::colision(h, *(lista[i]));
		//h.recibeDano();
	}
}

Obstaculo* ListaObstaculos::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaObstaculos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index;i < numero;i++)
		lista[i] = lista[i + 1];
}

void ListaObstaculos::eliminar(Obstaculo* o)
{
	for (int i = 0;i < numero;i++)
		if (lista[i] == o)
		{
			eliminar(i);
			return;
		}
}
