#pragma once
#ifndef NODO_H
#define NODO_H
#include "Espacio.h"
#include <iostream>
class Nodo
{
private:
	Espacio espacio;
	Nodo * sig;
public:
	Nodo();
	Nodo(Espacio);
	void SetEspacio(Espacio);
	Espacio GetEspacio(void);
	void SetSig(Nodo *);
	Nodo *GetSig(void);
};
#endif // !NODO_H


