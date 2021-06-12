#pragma once
#include "Pared.h"
#include "Caja.h"
#include "Interaccion.h"
#include "Enemigo.h"
#include "Plataforma.h"
#include "ListaPlataformas.h"
#include "ListaDisparos.h"
#include "ListaEnemigos.h"
#include "ListaObstaculos.h"
#include "ListaBonus.h"
#include "BonusVida.h"
#include "BonusDisparo.h"
#include "BonusLlave.h"
#include "PlataformaPuerta.h"
#include "EnemigoBoss.h"
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
	ListaBonus bonus;
	int puntos = 0;
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
	int nivel;
	friend class Coordinador;
};
