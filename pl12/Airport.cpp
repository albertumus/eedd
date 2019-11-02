#include "Airport.hpp"
#include <algorithm>
#include <conio.h>

Airport::Airport()
{
	t = 0; 
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
	t = colaInicial.buscarPrimerTiempoLlegada();
	
	
	while ( colaInicial.longitudCola() > 0 )
	{
		cout << endl;
		cout << "Pulsa para realizar iteracion: ";
		getch();
		cout << endl << "Momento en el que esta el aeropuerto " << t << endl;
		colaDeLista();
		cout << "### Gente que no ha llegado al aeropuerto ###" << endl;
		colaInicial.mostrar();
		cout << "### Gente lista para ser atendida ###" << endl;
		colaListos.mostrar();
		cout << "### Estado de los boxes ###" << endl;
		listaBoxes.mostrar();
		cout << endl;
		
		int h = colaListos.longitudCola();
		for ( int i = 0; i<h; i++ )
		{
			Pasajero* aux_pasajero = colaListos.cogerPrimeroPrioridadYTiempoLlegada(); 
			cout << "el pasajero a cambiar es " << aux_pasajero->getIdentificador() << endl;
			Box* box_aux = listaBoxes.getBoxMenosGente();
			if ( box_aux->getValor()->longitudCola() > 2 ) {
				crearNuevoBox();
				box_aux = listaBoxes.getBoxMenosGente();
				aux_pasajero->setHoraAtendido(aux_pasajero->getHoraLlegada());
			} else if ( box_aux->getValor()->longitudCola() == 0 )
			{
				aux_pasajero->setHoraAtendido(aux_pasajero->getHoraLlegada());
			}
			cout << "el box con menos gente es el " << box_aux->getIdentificador() << endl;
			box_aux->getValor()->insertarPorPrioridad(aux_pasajero);
			colaListos.borrarDeCola(aux_pasajero);
		}
		
		if (  colaInicial.longitudCola() > 0 ) {
			t = colaInicial.buscarPrimerTiempoLlegada();
			cout << endl << "La hora siguiente de llegada de un pasajero es " << t << "vaciamos los boxes en orden hasta dicha hora "<< endl;
		}
		
		vaciarBoxes();
		listaBoxes.borrarBoxesVacios();
		
		cout << endl << "### Estado final de los boxes en el minuto " << t << " ### " << endl;
		listaBoxes.mostrar();
		cout << endl << "##########################" << endl;
		cout << endl << "### Estado cola listos de gente por atender " << t << " ### " << endl;
		colaListos.mostrar();
		cout << endl << "##########################" << endl;
		cout << endl << "### Estado cola final de gente atendida en " << t << " ### " << endl;
		colaFinal.mostrar();
		cout << endl << "##########################" << endl;
		
	}
	cout << endl << " ### NO QUEDA NADIE POR LLEGAR. VAMOS A VACIAR LOS BOXES ###" << endl;
	colaInicial.mostrar();
	finalizarBoxes();
	cout << endl << " Estado despues de vaciar los boxes ( deberian de estar vacios ): " << endl;
	listaBoxes.mostrar();
	cout << endl << " Estado despues de borrar los boxes vacios sobrantes ( solo deberia de haber 1 ): " << endl;
	listaBoxes.borrarBoxesVacios();
	cout << endl << " Mostrados la cola final para ver los pasajeros ###" << endl;
	colaFinal.mostrar();
	cout << endl << " Tiempo medio de espera de atencion del aeropuerto " << calcularTiempoMedioAeropuerto();
	
	
	
	int a;
	cin >> a;


}

void Airport::colaDeLista()
/*
 * Mueve a Cola de Listos todas las personas que hayan llegado al aeropuerto en el time que estemos de la cola Inicial
 */ 
{	
	Pasajero* pasajeroLlegada = colaInicial.buscarPersonaLlegada(t);
	while (pasajeroLlegada->getIdentificador() != 0){
		cambiarCola(pasajeroLlegada, colaInicial, colaListos);
		pasajeroLlegada =colaInicial.buscarPersonaLlegada(t);
	}
	
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
		Pasajero* aux_p = colaOrigen.getPrimero();
		colaOrigen.eliminar();
		
		if ( aux_p->getIdentificador() != p->getIdentificador() )
		{
			colaOrigen.insertar(aux_p);
		}
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
			while ( aux->valor->getValor()->longitudCola() > 0 &&  aux->valor->getValor()->getPrimero()->calcularHoraSalida() <= t )
			{
				int horaSalidaLocal = aux->valor->getValor()->getPrimero()->calcularHoraSalida();
				cambiarCola(aux->valor->getValor()->getPrimero(), *aux->valor->getValor(), colaFinal);
				if ( aux->valor->getValor()->longitudCola() > 0 )
				{
					aux->valor->getValor()->getPrimero()->setHoraAtendido(horaSalidaLocal);
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




