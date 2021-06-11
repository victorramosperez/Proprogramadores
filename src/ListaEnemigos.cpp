#include "ListaEnemigos.h"

ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0;i < MAX_ENEMIGOS;i++)
		lista[i] = 0;
}

ListaEnemigos::~ListaEnemigos()
{
}

bool ListaEnemigos::agregar(Enemigo* e)
{
	if (numero < MAX_ENEMIGOS)
	{
		for (int i = 0;i < numero;i++)
			if (&e == &(lista[i]))return false;
		lista[numero++] = e; // último puesto sin rellenar
	}
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0;i < numero;i++) // destrucción de Enemigos contenidos
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaEnemigos::mueve(float t)
{
	for (int i = 0;i < numero;i++)
		lista[i]->mueve(t);
}

void ListaEnemigos::dibuja()
{
	for (int i = 0;i < numero;i++)
		lista[i]->dibuja();
}

void ListaEnemigos::colision(Disparo d)
{
	for (int i = 0;i < numero;i++)
	{
		if (Interaccion::colision(d, *(lista[i])))
		{
			delete lista[i];
			numero--;
			for (int j = i;j < numero;j++)
				lista[j] = lista[j + 1];
		}
	}
}
/*
void ListaEnemigos::colision(Pared p)
{
	for (int i = 0;i < numero;i++)
	{
		if (Interaccion::colision(*(lista[i]), p))
		{
			delete lista[i];
			numero--;
			for (int j = i;j < numero;j++)
				lista[j] = lista[j + 1];
		}

	}
}

void ListaEnemigos::colision(Caja c)
{
	for (int i = 0;i < numero;i++)
	{
		if (Interaccion::colision(*(lista[i]), c))
		{
			delete lista[i];
			numero--;
			for (int j = i;j < numero;j++)
				lista[j] = lista[j + 1];
		}
	}
}

void ListaEnemigos::colision(Plataforma p)
{
	for (int i = 0;i < numero;i++)
	{
		if (Interaccion::colision(*(lista[i]), p))
		{
			delete lista[i];
			numero--;
			for (int j = i;j < numero;j++)
				lista[j] = lista[j + 1];
		}

	}
}
*/
Enemigo* ListaEnemigos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index;i < numero;i++)
		lista[i] = lista[i + 1];
}

void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0;i < numero;i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}