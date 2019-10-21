#include "Airport.hpp"
#include "Cola.hpp"
#include "Box.hpp"
#include <algorithm>
#include <conio.h>

void cambiarCola(Pasajero *p, Cola& colaOrigen, Cola *pcolaDestino);
void colaDeLista(int t, Cola *pColaOrigen,Cola &colaOrigen ,Cola *pColaDestino);
void serAtendido(Box *box, Pasajero *pp, Cola &colaListos, int t);
void comprobarBoxFinalizado( Box *box1, Box *box2, Box *box3, int &t, Cola *colaFinal);
void colaDeLista(int *t, Cola *colaOrigen, Cola *colaDestino );
bool boxLibre(Box box1, Box box2, Box box3);
Box* cogerboxLibre(Box *box1, Box *box2, Box *box3);
float calcularTiempoMedioAeropuerto(Cola colaFinalizados);

Airport::Airport()
{
}

void Airport::gestionarAeropuerto()
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
	


	while ( pColaInicial->longitudCola() != 0 || pColaListos->longitudCola() != 0  || box1.getOcupado() || box2.getOcupado() || box3.getOcupado()  )
	{
		cout << endl;
		cout << "Pulsa para realizar iteracion: ";
		getch();
		
		cout << endl << "Tiempo actual de la iteracion: " << t << endl;
		cout << endl;
		cout << "#### Estado Inicial de las colas antes de iteracion ###" << endl;
		cout << "Cola Inicial: ";
		pColaInicial->mostrar();
		cout << endl;
		cout << "Cola Listos: ";
		pColaListos->mostrar();
		cout << endl;
		cout << "Cola Final: ";
		pColaFinal->mostrar();
		cout << endl;
		cout << endl;
		
		if ( pColaInicial->longitudCola() != 0 )
		{
			colaDeLista(t, pColaInicial, colaInicial, pColaListos); // bien
		}
		
		if ( pColaListos->longitudCola() != 0  )
		{
			prioridad = pColaListos->buscarPrioridad(); // bien
		}
		
		
		while ( pColaListos->longitudCola() > 0 && boxLibre(box1, box2, box3) ) 
		{
		serAtendido(cogerboxLibre(pBox1, pBox2, pBox3), pColaListos->cogerPrimeroPrioridad(pt, pPrioridad), colaListos, t); 
		prioridad = pColaListos->buscarPrioridad();
		}
		
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
	
		if ( !boxLibre(box1, box2, box3) )
		{
			cout << endl << "Accion realizada: No quedan boxes libre y he vaciado uno" << endl;
			comprobarBoxFinalizado( pBox1, pBox2, pBox3, t, pColaFinal );
			
		} else if ( pColaInicial->longitudCola() != 0 && pColaListos->longitudCola() == 0 )
		{
			cout << endl << "Accion realizada: Quedaban boxes libres y he movido el tiempo actual hasta donde llege alguien" << endl;
			t = pColaInicial->buscarPrimerTiempoLlegada();
		} else {
			cout << endl << "Accion realizada: Solo quedan vaciar boxes" << endl;
			comprobarBoxFinalizado( pBox1, pBox2, pBox3, t, pColaFinal );
		}
		cout << endl;
		cout << "#### Estado Final de las cola despues de iteracion ###" << endl;
		cout << "Cola Inicial: ";
		pColaInicial->mostrar();
		cout << endl;
		cout << "Cola Listos: ";
		pColaListos->mostrar();
		cout << endl;
		cout << "Cola Final: ";
		pColaFinal->mostrar();
		cout << endl;
		cout << endl <<"#### Tiempo en el que finaliza la iteracion: " << t << " "<<endl;
		
		cout << endl;
		cout << "############################### Terminada Iteracion ###############################" << endl;
		cout << endl;

	}
	
	
	
	cout << endl << "EL TIEMPO FINAL DEL AEROPUERTO: " << calcularTiempoMedioAeropuerto(colaFinal);


}

Airport::~Airport()
{
}


void cambiarCola(Pasajero *p, Cola& colaOrigen, Cola *pcolaDestino)
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
  
  pcolaDestino->insertar(p);
}

void colaDeLista(int t, Cola *pColaOrigen, Cola &colaOrigen, Cola *pColaDestino)
/*
 * Mueve a Cola de Listos todas las personas que hayan llegado al aeropuerto en el time que estemos de la cola Inicial
 */ 
{	
	Pasajero* pasajeroLlegada = pColaOrigen->buscarPersonaLlegada(t);
	while (pasajeroLlegada->getIdentificador() != 0){
		cambiarCola(pasajeroLlegada, colaOrigen, pColaDestino);
		pasajeroLlegada =pColaOrigen->buscarPersonaLlegada(t);
	}
	
}

void serAtendido(Box *box, Pasajero *pp, Cola &colaListos, int t)
/*
 * Mete a una pasajero en un box
 */ 
{
	
	box->setPasajeroEnBox(pp);
	pp->setHoraAtendido(t);
	colaListos.borrarDeCola(pp);
}

void comprobarBoxFinalizado( Box *box1, Box *box2, Box *box3, int &t, Cola *colaFinal )
/*
 * Funcion que comprueba cual es el box que anes se queda vacio, lo vacia y setea el tiempo
 * a dicho momeneot. Tambien setea el momento de salida de la persona del box en dicho momento.
 */ 
{

	
	int a = box1->getOcupado() ?  box1->getValor()->calcularHoraSalida() : 10000 ;
	int b = box2->getOcupado() ?  box2->getValor()->calcularHoraSalida() : 10000 ;
	int h = box3->getOcupado() ?  box3->getValor()->calcularHoraSalida() : 10000 ;
	
	int momentoMasCercanoDeSalida =  min( a, min( b, h));
	t = momentoMasCercanoDeSalida;
	
	if (box1->getOcupado() && box1->getValor()->calcularHoraSalida() == t )
	{
		colaFinal->insertar( box1->getValor() );
		box1->vaciarBox();
	}
	
	if (box2->getOcupado() && box2->getValor()->calcularHoraSalida() == t )
	{
		colaFinal->insertar( box2->getValor() );
		box2->vaciarBox();
	}
	
	if ( box3->getOcupado() && box3->getValor()->calcularHoraSalida() == t )
	{
		colaFinal->insertar( box3->getValor() );
		box3->vaciarBox();
	}

}

bool boxLibre(Box box1, Box box2, Box box3)
/*
 * Devuelve true o false en función de si un algún box está vacío o no
 */ 
{
	return !box1.getOcupado() || !box2.getOcupado() || !box3.getOcupado();
}

Box* cogerboxLibre(Box *box1, Box *box2, Box *box3)
/*
 * Devuelve un box libre, para usar esta función, aconsejable comprobar siempre antes si hay boxLibre,
 * ya que si no devuelve un NULL y habría que tener en cuenta este retorno
 */ 
{
	return (boxLibre(*box1, *box2, *box3) ? (!box1->getOcupado() ? box1 : ((!box2->getOcupado()) ? box2 : box3)) : NULL);
}


float calcularTiempoMedioAeropuerto(Cola colaFinalizados)
/*
 * Calcula el tiempo medio de estancia en el aeropuerto
 */ 
{
	float k = colaFinalizados.calcularTiempoTotalEnAeropuero();
	float l = colaFinalizados.longitudCola();
	float resp = k / l;
	return resp;
}

