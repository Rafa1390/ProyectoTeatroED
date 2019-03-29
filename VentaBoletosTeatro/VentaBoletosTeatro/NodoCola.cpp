#include "pch.h"
#include "NodoCola.h"

NodoCola::NodoCola() {
}

NodoCola::NodoCola(string x) {
	cliente = x;
	sig = NULL;
}

void NodoCola::SetCliente(string x) {
	cliente = x;
}

string NodoCola::GetCliente() {
	return cliente;
}

void NodoCola::SetSig(NodoCola *x) {
	sig = x;
}

NodoCola *NodoCola::GetSig() {
	return sig;
}