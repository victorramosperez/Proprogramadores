#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Disparo : public ObjetoMovil
{
protected:
	float radio;
	Vector2D origen;
	
public:
	Disparo();
	~Disparo();
	virtual void dibuja();
	friend class Interaccion;
	float getRadio();
	SpriteSequence sprite{ "imagenes/disparo.png", 1 };
	void setRadio(float r) { radio = r; }
};
