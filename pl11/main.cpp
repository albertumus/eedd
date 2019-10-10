#include <stdio.h>
#include <Cola.hpp>
#include <Box.hpp>

void cambiarCola(Pasajero *p, Cola *c1, Cola *c2);
void serAtendido(Box *box, Pasajero *pp);

int main(int argc, char **argv)
{
	Cola colaInicial;
	Cola* pColaInicial = &colaInicial;
    
	Cola colaListos;
	Cola* pColaListos = &colaListos;

	Cola colaFinal;
	Cola* pColaFinal = &colaFinal;
	
	Box box1 = Box(1);
	Box* pBox1 = &box1;
	
	Box box2 = Box(2);
	Box* pBox2 = &box2;
	
	Box box3 = Box(3);
	Box* pBox3 = &box3;
	
	int t = 0;
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
	Pasajero* pasajero6 = new Pasajero(6,2,18,14);
	colaInicial.insertar(pasajero6);
	Pasajero* pasajero7 = new Pasajero(7,6,9,16);
	colaInicial.insertar(pasajero7);
	Pasajero* pasajero8 = new Pasajero(8,7,14,31);
	colaInicial.insertar(pasajero8);
	Pasajero* pasajero9 = new Pasajero(9,4,11,23);
	colaInicial.insertar(pasajero9);
	
	/*
	while ( pColaInicial->longitudCola() > 0 ) 
	{
		pColaInicial->eliminar();
		
	}
	 */

	cout << endl;

	return 0;
}

void cambiarCola(Pasajero *p, Cola *colaOrigen, Cola *colaDestino)
/*
 * Mueve a una persoan de una cola de inicio a otra final 
 */ 
{
	colaOrigen->borrarDeCola(p, colaOrigen);
	colaDestino->insertar(p);
}

void serAtendido(Box *box, Pasajero *pp)
/*
 * Mete a una pasajero en un box
 */ 
{
	box->setOcupado(pp);
}

