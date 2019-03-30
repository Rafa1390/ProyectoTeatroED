#include "pch.h"
#include "ListaEspacios.h"

ListaEspacios::ListaEspacios()
{
	SetCabeza(NULL);
	longitud = 0;
	pagados = 0;
	montoTotal = 0;
}

void ListaEspacios::SetCabeza(Nodo *x) {
	cabeza = x;
}

Nodo * ListaEspacios::GetCabeza() {
	return cabeza;
}

void ListaEspacios::SetLong(int x) {
	longitud = x;
}

int ListaEspacios::GetLong() {
	return longitud;
}

void ListaEspacios::SetPagados(int x) {
	pagados = x;
}

int ListaEspacios::GetPagados() {
	return pagados;
}

void ListaEspacios::SetMontoTotal(float x) {
	montoTotal = x;
}

float ListaEspacios::GetMontoTotal() {
	return montoTotal;
}

void ListaEspacios::ReservarEspacioVIP(Espacio esp) {
	Nodo * nuevo = new Nodo(esp);

	if (GetCabeza() == NULL) {
		SetCabeza(nuevo);
	}
	else if (nuevo->GetEspacio().GetNumEspacio() < GetCabeza()->GetEspacio().GetNumEspacio()) {
		nuevo->SetSig(GetCabeza());
		SetCabeza(nuevo);
	}
	else {
		Nodo * ant = GetCabeza();
		Nodo * act = GetCabeza()->GetSig();

		while (act != NULL && act->GetEspacio().GetNumEspacio() < nuevo->GetEspacio().GetNumEspacio()) {
			ant = ant->GetSig();
			act = act->GetSig();
		}

		nuevo->SetSig(ant->GetSig());
		ant->SetSig(nuevo);
	}

	longitud++;
}

int ListaEspacios::ReservarGradGeneral(Espacio esp) {
	Nodo * aux;
	aux = new Nodo(esp);
	int num = esp.GetNumEspacio();

	if (GetCabeza() == NULL) {
		SetCabeza(aux);
	}
	else
	{
		aux->SetSig(GetCabeza());
		SetCabeza(aux);
	}

	longitud++;
	return num;
}

bool ListaEspacios::PagarEspacioReservado(int pNum) {
	Nodo * aux = GetCabeza();
	Espacio info;
	bool realizado = false;

	while (aux != NULL) {

		if (aux->GetEspacio().GetNumEspacio() == pNum) {
			info = aux->GetEspacio();
			info.SetEstado("Pagado");
			aux->SetEspacio(info);
			pagados++;
			montoTotal = montoTotal + aux->GetEspacio().GetCosto();
			realizado = true;
		}
		aux = aux->GetSig();
	}

	return realizado; //Segun lo que devuelva, se valida si se realizó el pago en el main
}

void ListaEspacios::LiberarReservas() {
	Nodo * aux = GetCabeza();
	Espacio info;

	while (aux != NULL) {
		if (aux->GetEspacio().GetEstado() == "Reservado") {
			info = aux->GetEspacio();
			info.SetEstado("Libre");
			info.SetNombre("Sin nombre");
			aux->SetEspacio(info);
		}
		aux = aux->GetSig();
	}
}

bool ListaEspacios::EsDisponible(int num) {
	Nodo * aux = GetCabeza();
	bool disp = true;

	while (aux != NULL) {
		if (aux->GetEspacio().GetNumEspacio() == num) {
			disp = false;
		}
		aux = aux->GetSig();
	}

	return disp;
}

void ListaEspacios::MostrarEspaciosVIP() {
	Nodo * aux = GetCabeza();
	Espacio info;

	while (aux != NULL) {
		info = aux->GetEspacio();

		info.MostrarEspacio(info);
		cout << "\n-------------------\n";

		aux = aux->GetSig();
	}
}

void ListaEspacios::MostrarEspaciosGeneral(Nodo * x) {
	if (x != NULL) {
		MostrarEspaciosGeneral(x->GetSig());
		x->GetEspacio().MostrarEspacio(x->GetEspacio());
		cout << "\n-------------------\n";
	}
}

bool ListaEspacios::IngresarVIP(int pNum, string nombre) {
	Nodo * aux = GetCabeza();
	Espacio info;
	bool realizado = false;

	while (aux != NULL) {

		if (aux->GetEspacio().GetNumEspacio() == pNum && aux->GetEspacio().GetEstado() == "Libre") {
			info = aux->GetEspacio();
			info.SetEstado("Pagado");
			info.SetNombre(nombre);
			aux->SetEspacio(info);
			pagados++;
			montoTotal = montoTotal + aux->GetEspacio().GetCosto();
			realizado = true;
		}
		aux = aux->GetSig();
	}

	return realizado;
}

bool ListaEspacios::IngresarGeneral(string nombre) {
	Nodo * aux = GetCabeza();
	Espacio info;
	bool realizado = false;

	while (aux != NULL) {

		if (realizado == false && aux->GetEspacio().GetEstado() == "Libre") {
			info = aux->GetEspacio();
			info.SetEstado("Pagado");
			info.SetNombre(nombre);
			cout << "Su espacio asignado es el n" << info.GetNumEspacio() << endl;
			aux->SetEspacio(info);
			pagados++;
			montoTotal = montoTotal + aux->GetEspacio().GetCosto();
			realizado = true;
		}
		aux = aux->GetSig();
	}

	return realizado;
}