#pragma once
#include "ObjetoMovil.h"
#include "ETSIDI.h"


using ETSIDI::SpriteSequence;
class Enemigo : public ObjetoMovil
{
protected:
    int Direccion;
    int Vida;
    bool Vivo;
    float Altura;
    float xmax;
    float xmin;
public:
    Enemigo();
    Enemigo(float ix, float iy, float ixmax, float ixmin);
    ~Enemigo();
    void dibuja();
    void mueve(float t);
    void setDireccion(int ndir) { Direccion = ndir; }
    int getDireccion() { return Direccion; }
    
    SpriteSequence sprite{ "imagenes/enemigo8.png", 3 };
    friend class Interaccion;
    
};

class EnemigoSimple : public Enemigo { 
public:
	//EnemigoSimple(Vector2D posicion);
protected:
	//sprite
};
