#pragma once
class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto;
	int nivel;
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
};
