#include <stdio.h>
#include <Cola.hpp>
#include <Box.hpp>

void cambiarCola(Pasajero *p, Cola *c1, Cola *c2);
void colaDeLista(int t, Cola *colaOrigen, Cola *colaDestino);


int main(int argc, char **argv)
{
	Cola colaInicial;
	Cola* pColaInicial = &colaInicial;
    
	
	Cola colaListos;
	Cola* pColaListos = &colaListos;

	Cola colaFinal;
	Cola* pColaFinal = &colaFinal;
	
	int t = 21;
	int* pt = &t;
	int prioridad = 0;
	int* pPrioridad = &prioridad;
	
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
	Pasajero* pasajero6 = new Pasajero(6,2,8,14);
	colaInicial.insertar(pasajero6);
	Pasajero* pasajero7 = new Pasajero(7,6,9,16);
	colaInicial.insertar(pasajero7);
	Pasajero* pasajero8 = new Pasajero(8,7,14,31);
	colaInicial.insertar(pasajero8);
	Pasajero* pasajero9 = new Pasajero(9,4,21,23);
	colaInicial.insertar(pasajero9);
	
	
//	while ( pColaInicial->longitudCola() > 0 ) 
//	{
//		cout << endl;
//		pColaInicial->buscarPrioridad();
//		cout << endl;
//		pColaInicial->eliminar();
//		
//	}
//	cambiarCola(pasajero1, pColaInicial, pColaListos);
//	pColaInicial->mostrar();
//	pColaListos->mostrar();
	colaDeLista(t, pColaInicial, pColaListos);
	//cout << "Después de ejecutar el método..." << endl;
	pColaInicial->mostrar();
	pColaListos->mostrar();


	cout << endl;
	
//	pColaInicial->buscarPersonaLlegada(pt, pColaInicial);
	

	return 0;
}

void cambiarCola(Pasajero *p, Cola *colaOrigen, Cola *colaDestino)
/*
 * 
 */ 
{
	colaOrigen->borrarDeCola(p, colaOrigen);
	colaDestino->insertar(p);
//	colaOrigen->mostrar();
//	colaDestino->mostrar();
}

void colaDeLista(int t, Cola *colaOrigen, Cola *colaDestino)
/*
 * Mueve a Cola de Listos todas las personas que hayan llegado al aeropuerto en el time que estemos de la cola Inicial
 */ 
{	
	Pasajero* pasajeroLlegada = colaOrigen->buscarPersonaLlegada(t);
	
	while (pasajeroLlegada->getIdentificador() != 0){
		
		cambiarCola(pasajeroLlegada, colaOrigen, colaDestino);
		pasajeroLlegada = colaOrigen->buscarPersonaLlegada(t);
	}
}