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
void liberarReservas();
void mostrarEspacios();

ListaEspacios *ListaVIP = new ListaEspacios();
ListaEspacios *ListaGeneral = new ListaEspacios();
Pila *graderia1_1 = new Pila();
Pila *graderia1_2 = new Pila();
Pila *graderia1_3 = new Pila();
Pila *graderia1_4 = new Pila();
Pila *graderia1_5 = new Pila();
Pila *graderia2_1 = new Pila();
Pila *graderia2_2 = new Pila();
Pila *graderia2_3 = new Pila();
Pila *graderia2_4 = new Pila();
Pila *graderia2_5 = new Pila();
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
			<< "5. Mostrar espacios" << endl
			<< "6. Mostrar teatro./Extra" << endl
			<< "7. Mostrar teatro(modo grafico)./extra" << endl
			<< "8. Salir." << endl << endl
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
			liberarReservas();
			break;
		case 4:
			break;
		case 5:
			mostrarEspacios();
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
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
	int fila;
	bool disp = false;
	string nombre;

	cout << "\n---VIP---" << endl;
	if (ListaVIP->GetLong() <= 10) {
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
	int fila = 3;
	string nombre = "";
	cout << "\n---Preferenciales---" << endl<<
		"Por favor seleccionar una de las graderias preferenciales:"<< endl
		<<"1. A la derecha del escenario." << endl
		<< "2. A la izquierda del escenario." << endl;
	try {
		cin >> lector;
	}
	catch (exception e) {
		lector = 3;
	}
	
	switch (lector) {

	case 1:
		cout << "\nGraderia preferencial 1" << endl << endl << 
			"Ingrese la fila en la que desea reservar: 1,2,3,4 o 5." << endl;
		try {
			cout << "Ingrese su nombre:" << endl;
			cin >> nombre;
			cin >> fila;
			Espacio *temp = new Espacio(contGeneral, "Reservado", "Preferencial", 5500, nombre);
			reservarGraderia1(temp, fila, nombre);

		}
		catch (exception e) {
			cout << "Ha ocurrido un error, por favor intentelo de nuevo.";
		}
		break;

	case 2:
		cout << "\nGraderia preferencial 2" << endl << endl <<
			"Ingrese la fila en la que desea reservar: 1,2,3,4 o 5." << endl;
		try {
			cout << "Ingrese su nombre:" << endl;
			cin >> nombre;
			cin >> fila;
			Espacio *temp = new Espacio(contGeneral, "Reservado", "Preferencial", 5500, nombre);
			reservarGraderia1(temp, fila, nombre);
		}
		catch (exception e) {
			cout << "Ha ocurrido un error, por favor intentelo de nuevo.";
		}
		break;

	default:
		cout << "Opcion no valida" << endl;
		break;

	}
}

void reservarGraderia1(Espacio *temp, int fila, string nombre) {
	switch (fila) {
	case 1:
		if (graderia1_1->getLongitud() < 5) {
			graderia1_1->insertarElem(*temp);
			contGeneral++;
			graderia1_1->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	case 2:
		if (graderia1_2->getLongitud() < 5) {
			graderia1_2->insertarElem(*temp);
			contGeneral++;
			graderia1_2->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	case 3:
		if (graderia1_3->getLongitud() < 5) {
			graderia1_3->insertarElem(*temp);
			contGeneral++;
			graderia1_3->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	case 4:
		if (graderia1_4->getLongitud() < 5) {
			graderia1_4->insertarElem(*temp);
			contGeneral++;
			graderia1_4->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	case 5:
		if (graderia1_5->getLongitud() < 5) {
			graderia1_5->insertarElem(*temp);
			contGeneral++;
			graderia1_5->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	default:
		break;
	}
}

void reservarGraderia2(Espacio *temp, int fila, string nombre) {
	switch (fila) {
	case 1:

		if (graderia2_1->getLongitud() < 5) {
			graderia2_1->insertarElem(*temp);
			contGeneral++;
			graderia2_1->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	case 2:
		if (graderia2_2->getLongitud() < 5) {
			graderia2_2->insertarElem(*temp);
			contGeneral++;
			graderia2_2->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}

		break;
	case 3:
		if (graderia2_3->getLongitud() < 5) {
			graderia2_3->insertarElem(*temp);
			contGeneral++;
			graderia2_3->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	case 4:
		if (graderia2_4->getLongitud() < 5) {
			graderia2_4->insertarElem(*temp);
			contGeneral++;
			graderia2_4->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	case 5:
		if (graderia2_5->getLongitud() < 5) {
			graderia2_5->insertarElem(*temp);
			contGeneral++;
			graderia2_5->mostrarPila();
		}
		else {
			cout << "Lo sentimos esta fila esta llena." << endl;
		}
		break;
	default:
		break;
	}
}

void reservarGeneral() {
	string nombre;
	int num;

	cout << "\n---General---" << endl;
	if (ListaGeneral->GetLong() <= 50) {
		cout << "\nDigite el nombre de quien realiza la reserva" << endl;
		cin >> nombre;
		Espacio espacio(contGeneral, "Reservado", "General", 4000, nombre);
		num = ListaGeneral->ReservarGradGeneral(espacio);
		contGeneral++;
		cout << "\n" << nombre << " ha reservado en el espacio n" << num << "\n" << endl;
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
	bool disp = true, pago = false;

	do {
		cout << "\nDigite el numero del espacio en el que hizo la reservacion" << endl;
		cin >> num;
		if (num >= 1 || num <= 10) {
			disp = ListaVIP->EsDisponible(num);
			if (disp == false) {
				pago = ListaVIP->PagarEspacioReservado(num);
				if (pago != false) {
					cout << "\nPago realizado" << endl;
				}
				else {
					cout << "\nEl pago no pudo efectuarse" << endl;
				}
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
	int num;
	bool disp = true, pago = false;

	do {
		cout << "\nDigite el numero del espacio en el que hizo la reservacion" << endl;
		cin >> num;
		if (num >= 1 || num <= 50) {
			disp = ListaGeneral->EsDisponible(num);
			if (disp == false) {
				pago = ListaGeneral->PagarEspacioReservado(num);
				if (pago != false) {
					cout << "\nPago realizado" << endl;
				}
				else {
					cout << "\nEl pago no pudo efectuarse" << endl;
				}
			}
			else {
				cout << "\nEl numero del espacio ingresado no se encuentra en reserva" << endl;
			}
		}
		else {
			cout << "\nEl numero que ingreso es incorrecto" << endl;
			cout << "Por favor ingrese un numero del 1 al 50" << endl;
		}
	} while (num < 1 || num > 50 || disp == true);
}

void liberarReservas() {
	ListaVIP->LiberarReservas();
	//Liberar reservas preferencial
	ListaGeneral->LiberarReservas();
	cout << "\nReservas liberadas" << endl;
}

void mostrarEspacios() {
	cout << "\n----Zona VIP----" << endl;
	cout << "******************" << endl;
	ListaVIP->MostrarEspaciosVIP();
	cout << "******************" << endl;
	cout << "\n----Zona General----" << endl;
	cout << "******************" << endl;
	ListaGeneral->MostrarEspaciosGeneral(ListaGeneral->GetCabeza());
	cout << "******************" << endl;
}