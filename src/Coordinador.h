#pragma once
#include "Mundo.h"
#include <string>
#define MAX_PUNTUACIONES 20
class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void ordenaPuntuaciones(int p[MAX_PUNTUACIONES]);
	void anadeScore(int, int[MAX_PUNTUACIONES]);
protected:
	Mundo mundo;
	enum Estado { INICIO,CINEMATICA, JUEGO, GAMEOVER, FIN, PAUSA, SCORE};
	Estado estado;
	int puntuaciones[MAX_PUNTUACIONES];
	//ofstream fout;
	int partida;
};
