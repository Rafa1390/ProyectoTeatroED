// VentaBoletosCine.cpp : Este archivo contiene, la clase main del proyecto.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "ListaEspacios.h"
#include "Espacio.h"
#include "Pila.h"
#include <string>
using namespace std;

void reservarEspacio();
void reservarVIP();
void reservarPreferencial();
void reservarGeneral();
void pagarReservacion();
void pagarVIP();
void pagarGeneral();

ListaEspacios *ListaVIP = new ListaEspacios();
ListaEspacios *ListaGeneral = new ListaEspacios();
Pila *graderiaPreferencialIzquierda = new Pila();
Pila *graderiaPreferencialDerecha = new Pila();
int contGeneral = 1;

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
			pagarReservacion();
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
			if (numEsp > 0 || numEsp <= 10) {
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
			}
			else {
				cout << "\nLa zona VIP solo cuenta con 10 espacios." << endl;
				cout << "Por favor ingrese un numero del 1 al 10." << endl;
			}
			
		} while (disp == false || numEsp < 1 || numEsp > 10);
	}
	else {
		cout << "\nYa no hay espacios en la zona VIP" << endl;
	}
	
}

void reservarPreferencial() {
	int lector = 0;
	string nombre = "";
	cout << "\n---Preferenciales---" << endl<<
		"Por favor seleccionar una de las graderias preferenciales:"<< endl
		<<"1. A la derecha del escenario." << endl
		<< "2. A la derecha del escenario." << endl;
	try {
		cin >> lector;
	}
	catch (exception e) {
		lector = 3;
	}
	
	switch (lector) {

	case 1:

	if (graderiaPreferencialDerecha->getLongitud() <=25) {
		cout << "\nGraderia preferencial 1" << endl <<
			"Ingrese su nombre" << endl;
		cin >> nombre;
		Espacio *temp = new Espacio(contGeneral, "Reservado", "Preferencial", 5500, nombre);
		graderiaPreferencialDerecha->insertarElem(*temp);
		contGeneral++;
		graderiaPreferencialDerecha->mostrarPila();
	}
	else {
		cout << "No quedan espacios disponibles en la graderia 1." << endl;
	}
		break;

	case 2:

	if (graderiaPreferencialIzquierda->getLongitud() <= 25) {
		cout << "\nGraderia preferencial 2" << endl <<
			"Ingrese su nombre" << endl;
		cin >> nombre;
		Espacio *temp = new Espacio(contGeneral, "Reservado", "Preferencial", 5500, nombre);
		graderiaPreferencialIzquierda->insertarElem(*temp);
		contGeneral++;
		graderiaPreferencialIzquierda->mostrarPila();
	}
	else {
		cout << "No quedan espacios disponibles en la graderia 2." << endl;
	}
		break;

	default:
		cout << "Opcion no valida" << endl;
		break;

	}

	

}

void reservarGeneral() {
	string nombre;

	cout << "\n---General---" << endl;
	if (ListaGeneral->GetLong() <= 50) {
		cout << "\nDigite el nombre de quien realiza la reserva" << endl;
		cin >> nombre;
		Espacio espacio(contGeneral, "Reservado", "General", 4000, nombre);
		ListaVIP->ReservarEspacioVIP(espacio);
		contGeneral++;
	}
	else {
		cout << "\nYa no hay espacios en la zona General" << endl;
	}
}

void pagarReservacion() {
	int opc;
	cout << "\nSeleccione la zona en la que se realizó la reservación\npara efectuar el pago" << endl;
	cout << "1. VIP" << endl;
	cout << "2. Preferencial" << endl;
	cout << "3. General" << endl;
	cin >> opc;
	do {
		switch (opc)
		{
		case 1:
			pagarVIP();
			break;
		case 2:
			//Pagar preferencial
			break;
		case 3:
			pagarGeneral();
			break;
		default:
			cout << "\nOpcion incorrecta" << endl;
			break;
		}
	} while (opc < 1 || opc > 3);
}

void pagarVIP() {
	int num;
	bool disp = true;

	do {
		cout << "\nDigite el numero del espacio en el que hizo la reservacion" << endl;
		cin >> num;
		if (num >= 1 || num <= 10) {
			disp = ListaVIP->EsDisponible(num);
			if (disp == false) {
				ListaVIP->PagarEspacioReservado(num);
			}
			else {
				cout << "\nEl numero del espacio ingresado no se encuentra en reserva" << endl;
			}
		}
		else {
			cout << "\nEl numero que ingreso es incorrecto" << endl;
			cout << "Por favor ingrese un numero del 1 al 10" << endl;
		}
	} while (num < 1 || num > 10 || disp == true);
}

void pagarGeneral() {

}