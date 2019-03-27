// VentaBoletosCine.cpp : Este archivo contiene, la clase main del proyecto.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "ListaEspacios.h"
#include "Espacio.h"
#include "Pila.h"
using namespace std;

void reservarEspacio();
void reservarVIP();
void reservarPreferencial();
void reservarGeneral();

ListaEspacios *ListaVIP = new ListaEspacios();
ListaEspacios *ListaGeneral = new ListaEspacios();
Pila *graderiaPreferencial = new Pila();

int main()
{
	int breaker = 0;
	int lectura = 0;

	while (breaker == 0) {

		std::cout << "========Boletos Teatro========" << endl << endl
			<< "1. Realizar reservacion." << endl
			<< "2. Pagar reservacion realizada." << endl
			<< "3. Liberar reservaciones." << endl
			<< "4. Iniciar la Funcion." << endl
			<< "5. Mostrar teatro./Extra" << endl
			<< "6. Mostrar teatro(modo grafico)./extra" << endl
			<< "7. Salir." << endl << endl
			<< "============================" << endl;

		std::cin >> lectura;

		switch (lectura) {
		case 1:
			reservarEspacio();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			breaker = 1;
			std::cout << "Gracias por usar nuestra servicio, lo esperamos pronto." << endl;
			break;

		}
	}
}

void reservarEspacio() {
	int opc;
	cout << "\nSeleccione la zona en la que desea reservar" << endl;
	cout << "1. VIP" << endl;
	cout << "2. Preferencial" << endl;
	cout << "3. General" << endl;
	cin >> opc;
	do {
		switch (opc)
		{
		case 1:
			reservarVIP();
			break;
		case 2:
			reservarPreferencial();
			break;
		case 3:
			reservarGeneral();
			break;
		default:
			cout << "\nOpcion incorrecta" << endl;
			break;
		}
	} while (opc < 1 || opc > 3);
}

void reservarVIP() {
	int numEsp;
	bool disp = false;
	string nombre;

	cout << "\n---VIP---" << endl;
	if (ListaVIP->GetLong() < 10) {
		do {
			cout << "\nDigite el numero del espacio que desea reservar" << endl;
			cin >> numEsp;
			disp = ListaVIP->EsDisponible(numEsp);
			if (disp == true) {
				cout << "\nDigite el nombre de quien realiza la reserva" << endl;
				cin >> nombre;
				Espacio espacio(numEsp, "Reservado", "VIP", 7000, nombre);
				ListaVIP->ReservarEspacioVIP(espacio);
			}
			else {
				cout << "\nEl espacio ingresado ya se encuentra reservado" << endl;
			}
		} while (disp == false);
	}
	else {
		cout << "\nYa no hay espacios en la zona VIP" << endl;
	}
	
}

void reservarPreferencial() {

}


void reservarGeneral() {

}