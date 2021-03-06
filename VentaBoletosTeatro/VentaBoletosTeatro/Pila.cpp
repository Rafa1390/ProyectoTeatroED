#include "pch.h"
#include "Pila.h"
#include <iostream>
using namespace std;

Pila::Pila()
{
	setCabeza(NULL);
}

Pila::~Pila() {
}

void Pila::setCabeza(Nodo * x) {
	cabeza = x;
}

Nodo* Pila::getCabeza() {
	return cabeza;
}

void Pila::insertarElem(Espacio x) {
	Nodo * aux;
	aux = new Nodo(x);

	aux->SetSig(getCabeza());
	setCabeza(aux);
	sumarLongitud();
}

void Pila::mostrarPila() {
	Nodo *actual = NULL;
	actual = getCabeza();
	if (getCabeza() != NULL) {
		cout << endl << "Elementos de la pila: " << endl << endl;
		while (actual != NULL) {
			std::cout << actual->GetEspacio().GetEstado() << ", " << actual->GetEspacio().GetNombre() << 
				", " << actual->GetEspacio().GetTipo() << ", " << actual->GetEspacio().GetCosto() <<
				", " << actual->GetEspacio().GetNumEspacio() << ", " << endl;
			actual = actual->GetSig();
		}
		std::cout << endl;
	}
	else {
		std::cout << endl << "No hay elementos en la pila." << endl << endl;
	}
}

void Pila::liberarReservas()
{
	while (this->getLongitud() != 0) {
		this->RetirarElemTope();
	}
}

Espacio Pila::RetirarElemTope() {
	Espacio *valor = new Espacio();
	if (getCabeza() != NULL) {
		Nodo * aux;
		aux = getCabeza();
		valor = &aux->GetEspacio();
		valor->SetCosto(aux->GetEspacio().GetCosto());
		valor->SetEstado(aux->GetEspacio().GetEstado());
		valor->SetNombre(aux->GetEspacio().GetNombre());
		valor->SetTipo(aux->GetEspacio().GetTipo());
		setCabeza(getCabeza()->GetSig());
		restarLongitud();
	}
	else {
		cout << "No hay datos registrados dentro de la Pila." << endl;
	}
	return *valor;
}


//Implementacion de los metodos extra

void Pila::sumarLongitud() {
	longitud++;
}

void Pila::restarLongitud() {
	longitud = longitud--;
}

int Pila::getLongitud() {
	return longitud;
}


Espacio Pila::topePila() {
	return (cabeza->GetSig())->GetEspacio();
}

bool Pila::esVaciaPila() {
	if (getCabeza() == NULL) {
		return false;
	}
	else {
		return true;
	}
}