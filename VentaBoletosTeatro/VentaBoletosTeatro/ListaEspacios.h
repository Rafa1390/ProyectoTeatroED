#pragma once
#ifndef LISTAESPACIOS_H
#define LISTAESPACIOS_H
#include "Nodo.h"
class ListaEspacios
{
private:
	Nodo * cabeza;
	int longitud;
	int pagados;
	float montoTotal;
public:
	ListaEspacios();
	void SetCabeza(Nodo*);
	Nodo * GetCabeza(void);
	void SetLong(int);
	int GetLong(void);
	void SetPagados(int);
	int GetPagados(void);
	void SetMontoTotal(float);
	float GetMontoTotal(void);
	void ReservarEspacioVIP(Espacio); //insertar ordenado
	void ReservarGradGeneral(Espacio);// insertar al inicio
	bool PagarEspacioReservado(int);
	void LiberarReservas(void);
	bool EsDisponible(int);
};
#endif // !LISTAESPACIOS_H
