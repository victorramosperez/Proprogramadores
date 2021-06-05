#pragma once
#include "ObjetoMovil.h"

class Enemigo : public ObjetoMovil
{
protected:

    int Direccion;
    int Vida;
    bool Vivo;

public:
    Enemigo();
    ~Enemigo();
    void dibuja();
    void setDireccion(int ndir) { Direccion = ndir; }
    int getDireccion() { return Direccion; }
};


class EnemigoSimple : public Enemigo { 
public:
	EnemigoSimple(Vector2D posicion);
protected:
	//sprite
};
