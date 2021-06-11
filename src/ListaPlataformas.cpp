#include "ListaPlataformas.h"

ListaPlataformas::ListaPlataformas()
{
	numero = 0;
	for (int i = 0; i < MAX_PLATAFORMAS; i++)
		lista[i] = 0;
}

bool ListaPlataformas::agregar(Plataforma* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
			return false;

	if (numero < MAX_PLATAFORMAS)
		lista[numero++] = p; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaPlataformas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}




void ListaPlataformas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de Plataformaes contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

Plataforma* ListaPlataformas::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		//if (Interaccion::colision(*(lista[i]), h))
			//return lista[i];
	}
	return 0; //no hay colisión
}

Plataforma* ListaPlataformas::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima i=numero-1;
		if (i < 0) //si el indice es negativo, devuelvo la primera 
			i = 0;
	return lista[i];
}

void ListaPlataformas::rebote(Hombre& h)
{
	for (int i = 0;i < numero;i++)
		Interaccion::rebote(h, *(lista[i]));
		
}