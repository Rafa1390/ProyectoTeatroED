// VentaBoletosCine.cpp : Este archivo contiene, la clase main del proyecto.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "ListaEspacios.h"
#include "Espacio.h"
#include "Pila.h"
#include "Cola.h"
#include <string>
using namespace std;

void reservarEspacio();
void reservarVIP();
void reservarPreferencial();
void reservarGeneral();
void reservarGraderia1(Espacio *temp, int fila, string nombre);
void reservarGraderia2(Espacio *temp, int fila, string nombre);
void pagarPreferencial();
void pagarGraderia1(int fila, string nombre);
void pagarGraderia2(int fila, string nombre);
void realizarPagoGraderiaEnFila(Pila *graderia, Pila *graderiaPagado, string nombre);
void pagarReservacion();
void pagarVIP();
void pagarGeneral();
void liberarReservas();
void liberarReservasPreferencial();
void mostrarEspacios();
void iniciarFuncion();
int conseguirTotalEspaciosPreferencialesPagos();
double MontoTotalPreferencial();
void enviarACola();
void atenderClienteCola();
void ingresarVIP(string);
void ingresarGeneral(string);
void ingresarPreferencialDesdeCola(string);
void ingresarGraderia1PagoDesdeCola(string nombre, int fila);
void ingresarGraderia2PagoDesdeCola(string nombre, int fila);
void mostrarTeatro();
void imprimirVIP();
void imprimirPreferenciales();
void imprimirFila(Pila *fila, Pila *filaPago);
void imprimirTipoEstado(string estado);
void imprimirRegulares();

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
Cola *colaClientes = new Cola();

Pila *graderia1_1Pagado = new Pila();
Pila *graderia1_2Pagado = new Pila();
Pila *graderia1_3Pagado = new Pila();
Pila *graderia1_4Pagado = new Pila();
Pila *graderia1_5Pagado = new Pila();
Pila *graderia2_1Pagado = new Pila();
Pila *graderia2_2Pagado = new Pila();
Pila *graderia2_3Pagado = new Pila();
Pila *graderia2_4Pagado = new Pila();
Pila *graderia2_5Pagado = new Pila();

int contGeneral = 1, contGradGeneral = 1;
bool reservasLib = false;

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
			<< "6. Atender clientes en cola" << endl
			<< "7. Mostrar teatro./Extra" << endl
			<< "8. Mostrar teatro(modo grafico)./extra" << endl
			<< "9. Salir." << endl << endl
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
			iniciarFuncion();
			break;
		case 5:
			mostrarEspacios();
			break;
		case 6:
			atenderClienteCola();
			break;
		case 7:
			mostrarTeatro();
			break;
		case 8:
			break;
		case 9:
			breaker = 1;
			std::cout << "Gracias por usar nuestro servicio, lo esperamos pronto." << endl;
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
		enviarACola();
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
		try {
			cout << "\nGraderia preferencial 1" << endl << endl <<
				"Ingrese la fila en la que desea reservar: 1,2,3,4 o 5." << endl;
			cin >> fila;
			cout << "Ingrese su nombre:" << endl;
			cin >> nombre;
			
			Espacio *temp = new Espacio(contGeneral, "Reservado", "Preferencial", 5500, nombre);
			reservarGraderia1(temp, fila, nombre);

		}
		catch (exception e) {
			cout << "Ha ocurrido un error, por favor intentelo de nuevo.";
		}
		break;

	case 2:
		try {
			cout << "\nGraderia preferencial 2" << endl << endl <<
				"Ingrese la fila en la que desea reservar: 1,2,3,4 o 5." << endl;
			cin >> fila;
			cout << "Ingrese su nombre:" << endl;
			cin >> nombre;
			
			Espacio *temp = new Espacio(contGeneral, "Reservado", "Preferencial", 5500, nombre);
			reservarGraderia2(temp, fila, nombre);
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
			enviarACola();
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
			enviarACola();
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
			enviarACola();
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
			enviarACola();
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
			enviarACola();
		}
		break;
	default:
		cout << "Esta fila no existe." << endl;
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
			enviarACola();
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
			enviarACola();
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
			enviarACola();
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
			enviarACola();
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
			enviarACola();
		}
		break;
	default:
		cout << "Esta fila no existe." << endl;
		break;
	}
}

