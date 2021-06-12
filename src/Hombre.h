#pragma once
#include "Dimensiones.h"
#include "ObjetoMovil.h"
#include "Bonus.h"
#include "Obstaculo.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
class Hombre :public ObjetoMovil
{
protected:
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    float altura = 1.8f;
    float anchura = 0.5f;
    Dimensiones dim;
    int vida=1;
    bool dispEspecial=false;
    bool vivo;
public:
    Hombre();
    ~Hombre();
    void dibuja();
    void mueve(float t);
    void setVel(float vx, float vy);
    void setPos(float ix, float iy);
    Vector2D getVel() { return velocidad; }
    Vector2D getPos() { return posicion; }
    Dimensiones getDim() { return dim; }
    int getVida() { return vida; }
    bool getDispEspecial() { return dispEspecial; }
    void setDispEspecial(bool b) { dispEspecial = b; }
    void setVida(int v) { vida = v; }
    //bool cogerBonus(Bonus b);
    void recibeDano() { vida--; }
    void recibeVida() { vida++; }
    SpriteSequence sprite{ "imagenes/samus.png", 3 };
    friend class Interaccion;
};