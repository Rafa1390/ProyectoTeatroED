#pragma once
#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
class Cola
{
private:
	int longitud;
	NodoCola * frente;
	NodoCola * final;
public:
	Cola();
	int getLong(void);
	void setFrente(NodoCola*);
	NodoCola * getFrente(void);
	void setFinal(NodoCola*);
	NodoCola * getFinal(void);
	bool esVacia();
	void insertarCliente(string);
	string atender();
};
#endif