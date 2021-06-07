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
public:
    Enemigo();
    ~Enemigo();
    void dibuja();
    void setDireccion(int ndir) { Direccion = ndir; }
    int getDireccion() { return Direccion; }
    
    SpriteSequence sprite{ "imagenes/zoomer.png", 5 };
    friend class Interaccion;
    
};

class EnemigoSimple : public Enemigo { 
public:
	//EnemigoSimple(Vector2D posicion);
protected:
	//sprite
};
