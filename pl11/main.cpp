#include <stdio.h>
#include <Cola.hpp>
#include <Box.hpp>

int buscarPrioridad 
void cambiarCola(Pasajero *p, Cola *c1, Cola *c2);


int main(int argc, char **argv)
{
	Cola colaInicial;
	Cola* pColaInicial = &colaInicial;
    
	
	Cola colaListos;
	Cola* pColaListos = &colaListos;

	Cola colaFinal;
	Cola* pColaFinal = &colaFinal;
	
	int t = 0;
	int* pt = &t;
	int prioridad = 0;
	int* pPrioridad = &prioridad;
	
	Pasajero* pasajero1 = new Pasajero(1,1,1,1);
	colaInicial.insertar(pasajero1);
	Pasajero* pasajero2 = new Pasajero(2,1,1,1);
	colaInicial.insertar(pasajero2);
	Pasajero* pasajero3 = new Pasajero(3,1,1,1);
	colaInicial.insertar(pasajero3);
	Pasajero* pasajero4 = new Pasajero(4,1,1,1);
	colaInicial.insertar(pasajero4);
	Pasajero* pasajero5 = new Pasajero(5,1,1,1);
	colaInicial.insertar(pasajero5);
	Pasajero* pasajero6 = new Pasajero(6,1,1,1);
	colaInicial.insertar(pasajero6);
	Pasajero* pasajero7 = new Pasajero(7,1,1,1);
	colaInicial.insertar(pasajero7);
	Pasajero* pasajero8 = new Pasajero(8,1,1,1);
	colaInicial.insertar(pasajero8);
	Pasajero* pasajero9 = new Pasajero(9,1,1,1);
	colaInicial.insertar(pasajero9);
	
	cout << t << endl;
	
	while ( pColaInicial->longitudCola() > 0 ) 
	{
		pColaInicial->mostrar();
		pColaInicial->eliminar();
		
	}
		
	cout << endl;
	return 0;
}

void cambiarCola(Pasajero *p, Cola *colaOrigen, Cola *colaDestino)
/*
 * 
 */ 
{
	// Falta elinar de la cola de origin
	colaDestino->insertar(p);
}

