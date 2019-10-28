#include "Airport.hpp"
#include <algorithm>
#include <conio.h>

Airport::Airport()
{
	t = 35; 
	numeroBoxes = 0;
}

void Airport::gestionarAeropuerto()
{
	
	Cola* pColaInicial = &colaInicial;
	Cola* pColaFinal = &colaFinal;
	
	int* pt = &t;

	Pasajero* pasajero1 = new Pasajero(1,6,0,20);
	colaInicial.insertar(pasajero1);
	Pasajero* pasajero2 = new Pasajero(2,7,5,39);
	colaInicial.insertar(pasajero2);
	Pasajero* pasajero3 = new Pasajero(3,1,0,15);
	colaInicial.insertar(pasajero3);
	Pasajero* pasajero4 = new Pasajero(4,5,7,23);
	colaInicial.insertar(pasajero4);
	Pasajero* pasajero5 = new Pasajero(5,3,21,20);
	colaInicial.insertar(pasajero5);
	Pasajero* pasajero6 = new Pasajero(6,2,18,14);
	colaInicial.insertar(pasajero6);
	Pasajero* pasajero7 = new Pasajero(7,6,9,16);
	colaInicial.insertar(pasajero7);
	Pasajero* pasajero8 = new Pasajero(8,7,14,31);
	colaInicial.insertar(pasajero8);
	Pasajero* pasajero9 = new Pasajero(9,4,11,23);
	colaInicial.insertar(pasajero9);
	
	
	
	crearNuevoBox();
	// Se mete al primer pasajero
	pasajero1->setAtendido();
	pasajero1->setHoraAtendido(0);
	listaBoxes.getPrimero()->setPasajeroEnColaBox(pasajero1);
	// Se meten mas pasajeros
	listaBoxes.getPrimero()->setPasajeroEnColaBox(pasajero2);
	listaBoxes.getPrimero()->setPasajeroEnColaBox(pasajero4);
	listaBoxes.getPrimero()->setPasajeroEnColaBox(pasajero3);
	cout << endl << "la longitud inicial es " << listaBoxes.getPrimero()->getValor()->longitudCola() << endl;
	finalizarBoxes();
	cout << endl << "despues, la longitud final es " << listaBoxes.getPrimero()->getValor()->longitudCola();
	cout << endl << "la cola final es ";
	colaFinal.mostrar();
	cout << "el tiempo medio de atencion es " << calcularTiempoMedioAeropuerto();
	
	
	
	int a;
	cin >> a;


}

void Airport::crearNuevoBox()
{
	Box* nuevo_box = new Box(numeroBoxes+1);
	listaBoxes.insertarDerch(nuevo_box);
	numeroBoxes = numeroBoxes+1;
}

void Airport::cambiarCola(Pasajero *p, Cola& colaOrigen, Cola& colaDestino)
{
  int lenColaOrigen = colaOrigen.longitudCola();
   
  for ( int i=0; i<lenColaOrigen; i++ )
  {
    if ( colaOrigen.getPrimero()->getIdentificador() != p->getIdentificador() )
    {
      colaOrigen.insertar(colaOrigen.getPrimero());
    }

    colaOrigen.eliminar();
  }
  
  colaDestino.insertar(p);
}

void Airport::finalizarBoxes()
{
	lnodo aux = listaBoxes.getPrimerNodo();
	
	for ( int i = 0; i<listaBoxes.getLongitud();i++)
	{
		if ( aux->valor->getValor()->longitudCola() > 0 )
		{
			while ( aux->valor->getValor()->longitudCola() > 0 )
			{
				int horaSalidaLocal = aux->valor->getValor()->getPrimero()->calcularHoraSalida();
				cambiarCola(aux->valor->getValor()->getPrimero(), *aux->valor->getValor(), colaFinal);
				if ( aux->valor->getValor()->longitudCola() > 0 )
				{
					aux->valor->getValor()->getPrimero()->setHoraAtendido(horaSalidaLocal);
					aux->valor->getValor()->getPrimero()->setAtendido();
				}
			}
		} else
		{
			cout << "No hay gente en el box " << aux->valor->getIdentificador() << endl;
		}
		aux = aux->siguiente;
	}
}

void Airport::vaciarBoxes()
{
	lnodo aux = listaBoxes.getPrimerNodo();
	
	for ( int i = 0; i<listaBoxes.getLongitud();i++)
	{
		if ( aux->valor->getValor()->longitudCola() > 0 )
		{
			while ( aux->valor->getValor()->longitudCola() > 0 && aux->valor->getValor()->getPrimero()->estaSiendoAtendido() &&  aux->valor->getValor()->getPrimero()->calcularHoraSalida() <= t )
			{
				int horaSalidaLocal = aux->valor->getValor()->getPrimero()->calcularHoraSalida();
				cambiarCola(aux->valor->getValor()->getPrimero(), *aux->valor->getValor(), colaFinal);
				if ( aux->valor->getValor()->longitudCola() > 0 )
				{
					aux->valor->getValor()->getPrimero()->setHoraAtendido(horaSalidaLocal);
					aux->valor->getValor()->getPrimero()->setAtendido();
				}
			}
		} else
		{
			cout << "No hay gente en el box " << aux->valor->getIdentificador() << endl;
		}
		aux = aux->siguiente;
	}
}

float Airport::calcularTiempoMedioAeropuerto()
/*
 * Calcula el tiempo medio de estancia en el aeropuerto
 */ 
{
	float k = colaFinal.calcularTiempoTotalEnAeropuero();
	float l = colaFinal.longitudCola();
	float resp = k / l;
	return resp;
}

Airport::~Airport()
{
}




