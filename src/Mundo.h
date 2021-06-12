#pragma once
#include "Pared.h"
#include "Caja.h"
#include "ListaParedes.h"
#include "Interaccion.h"
#include "Enemigo.h"
#include "Plataforma.h"
#include "ListaPlataformas.h"
#include "ListaDisparos.h"
#include "ListaEnemigos.h"
#include "ListaObstaculos.h"
class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto;
	Caja caja;
	Hombre hombre;
	ListaPlataformas plataformas;
	ListaDisparos disparos;
	ListaEnemigos enemigos;
	ListaObstaculos obstaculos;
public: 
	~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	bool cargarNivel();
	void setNivel(int);
	ListaParedes paredes;
	int nivel;
	friend class Coordinador;
};
