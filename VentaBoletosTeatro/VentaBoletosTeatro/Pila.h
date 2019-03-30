#pragma once
#include "Nodo.h"

class Pila
{
public:
	Pila();
	~Pila();

	Nodo* getCabeza();
	void setCabeza(Nodo *x);
	void sumarLongitud();
	void restarLongitud();
	int getLongitud();
	void insertarElem(Espacio);
	Espacio RetirarElemTope();
	Espacio topePila();
	bool esVaciaPila();
	void mostrarPila();
	void liberarReservas();

private:
	Nodo * cabeza;
	int longitud = 0;
};