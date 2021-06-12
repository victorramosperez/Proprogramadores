#include "ListaDisparos.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0;i < MAX_DISPAROS;i++)
		lista[i] = 0;
}

ListaDisparos::~ListaDisparos()
{
}

bool ListaDisparos::agregar(Disparo* d)
{
	if (numero < MAX_DISPAROS)
	{
		for (int i = 0;i < numero;i++)
			if (&d == &(lista[i]))return false;
		lista[numero++] = d; // último puesto sin rellenar
	}
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0;i < numero;i++) // destrucción de disparos contenidos
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0;i < numero;i++)
		lista[i]->mueve(t);
}

void ListaDisparos::dibuja()
{
	for (int i = 0;i < numero;i++)
		lista[i]->dibuja();
}

void ListaDisparos::colision(Pared p)
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

void ListaDisparos::colision(Caja c)
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

void ListaDisparos::colision(Plataforma p)
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

Disparo* ListaDisparos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index;i < numero;i++)
		lista[i] = lista[i + 1];
}

void ListaDisparos::eliminar(Disparo* d)
{
	for (int i = 0;i < numero;i++)
		if (lista[i] == d)
		{
			eliminar(i);
			return;
		}
}


