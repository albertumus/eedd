#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
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
    cout << "Cola: " << endl;
    while(aux) {
        cout << "Pasajero Numero -> " << aux->valor->getIdentificador() << endl;
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

Pasajero* Cola::cogerPrimeroPrioridad( int *t, int *prior )
{
	pnodo aux = primero;
	Pasajero* auxPasajero;
	
	while (aux){
	//while (aux->longitudCola() > 0 ){
		if ( aux->valor->getPrioridad() == *prior)
		{
			auxPasajero = aux->valor;
			return auxPasajero;
		}
		
		aux = aux->siguiente;
	}
	
	return auxPasajero;
}

int Cola::buscarPrioridad() 
{
	int priodadMax = 0;
    pnodo aux = primero;
    while(aux) {
        if ( aux->valor->getPrioridad() > priodadMax )
		{
			priodadMax = aux->valor->getPrioridad();
		}
			
        aux = aux->siguiente;
    }
	return priodadMax;
}

void Cola::borrarDeCola(Pasajero *pp, Cola *pc)
/*
 * Borra de la cola pasada por parámetro el pasajero pasado por parámetro
 */
{
	pnodo aux = primero;
	Cola auxCola;
	
	while (aux){
	//while (aux->longitudCola() > 0 ){
		if ( aux->valor->getIdentificador() != pp->getIdentificador() )
		{
			auxCola.insertar(aux->valor);
		}
		
		aux = aux->siguiente;
	}
	
	*pc = auxCola;	
}

Pasajero* Cola::buscarPersonaLlegada( int *t)
{
    Pasajero* auxPasajero = new Pasajero(0,0,0,0);
    pnodo aux = primero;
    while ( aux )
    {
        if (aux->valor->getHoraLlegada() <= *t )
        {
            auxPasajero = aux->valor;
            return auxPasajero;
        }
        aux = aux->siguiente;
    }
    
    return auxPasajero;
}

Cola::~Cola()
/*
 * Destructor de la cola 
 */
{
    while(primero)
        eliminar();
}