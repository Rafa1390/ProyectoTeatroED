#include "pch.h"
#include "Espacio.h"
#include <iostream>
using namespace std;

Espacio::Espacio()
{
}

Espacio::Espacio(int pNumEspacio, string pEstado, string pTipo, float pCosto, string pNombre)
{
	NumEspacio = pNumEspacio;
	Estado = pEstado;
	Tipo = pTipo;
	Costo = pCosto;
	Nombre = pNombre;
}

//NumEspacio
void Espacio::SetNumEspacio(int num) {
	NumEspacio = num;
}

int Espacio::GetNumEspacio(void) {
	return NumEspacio;
}
//Estado
void Espacio::SetEstado(string estado) {
	Estado = estado;
}

string Espacio::GetEstado(void) {
	return Estado;
}
//Tipo
void Espacio::SetTipo(string tipo) {
	Tipo = tipo;
}

string Espacio::GetTipo(void) {
	return Tipo;
}
//Costo
void Espacio::SetCosto(float costo) {
	Costo = costo;
}

float Espacio::GetCosto(void) {
	return Costo;
}
//Nombre
void Espacio::SetNombre(string nombre) {
	Nombre = nombre;
}

string Espacio::GetNombre(void) {
	return Nombre;
}

void Espacio::MostrarEspacio(Espacio espacio) {
	cout << "Numero: " << espacio.GetNumEspacio() << endl;
	cout << "Estado: " << espacio.GetEstado() << endl;
	cout << "Tipo: " << espacio.GetTipo() << endl;
	cout << "Costo: " << espacio.GetCosto() << endl;
	cout << "Nombre: " << espacio.GetNombre() << endl;
}