void reservarGeneral() {
	string nombre;
	int num;

	cout << "\n---General---" << endl;
	if (ListaGeneral->GetLong() < 50) {
		cout << "\nDigite el nombre de quien realiza la reserva" << endl;
		cin >> nombre;
		Espacio espacio(contGradGeneral, "Reservado", "General", 4000, nombre);
		num = ListaGeneral->ReservarGradGeneral(espacio);
		contGradGeneral++;
		cout << "\n" << nombre << " ha reservado en el espacio n" << num << "\n" << endl;
	}
	else {
		cout << "\nYa no hay espacios en la zona General" << endl;
		enviarACola();
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
			pagarPreferencial();
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

void pagarPreferencial() {

	int fila = 0;
	int graderia = 0;
	string nombre;

	cout << "" << endl <<
		"Ingrese su nombre:" << endl;
	cin >> nombre;
	cout << "" << endl <<
		"Ingrese la graderia:" << endl;
	cin >> graderia;
	cout << "" << endl <<
		"Ingrese la fila en la que reservo:" << endl;
	cin >> fila;

	try {
		if (graderia == 1) {
			pagarGraderia1(fila, nombre);
		}
		else if (graderia == 2) {
			pagarGraderia2(fila, nombre);
		}
	}
	catch (exception e) {
		cout << "ha sucedido un error, por favor intentelo de nuevo." << endl;
	}

}

void pagarGraderia1(int fila, string nombre) {

	switch (fila) {

	case 1:
		realizarPagoGraderiaEnFila(graderia1_1, graderia1_1Pagado, nombre);
		cout << "Pago realizado" << endl;
		break;
	case 2:
		realizarPagoGraderiaEnFila(graderia1_2, graderia1_2Pagado, nombre);
		cout << "Pago realizado" << endl;
		break;
	case 3:
		realizarPagoGraderiaEnFila(graderia1_3, graderia1_3Pagado, nombre);
		cout << "Pago realizado" << endl;
		break;
	case 4:
		realizarPagoGraderiaEnFila(graderia1_4, graderia1_4Pagado, nombre);
		cout << "Pago realizado" << endl;
		break;
	case 5:
		realizarPagoGraderiaEnFila(graderia1_5, graderia1_5Pagado, nombre);
		cout << "Pago realizado" << endl;
		break;
	default:
		cout << "Opcion invalida." << endl;
		break;
	}
}

void pagarGraderia2(int fila, string nombre) {
	
	switch (fila) {

	case 1:
		graderia2_1Pagado->insertarElem(graderia2_1->RetirarElemTope());
		cout << "Pago realizado" << endl;
		break;
	case 2:
		graderia2_2Pagado->insertarElem(graderia2_2->RetirarElemTope());
		cout << "Pago realizado" << endl;
		break;
	case 3:
		graderia2_3Pagado->insertarElem(graderia2_3->RetirarElemTope());
		cout << "Pago realizado" << endl;
		break;
	case 4:
		graderia2_4Pagado->insertarElem(graderia2_4->RetirarElemTope());
		cout << "Pago realizado" << endl;
		break;
	case 5:
		graderia2_5Pagado->insertarElem(graderia2_5->RetirarElemTope());
		cout << "Pago realizado" << endl;
		break;
	default:
		cout << "Opcion invalida." << endl;
		break;
	}
}

void realizarPagoGraderiaEnFila(Pila *graderia,Pila *graderiaPagado, string nombre) {
	int breaker = 0;
	int contador = 0;
	Espacio temp;
	Pila *pilaTemp = new Pila();

	while (breaker == 0) {
		temp = graderia->RetirarElemTope();

		if (nombre == temp.GetNombre()) {
			temp.SetEstado("Pagado");
			graderiaPagado->insertarElem(temp);
			breaker = 1;
		}
		else {
			pilaTemp->insertarElem(temp);
			
		}

		if (contador >= graderia->getLongitud()) {
			breaker = 1;
		}
		contador++;
	}

	breaker = 0;
	while (breaker == 0) {
		temp = pilaTemp->RetirarElemTope();
		graderia->insertarElem(temp);
		contador = pilaTemp->getLongitud();
		if (pilaTemp->getLongitud()==0) {
			breaker = 1;
		}

	}
	

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
	if (ListaVIP->GetCabeza() != NULL) {
		ListaVIP->LiberarReservas();
		
		reservasLib = true;
		cout << "\nAsientos reservados en VIP han sido liberadas." << endl;
	}
	else {
		cout << "\nNo se han realizado reservaciones VIP." << endl;
	}

	if (graderia1_1->getLongitud() == 0 &&
		graderia1_2->getLongitud() == 0 &&
		graderia1_3->getLongitud() == 0 &&
		graderia1_4->getLongitud() == 0 &&
		graderia1_5->getLongitud() == 0 &&
		graderia2_1->getLongitud() == 0 &&
		graderia2_2->getLongitud() == 0 &&
		graderia2_3->getLongitud() == 0 &&
		graderia2_4->getLongitud() == 0 &&
		graderia2_5->getLongitud() == 0) {

		cout << "\nNo se han realizado reservaciones preferenciales" << endl;
	}
	else {
		liberarReservasPreferencial();
		reservasLib = true;
	}

	if (ListaGeneral->GetCabeza() != NULL) {
		ListaGeneral->LiberarReservas();
		reservasLib = true;
		cout << "\nAsientos reservados en asientos regulares han sido liberadas." << endl;
	}
	else {
		cout << "\nNo se han realizado reservaciones en asientos regulares." << endl;
	}

}

void liberarReservasPreferencial() {

	graderia1_1->liberarReservas();
	graderia1_2->liberarReservas();
	graderia1_3->liberarReservas();
	graderia1_4->liberarReservas();
	graderia1_5->liberarReservas();
	graderia2_1->liberarReservas();
	graderia2_2->liberarReservas();
	graderia2_3->liberarReservas();
	graderia2_4->liberarReservas();
	graderia2_5->liberarReservas();

	cout << "\nAsientos reservados en graderias preferenciales han sido liberadas." << endl;
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

void iniciarFuncion() {
	cout << "\n----Zona VIP----" << endl;
	cout << "\nCantidad de personas en la funcion: " << ListaVIP->GetPagados() << endl;
	cout << "Monto total vendido en la zona: " << ListaVIP->GetMontoTotal() << " colones" << endl;

	cout << "\n----Zona Graderia Preferencial----" << endl;
	cout << "\nCantidad de personas en la funcion: " << conseguirTotalEspaciosPreferencialesPagos() << endl;
	cout << "Monto total vendido en la zona: " << MontoTotalPreferencial() << " colones" << endl;

	cout << "\n----Zona Graderia General----" << endl;
	cout << "\nCantidad de personas en la funcion: " << ListaGeneral->GetPagados() << endl;
	cout << "Monto total vendido en la zona: " << ListaGeneral->GetMontoTotal() << " colones" << endl;

	cout << "\n----Monto total recaudado en la funcion: " << ListaVIP->GetMontoTotal() + ListaGeneral->GetMontoTotal() + MontoTotalPreferencial() << " colones----" << endl;
}

int conseguirTotalEspaciosPreferencialesPagos()
{
	int totalEspaciosPagos = 0;
	totalEspaciosPagos = totalEspaciosPagos+ graderia1_1Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia1_2Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia1_3Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia1_4Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia1_5Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia2_1Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia2_2Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia2_3Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia2_4Pagado->getLongitud();
	totalEspaciosPagos = totalEspaciosPagos + graderia2_5Pagado->getLongitud();
	return totalEspaciosPagos;
}

double MontoTotalPreferencial()
{
	return conseguirTotalEspaciosPreferencialesPagos() * 5500;
}

void enviarACola() {
	int resp;
	string nombre;
	do {
		cout << "\n¿Desea esperar a que se libere una reserva para poder ingresar al teatro?" << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;
		cin >> resp;

		if (resp == 1) {
			cout << "\nDigite el nombre del cliente para ingresarlo a la cola" << endl;
			cin >> nombre;
			colaClientes->insertarCliente(nombre);
		}
		else if (resp == 2) {
			cout << "Gracias por preferirnos" << endl;
		}
		else {
			cout << "Opcion incorrecta" << endl;
		}
	} while (resp < 1 || resp > 2);
}

void atenderClienteCola() {
	string nombre;

	if (reservasLib == true) {
		nombre = colaClientes->atender();
		if (nombre != "") {
			cout << "\nSe atiende a " << nombre << endl;
			int opc;
			cout << "Seleccione la zona a la que desea ingresar" << endl;
			cout << "1. VIP" << endl;
			cout << "2. Preferencial" << endl;
			cout << "3. General" << endl;
			cin >> opc;
			do {
				switch (opc)
				{
				case 1:
					ingresarVIP(nombre);
					break;
				case 2:
					ingresarPreferencialDesdeCola(nombre);
					break;
				case 3:
					ingresarGeneral(nombre);
					break;
				default:
					cout << "\nOpcion incorrecta" << endl;
					break;
				}
			} while (opc < 1 || opc > 3);
		}
	}
	else {
		cout << "Aun no se liberan reserevaciones" << endl;
	}
}

void ingresarVIP(string nombre) {
	int num;
	bool realizado = false;

	if (ListaVIP->GetPagados() < 10) {
		do {
			cout << "\nDigite el numero del espacio al que desea ingresar" << endl;
			cin >> num;

			if (num > 10 || num < 1) {
				cout << "\nPor favor ingrese un numero del 1 al 10" << endl;
			}
			else {
				realizado = ListaVIP->IngresarVIP(num, nombre);
			}

			if (realizado == false) {
				cout << "\nEl numero de espacio ingresado ya se encuentra ocupado, por favor ingrese otro" << endl;
			}

		} while (realizado == false || num > 10 || num < 1);
	}
	else {
		cout << "\nLo sentimos los espacios de esta zona ya estan llenos" << endl;
	}
}

void ingresarGeneral(string nombre) {
	
	bool realizado = false;

	if (ListaGeneral->GetPagados() < 50) {
		realizado = ListaGeneral->IngresarGeneral(nombre);
		cout << "\nPago efectuado" << endl;
	}
	else {
		cout << "\nLo sentimos los espacios de esta zona ya estan llenos" << endl;
	}
}

void ingresarPreferencialDesdeCola(string nombre) {

	int graderia = 0;
	int fila = 0;

	cout << "Ingrese la graderia:" << endl << "1. Graderia derecha." << "2. Graderia izquierda.";
	cin >> graderia;
	cout << "Ingrese la fila: 1,2,3,4 o 5." << endl;
	cin >> fila;

	if (graderia == 1) {
		if (fila == 1 || fila == 2 || fila == 3 || fila == 4|| fila == 5) {
			ingresarGraderia1PagoDesdeCola(nombre, fila);
		}
		else {
			cout << "Fila no valida." << endl;
		}
	}
	else if (graderia == 2) {
		if (fila == 1 || fila == 2 || fila == 3 || fila == 4 || fila == 5) {
			ingresarGraderia2PagoDesdeCola(nombre, fila);
		}
		else {
			cout << "Fila no valida." << endl;
		}
	}
	else {
		cout << "Graderia no valida." << endl;
	}

}

void ingresarGraderia1PagoDesdeCola(string nombre, int fila) {
	Espacio espacioTemp;
	espacioTemp.SetEstado("Pagado");
	espacioTemp.SetCosto(5500);
	espacioTemp.SetNombre(nombre);
	espacioTemp.SetTipo("Preferencial");
	switch (fila) {
	case 1:
		if (graderia1_1Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia1_1Pagado->getLongitud() + 1);
			graderia1_1Pagado->insertarElem(espacioTemp);
		}
		break;
	case 2:
		if (graderia1_2Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia1_2Pagado->getLongitud() + 1);
			graderia1_2Pagado->insertarElem(espacioTemp);
		}
		break;
	case 3:
		if (graderia1_3Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia1_3Pagado->getLongitud() + 1);
			graderia1_3Pagado->insertarElem(espacioTemp);
		}
		break;
	case 4:
		if (graderia1_4Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia1_4Pagado->getLongitud() + 1);
			graderia1_4Pagado->insertarElem(espacioTemp);
		}
		break;
	case 5:
		if (graderia1_5Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia1_5Pagado->getLongitud() + 1);
			graderia1_5Pagado->insertarElem(espacioTemp);
		}
		break;
	}
}


