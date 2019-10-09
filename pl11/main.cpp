#include <stdio.h>
#include <Cola.hpp>
#include <Box.hpp>

int main(int argc, char **argv)
{
    Cola colaInicial;
	Cola colaListos;
	Cola colaFinal;
	
	int *t = 0;
	cout << t << endl;

	Pasajero* pasajero1 = new Pasajero(1,1,1,1);
	Pasajero* pasajero2 = new Pasajero(2,1,1,1);
	Pasajero* pasajero3 = new Pasajero(3,1,1,1);
	Pasajero* pasajero4 = new Pasajero(4,1,1,1);
	Pasajero* pasajero5 = new Pasajero(5,1,1,1);
	Pasajero* pasajero6 = new Pasajero(6,1,1,1);
	Pasajero* pasajero7 = new Pasajero(7,1,1,1);
	Pasajero* pasajero8 = new Pasajero(8,1,1,1);
	Pasajero* pasajero9 = new Pasajero(9,1,1,1);
	
	cout << pasajero1->getHoraLlegada() << endl;

	colaFinal.insertar(pasajero1);
	colaFinal.mostrar();

	printf("hello world\n");
	return 0;
}
