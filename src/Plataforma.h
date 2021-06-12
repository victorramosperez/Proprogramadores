#pragma once
#include "ColorRGB.h"
#include "Dimensiones.h" 
#include "ETSIDI.h"
class Plataforma
{
protected:
	ColorRGB color;
	Dimensiones dim;
	Vector2D limite1;
	Vector2D limite2;
public:
	Plataforma();
	Plataforma(float x1, float y1, float x2, float y2);
	~Plataforma();
	void setColor(Byte r, Byte g, Byte b);
	void setPos(float x1, float y1, float x2, float y2);
	virtual void dibuja();
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	Dimensiones getDim();
	friend class Interaccion;
};