void ingresarGraderia2PagoDesdeCola(string nombre, int fila) {
	Espacio espacioTemp;
	espacioTemp.SetEstado("Pagado");
	espacioTemp.SetCosto(5500);
	espacioTemp.SetNombre(nombre);
	espacioTemp.SetTipo("Preferencial");
	switch (fila) {
	case 1:
		if (graderia2_1Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia2_1Pagado->getLongitud() + 1);
			graderia2_1Pagado->insertarElem(espacioTemp);
		}
		break;
	case 2:
		if (graderia2_2Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia2_2Pagado->getLongitud() + 1);
			graderia2_2Pagado->insertarElem(espacioTemp);
		}
		break;
	case 3:
		if (graderia2_3Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia2_3Pagado->getLongitud() + 1);
			graderia2_3Pagado->insertarElem(espacioTemp);
		}
		break;
	case 4:
		if (graderia2_4Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia2_4Pagado->getLongitud() + 1);
			graderia2_4Pagado->insertarElem(espacioTemp);
		}
		break;
	case 5:
		if (graderia2_5Pagado->getLongitud() == 5) {
			cout << "Esta fila esta llena." << endl;
		}
		else {
			espacioTemp.SetNumEspacio(graderia2_5Pagado->getLongitud() + 1);
			graderia2_5Pagado->insertarElem(espacioTemp);
		}
		break;
	}
}
void mostrarTeatro() {

	cout << endl <<
		   "              ============================================" << endl <<
		   "             |                                            |" << endl <<
		   "             |                                            |"<< endl <<
		   "             |                  Escenario                 |" <<
		   "             |                                            |" << endl <<
		   "             |                                            |" << endl <<
		   "             |                                            |" << endl << 
		   "              ============================================" << endl << endl <<
		   " _____________________________________________________________________________" << endl << endl;


	imprimirVIP();
	imprimirPreferenciales();
	imprimirRegulares();
	cout << endl << " _____________________________________________________________________________" << endl;

}

