#include "Airport.hpp"
#include <algorithm>
#include <conio.h>

Airport::Airport()
{
	t = 0; 
	prioridad = 0;
}

void Airport::gestionarAeropuerto()
{
	
	Cola* pColaInicial = &colaInicial;
	Cola* pColaListos = &colaListos;
	Cola* pColaFinal = &colaFinal;
	
	Box* pBox1 = &box1;
	Box* pBox2 = &box2;
	Box* pBox3 = &box3;
	
	int* pt = &t;
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
	


	while ( colaInicial.longitudCola() != 0 || colaListos.longitudCola() != 0  || box1.getOcupado() || box2.getOcupado() || box3.getOcupado()  )
	{
		cout << endl;
		cout << "Pulsa para realizar iteracion: ";
		//getch();
		
		cout << endl << "Tiempo actual del aeropuerto: " << t << endl;
		cout << endl;
		cout << "#### Estado Inicial de las colas antes de iteracion ###" << endl;
		cout << endl;
		mostrarColas();
		
		if ( colaInicial.longitudCola() != 0 )
		{
			colaDeLista();
		}
		
		if ( colaListos.longitudCola() != 0  )
		{
			prioridad = colaListos.buscarPrioridad();
		}
		
		
		while ( colaListos.longitudCola() > 0 && boxLibre() ) 
		{
		serAtendido(cogerboxLibre(pBox1, pBox2, pBox3), colaListos.cogerPrimeroPrioridad( prioridad )); 
		prioridad = pColaListos->buscarPrioridad();
		}
		
		mostrarEstadoBoxes();
	
		if ( !boxLibre() )
		{
			cout << endl << "Accion realizada: No quedan boxes libre y he vaciado uno" << endl;
			comprobarBoxFinalizado();
			
		} else if ( pColaInicial->longitudCola() != 0 && pColaListos->longitudCola() == 0 )
		{
			cout << endl << "Accion realizada: Quedaban boxes libres y he movido el tiempo actual hasta donde llege alguien" << endl;
			t = pColaInicial->buscarPrimerTiempoLlegada();
		} else {
			cout << endl << "Accion realizada: Solo quedan vaciar boxes" << endl;
			comprobarBoxFinalizado();
		}
		cout << endl;
		cout << "#### Estado Final de las cola despues de iteracion ###" << endl;
		mostrarColas();
		cout << endl <<"#### Tiempo del aeropuerto en el que finaliza esta iteracion: " << t << " "<<endl;
		
		cout << endl;
		cout << "############################### Terminada Iteracion ###############################" << endl;
		cout << endl;

	}
	
	float tiempoFinalAeropuerto = calcularTiempoMedioAeropuerto();
	cout << endl << "EL TIEMPO FINAL DEL AEROPUERTO: " << tiempoFinalAeropuerto  << endl;
	cout << "###################################################" << endl;
	int a;
	cin >> a;

	cout << endl << "### Practica Arboles ###" << endl;
	cout << "Orden de la cola de gente finalizada " << endl;
	colaFinal.setearSatisfaccion(tiempoFinalAeropuerto );
	colaFinal.mostrar();
	cout << endl << "###################################################" << endl;
	

	Pasajero* pasajero_nulo = new Pasajero(0,0,0,0);
	pasajero_nulo->setSatisfaccion(0);
	ArbolBusqueda* arbol_principal = new ArbolBusqueda(pasajero_nulo);
	colaFinal.insertarEnArbol(arbol_principal);
	cout << endl;
	arbol_principal->verArbol(4);
	
	// Ejercicio 1 - Media
	cout << endl << "###################################################" << endl;
	cout << "La satisfaccion media de los pasajeros es " << arbol_principal->calcularSatisfaccionMedia();
	cout << endl << "###################################################" << endl;
	
	// Ejercicio 2 - Minimo
	cout << endl << "###################################################" << endl;
	cout << "El pasajero minimo es ";
	arbol_principal->satisfaccionMinima()->mostrarPasajero();
	cout << endl << "###################################################" << endl;
	
	// Ejercicio 2 - Maximo
	cout << endl << "###################################################" << endl;
	cout << "El pasajero maximo es ";
	arbol_principal->satisfaccionMaxima()->mostrarPasajero();
	cout << endl << "###################################################" << endl;
	
	// Ejercicio 3 - max media de menor a mayor
	cout << endl << "###################################################" << endl;
	cout << "Los pasajeros con un nivel de satisfaccion mayor que la media son ";
	cout << endl << endl;
	arbol_principal->getDer()->verArbol(10);
	cout << endl;
	arbol_principal->getDer()->inOrden();
	cout << endl << "###################################################" << endl;
	
	// Ejercicio 4 - datos pasajero negativo en preorden
	cout << endl << "###################################################" << endl;
	cout << "Los pasajeros con una satisfaccion negativa en preorden son";
	cout << endl << endl;
	arbol_principal->getIzq()->verArbol(10);
	cout << endl;
	arbol_principal->getIzq()->preOrden();
	cout << endl << "###################################################" << endl;

	// Ejercicio 5 - datos de pasajero en orden
	cout << endl << "###################################################" << endl;
	cout << "Los pasajeros de menor a mayor ";
	cout << endl << endl;
	arbol_principal->verArbol(10);
	cout << endl;
	arbol_principal->inOrden();
	cout << endl << "###################################################" << endl;

	int b;
	cin >> b;

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

void Airport::serAtendido(Box *box, Pasajero *pp )
/*
 * Mete a una pasajero en un box
 */ 
{
	
	box->setPasajeroEnBox(pp);
	pp->setHoraAtendido(t);
	colaListos.borrarDeCola(pp);
}

void Airport::comprobarBoxFinalizado()
/*
 * Funcion que comprueba cual es el box que anes se queda vacio, lo vacia y setea el tiempo
 * a dicho momeneot. Tambien setea el momento de salida de la persona del box en dicho momento.
 */ 
{

	
	int a = box1.getOcupado() ?  box1.getValor()->calcularHoraSalida() : 10000 ;
	int b = box2.getOcupado() ?  box2.getValor()->calcularHoraSalida() : 10000 ;
	int c = box3.getOcupado() ?  box3.getValor()->calcularHoraSalida() : 10000 ;
	
	int momentoMasCercanoDeSalida =  min( a, min( b, c));
	t = momentoMasCercanoDeSalida;
	
	if (box1.getOcupado() && box1.getValor()->calcularHoraSalida() == t )
	{
		colaFinal.insertarPorId( box1.getValor() );
		box1.vaciarBox();
	}
	
	if (box2.getOcupado() && box2.getValor()->calcularHoraSalida() == t )
	{
		colaFinal.insertarPorId( box2.getValor() );
		box2.vaciarBox();
	}
	
	if ( box3.getOcupado() && box3.getValor()->calcularHoraSalida() == t )
	{
		colaFinal.insertarPorId( box3.getValor() );
		box3.vaciarBox();
	}

}

bool Airport::boxLibre()
/*
 * Devuelve true o false en función de si un algún box está vacío o no
 */ 
{
	return !box1.getOcupado() || !box2.getOcupado() || !box3.getOcupado();
}

Box* Airport::cogerboxLibre(Box *box1, Box *box2, Box *box3)
/*
 * Devuelve un box libre, para usar esta función, aconsejable comprobar siempre antes si hay boxLibre,
 * ya que si no devuelve un NULL y habría que tener en cuenta este retorno
 */ 
{
	return (boxLibre() ? (!box1->getOcupado() ? box1 : ((!box2->getOcupado()) ? box2 : box3)) : NULL);
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

void Airport::mostrarEstadoBoxes()
/*
 * Muestra pasajeros en los boxes
 */ 
{
		cout << "#### Estado de los boxes ###" << endl;
		if ( box1.getOcupado() )
		{
			cout << "El pasajero " << box1.getValor()->getIdentificador() << " esta en el box y sale en: " << box1.getValor()->calcularHoraSalida() << endl;
		}
		
		if ( box2.getOcupado() )
		{
			cout << "El pasajero " << box2.getValor()->getIdentificador() << " esta en el box y sale en: " << box2.getValor()->calcularHoraSalida() << endl;
		}
		
		if ( box3.getOcupado() )
		{
			cout << "El pasajero " << box3.getValor()->getIdentificador() << " esta en el box y sale en: " << box3.getValor()->calcularHoraSalida() << endl;
		}
		cout << "#### ######### ###" << endl;
}

void Airport::mostrarColas()
/*
 * Muestra los componentes de las 3 colas
 */ 
{
		cout << "Cola Inicial: ";
		colaInicial.mostrar();
		cout << endl;
		cout << "Cola Listos: ";
		colaListos.mostrar();
		cout << endl;
		cout << "Cola Final: ";
		colaFinal.mostrar();
		cout << endl;
}