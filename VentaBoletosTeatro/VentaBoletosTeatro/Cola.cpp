#include "pch.h"
#include "Cola.h"
#include "NodoCola.h"
#include <iostream>
using namespace std;

Cola::Cola()
{
	longitud = 0;
	frente = NULL;
	final = NULL;
}

int Cola::getLong() {
	return longitud;
}

void Cola::setFrente(NodoCola * x) {
	frente = x;
}

NodoCola * Cola::getFrente() {
	return frente;
}

void Cola::setFinal(NodoCola * y) {
	final = y;
}

NodoCola * Cola::getFinal() {
	return final;
}

bool Cola::esVacia() {
	bool resp = false;
	if (getFrente() == NULL) {
		resp = true;
	}
	return resp;
}

void Cola::insertarCliente(string x) {
	NodoCola * nuevo = new NodoCola(x);

	if (this->esVacia()) {
		setFrente(nuevo);
		setFinal(nuevo);
	}
	else {
		getFinal()->SetSig(nuevo);
		setFinal(nuevo);
	}
	longitud++;
	cout << "\nEl cliente se ha añadido a la cola\n" << endl;
}

string Cola::atender() {
	string nombre = "";

	if (this->esVacia()) {
		cout << "No hay clientes en la cola" << endl;
	}
	else {
		NodoCola * aux = getFrente();
		nombre = aux->GetCliente();
		setFrente(aux->GetSig());
		aux->SetSig(NULL);
		delete aux;
		longitud--;
	}
	return nombre;
}