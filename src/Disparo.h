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
	void setPos(float ix, float iy);
	void setPos(Vector2D pos);
	SpriteSequence sprite{ "imagenes/disparo.png", 1 };
};
