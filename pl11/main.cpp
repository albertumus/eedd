#include <stdio.h>
#include <Cola.hpp>
#include <Box.hpp>
#include <algorithm>

void cambiarCola(Pasajero *p, Cola *c1, Cola *c2);
void colaDeLista(int t, Cola *colaOrigen, Cola *colaDestino);
void serAtendido(Box *box, Pasajero *pp);
void comprobarBoxFinalizado( Box *box1, Box *box2, Box *box3, int *t );
void colaDeLista(int *t, Cola *colaOrigen, Cola *colaDestino );
bool boxLibre(Box box1, Box box2, Box box3);
Box* cogerboxLibre(Box *box1, Box *box2, Box *box3);
int calcularTiempoMedioAeropuerto(Cola colaFinalizados);

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
	
	int t = 21;
	int* pt = &t;
	int prioridad = 0;
	int* pPrioridad = &prioridad;
	
	Pasajero* pasajero1 = new Pasajero(1,6,0,20);
	colaFinal.insertar(pasajero1);
	Pasajero* pasajero2 = new Pasajero(2,7,5,39);
	colaFinal.insertar(pasajero2);
	Pasajero* pasajero3 = new Pasajero(3,1,0,15);
	colaFinal.insertar(pasajero3);
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
//	colaDeLista(t, pColaInicial, pColaListos);
	//cout << "Después de ejecutar el método..." << endl;
//	pColaInicial->mostrar();
//	pColaListos->mostrar();
//	cout << endl;

	//Probando box libre  =======
//	serAtendido(pBox1, pasajero1);
//	serAtendido(pBox2, pasajero1);
//	serAtendido(pBox3, pasajero1);
//	cout << boxLibre(box1, box2, box3) << endl;

	//Probando coger box libre ======= 
//	serAtendido(pBox1, pasajero1);
//	serAtendido(pBox3, pasajero3);
////	serAtendido(pBox2, pasajero6);
//	
//	cogerboxLibre(pBox1, pBox2, pBox3)->setPasajeroEnBox(pasajero2);
//	cout << pBox2->getValor()->getIdentificador() << endl;
//	cout << boxLibre(box1, box2, box3) << endl;
	
	//Probando calcularTiempoMedioAeropuerto
	pasajero1->setHoraAtendido(32);
	pasajero2->setHoraAtendido(24);
	pasajero3->setHoraAtendido(12);
	cout << "El tiempo medio es: " << calcularTiempoMedioAeropuerto(colaFinal) << endl;
	
//	pColaInicial->buscarPersonaLlegada(pt, pColaInicial);
	
	return 0;
}

void cambiarCola(Pasajero *p, Cola *colaOrigen, Cola *colaDestino)
/*
 * Mueve a una persoan de una cola de inicio a otra final 
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
//	while (pasajeroLlegada->getIdentificador() != 0){
		
		cambiarCola(pasajeroLlegada, colaOrigen, colaDestino);
		pasajeroLlegada = colaOrigen->buscarPersonaLlegada(t);
//	}
}

void serAtendido(Box *box, Pasajero *pp)
/*
 * Mete a una pasajero en un box
 */ 
{
	box->setPasajeroEnBox(pp);
}

void comprobarBoxFinalizado( Box *box1, Box *box2, Box *box3, int *t )
/*
 * Funcion que comprueba cual es el box que anes se queda vacio, lo vacia y setea el tiempo
 * a dicho momeneot. Tambien setea el momento de salida de la persona del box en dicho momento.
 */ 
{
	int momentoMasCercanoDeSalida =  min( box1->getValor()->calcularHoraSalida(), min( box2->getValor()->calcularHoraSalida(), box3->getValor()->calcularHoraSalida()) );
	cout << "El momento más cercano de salida es: " << momentoMasCercanoDeSalida << endl;
	*t = momentoMasCercanoDeSalida;
	
	if ( box1->getValor()->calcularHoraSalida() == *t )
	{
//		box1
	}
	
	if ( box2->getValor()->calcularHoraSalida() == *t )
	{
//		box1
	}
	
	if ( box3->getValor()->calcularHoraSalida() == *t )
	{
//		box1
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


int calcularTiempoMedioAeropuerto(Cola colaFinalizados)
/*
 * Calcula el tiempo medio de estancia en el aeropuerto
 */ 
{
	return (colaFinalizados.calcularTiempoTotalEnAeropuero())/colaFinalizados.longitudCola();
}