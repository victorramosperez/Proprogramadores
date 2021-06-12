#include "ListaBonus.h"
#include "ListaDisparos.h"
ListaBonus::ListaBonus()
{
	numero = 0;
	for (int i = 0;i < MAX_BONUS;i++)
		lista[i] = 0;
}

ListaBonus::~ListaBonus()
{
}

bool ListaBonus::agregar(Bonus* b)
{
	if (numero < MAX_BONUS)
	{
		for (int i = 0;i < numero;i++)
			if (&b == &(lista[i]))return false;
		lista[numero++] = b; // último puesto sin rellenar
	}
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaBonus::destruirContenido()
{
	for (int i = 0;i < numero;i++) // destrucción de Bonuss contenidos
		delete lista[i];
	numero = 0; // inicializa lista
}


void ListaBonus::dibuja()
{
	for (int i = 0;i < numero;i++)
		lista[i]->dibuja();
}

void ListaBonus::colision(Hombre& h)
{
	for (int i = 0;i < numero;i++)
	{
		if (Interaccion::colision(h, *(lista[i])))
		{
			if ((*lista[i]).identificador == 1)
				h.recibeVida();
			else if ((*lista[i]).identificador == 2)h.setDispEspecial(true);
			else h.setLlave(true);
			delete lista[i];
			numero--;
			for (int j = i;j < numero;j++)
				lista[j] = lista[j + 1];
		}

	}
}

Bonus* ListaBonus::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaBonus::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index;i < numero;i++)
		lista[i] = lista[i + 1];
}

void ListaBonus::eliminar(Bonus* b)
{
	for (int i = 0;i < numero;i++)
		if (lista[i] == b)
		{
			eliminar(i);
			return;
		}
}