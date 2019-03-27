#include "pch.h"
#include "Nodo.h"

Nodo::Nodo()
{
}

Nodo::Nodo(Espacio esp)
{
	espacio = esp;
	sig = NULL;
}

void Nodo::SetEspacio(Espacio esp) {
	espacio = esp;
}

Espacio Nodo::GetEspacio() {
	return espacio;
}

void Nodo::SetSig(Nodo *x) {
	sig = x;
}

Nodo *Nodo::GetSig() {
	return sig;
}