void imprimirVIP() {

}

void imprimirPreferenciales() {
	
	Pila *pilaTemp = new Pila();

	cout << "                        ";
	imprimirFila(graderia1_1, graderia1_1Pagado);
	cout << "  |  ";
	imprimirFila(graderia2_1, graderia2_1Pagado);
	cout << endl << "                        ";
	imprimirFila(graderia1_2, graderia1_2Pagado);
	cout << "  |  ";
	imprimirFila(graderia2_2, graderia2_2Pagado);
	cout << endl << "                        ";
	imprimirFila(graderia1_3, graderia1_3Pagado);
	cout << "  |  ";
	imprimirFila(graderia2_3, graderia2_3Pagado);
	cout << endl << "                        ";
	imprimirFila(graderia1_4, graderia1_4Pagado);
	cout << "  |  ";
	imprimirFila(graderia2_4, graderia2_4Pagado);
	cout << endl << "                        ";
	imprimirFila(graderia1_5, graderia1_5Pagado);
	cout << "  |  ";
	imprimirFila(graderia2_5, graderia2_5Pagado);
	cout << endl << "                        ";


}

void imprimirFila(Pila *fila, Pila *filaPago) {
	int suma = fila->getLongitud() + filaPago->getLongitud();
	int cantidad = 0;
	int diferencia = 0;
	Pila *temp = new Pila();
	Espacio asiento;
	//imprimir los asientos pagos.
	for (int i = 0; i < filaPago->getLongitud();i++) {
		asiento = filaPago->RetirarElemTope();
		imprimirTipoEstado(asiento.GetEstado());
		temp->insertarElem(asiento);
	}
	
	for (int a = 0; a < temp->getLongitud();a++) {
		asiento = temp->RetirarElemTope();
		filaPago->insertarElem(asiento);
	}
	//imprimir los asientos reservador.
	for (int i = 0; i < fila->getLongitud(); i++) {
		asiento = fila->RetirarElemTope();
		imprimirTipoEstado(asiento.GetEstado());
		temp->insertarElem(asiento);
	}

	for (int a = 0; a < temp->getLongitud(); a++) {
		asiento = temp->RetirarElemTope();
		fila->insertarElem(asiento);
	}
	//En caso de que el resto de los asientos sean vacios se imprime la diferencia.
	cantidad = fila->getLongitud() + filaPago->getLongitud();
	diferencia = 5 - cantidad;
	for (int e = 0; e < diferencia;e++) {
		imprimirTipoEstado("Libre");
	}
}


void imprimirTipoEstado(string estado) {

	if (estado == "Pagado") {
		cout << "P ";
	}
	else if (estado == "Reservado") {
		cout << "R ";
	}
	else {
		cout << "L ";
	}

}

void imprimirRegulares() {


}