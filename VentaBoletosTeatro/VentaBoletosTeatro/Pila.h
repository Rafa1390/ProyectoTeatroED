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
	void insertarElem(int);
	int RetirarElemTope();
	Pila pilaEnt();
	int topePila();
	bool esVaciaPila();
	void mostrarPila();

private:
	Nodo * cabeza;
	int longitud = 0;
};