#pragma once
#ifndef ESPACIO_H
#define ESPACIO_H
#include <string>
using namespace std;
class Espacio {
private:
	int NumEspacio;
	string Estado = "Libre"; //Reservado o Comprado
	string Tipo;
	float Costo;
	string Nombre = "Sin nombre";
public:
	//Constructores
	Espacio();
	Espacio(int,string,string,float,string);
	//Sets y Gets
	void SetNumEspacio(int);
	int GetNumEspacio(void);
	void SetEstado(string);
	string GetEstado(void);
	void SetTipo(string);
	string GetTipo(void);
	void SetCosto(float);
	float GetCosto(void);
	void SetNombre(string);
	string GetNombre(void);
	//Metodos
	void MostrarEspacio(Espacio);
};
#endif // !ESPACIO_H