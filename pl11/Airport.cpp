#include "Airport.hpp"
#include <algorithm>
#include <conio.h>

Airport::Airport()
{
	t = 0; 
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
	
	
	Box* nuevo_box = new Box(5);
	nuevo_box->setPasajeroEnColaBox(pasajero1);
	listaBoxes.insertarDerch(nuevo_box);
	Box* nuevo_box2 = new Box(6);
	nuevo_box2->setPasajeroEnColaBox(pasajero2);
	listaBoxes.insertarIzq(nuevo_box2);
	listaBoxes.mostrar();
	
	cout << "Hay box vacio? : " << listaBoxes.hayBoxVacio();
	
	
	int a;
	cin >> a;


}

Airport::~Airport()
{
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

