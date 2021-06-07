#pragma once
#include "Pared.h"
#include "Caja.h"
#include "ListaParedes.h"
#include "Interaccion.h"
#include "Enemigo.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto;
	Caja cajita;
	Hombre hombre;
	Enemigo enemigo;
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
};
