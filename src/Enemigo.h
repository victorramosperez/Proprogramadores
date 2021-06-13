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
    bool boss = false;
public:
    Enemigo();
    Enemigo(float ix, float iy, float ixmin, float ixmax);
    ~Enemigo();
    virtual void dibuja();
    virtual void mueve(float t);
    void setDireccion(int ndir) { Direccion = ndir; }
    int getDireccion() { return Direccion; }
    void setBoss(bool b) { boss = b; }
    bool getBoss() { return boss; }
    SpriteSequence sprite{ "imagenes/enemigo8.png", 3 };
    friend class Interaccion;
};
