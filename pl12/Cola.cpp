#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
}

Pasajero* Cola::cogerPrimeroPrioridadYTiempoLlegada()
{
	pnodo aux = primero;
	Pasajero* auxPasajero;
	int llegadaPrimero = 99999;
	int prior = 0;
	
	while (aux){
		if ( aux->valor->getPrioridad() >= prior && aux->valor->getHoraLlegada() < llegadaPrimero && aux->valor->getIdentificador() != 0)
		{
			llegadaPrimero = aux->valor->getHoraLlegada();
			prior = aux->valor->getPrioridad();
			auxPasajero = aux->valor;
		}
		aux = aux->siguiente;
	}
	return auxPasajero;
}

void Cola::insertar(Pasajero* v )
/*
 * Inserta un elemento a la cola
 */
{
    pnodo nuevo;
    nuevo = new NodoCola(v);
    if (ultimo)
        ultimo->siguiente = nuevo;
		ultimo = nuevo;
    if(!primero)
        primero = nuevo;
}

void Cola::insertarPorPrioridad(Pasajero* p)
{
	pnodo nuevoPasajero;
    nuevoPasajero = new NodoCola(p);
	if(this->longitudCola() == 0){
		this->primero = nuevoPasajero; 
	}else if(this->longitudCola() == 1){
		this->primero->siguiente = nuevoPasajero;
		this->ultimo = nuevoPasajero;
	}else{
		if(this->primero->siguiente->valor->getPrioridad() > nuevoPasajero->valor->getPrioridad())
		{
			this->primero->siguiente->siguiente = nuevoPasajero;
			this->ultimo = nuevoPasajero;
		}else
		{
			nuevoPasajero->siguiente = this->primero->siguiente;
			this->primero->siguiente = nuevoPasajero;
		}
	}
}

int Cola::eliminar()
/*
 * Elimina el primer elemento de la cola
 */
{
    pnodo nodo;
    Pasajero* v;
    nodo = primero;
    if (!nodo)
        return 0;
    primero = nodo->siguiente;
    v = nodo->valor;
    delete nodo;
    if (!primero)
        ultimo = NULL;
    return v->getIdentificador();
}

void Cola::mostrarPrimero()
/*
 * Muestra el primero de la cola
 */ 
{
	cout << primero->valor;
}

void Cola::mostrar()
/*
 * Muestra la cola en su totalidad
 */
{
    pnodo aux = primero;
    cout << endl;
    while(aux) {
        aux->valor->mostrarPasajero();
        aux = aux->siguiente;
    }
    cout << endl;
}

int Cola::longitudCola()
/*
 * Muestra la longitud de la cola
 */
{
	int len = 0;
    pnodo aux = primero;
    while(aux) {
        len++;
        aux = aux->siguiente;
    }
	return len;
}

int Cola::buscarPrimerTiempoLlegada() {
	
	pnodo aux = primero;
	int llegadaPrimero = aux->valor->getHoraLlegada();
	
	
	while (aux)
	{
		if ( aux->valor->getHoraLlegada() < llegadaPrimero )
		{
			llegadaPrimero = aux->valor->getHoraLlegada();
		}
		aux = aux->siguiente;
	}
	
	return llegadaPrimero;
}

Pasajero* Cola::getPrimero()
{
  return primero->valor;
}

pnodo Cola::getPrimeroNodo() 
{
	return primero;
}

void Cola::borrarDeCola(Pasajero *pp )
/*
 * Borra de la cola pasada por parámetro el pasajero pasado por parámetro
 */
{
  
	pnodo aux = primero;
  
  int lenCola = this->longitudCola();
   
	for ( int i=0; i<lenCola; i++ )
	{
		if ( aux->valor->getIdentificador() != pp->getIdentificador() )
		{
		  this->insertar(aux->valor);
		}

		this->eliminar();
		aux = primero;
	}
}

Pasajero* Cola::buscarPersonaLlegada(int t) 
{
	Pasajero* auxPas = new Pasajero(0,0,0,0);
    pnodo aux = primero;
    while(aux) {
        if ( aux->valor->getHoraLlegada() <= t )
		{
			auxPas = aux->valor;
			return auxPas;
		}
        aux = aux->siguiente;
    }
	return auxPas;
}

int Cola::calcularTiempoTotalEnAeropuero()
{
	int sumatorio = 0;
	pnodo aux = primero;
    while(aux) {
		sumatorio = sumatorio + aux->valor->calcularTiempoQuePasaEnAeropuerto();
		aux = aux->siguiente;
    }
	return sumatorio;
}

Cola::~Cola()
/*
 * Destructor de la cola 
 */
{
    while(primero)
        eliminar();
}
