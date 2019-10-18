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

void Cola::mostrar()
/*
 * Muestra la cola en su totalidad
 */
{
    pnodo aux = primero;
    cout << "Cola: ";
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
	cout << "La prioridad maxima de la cola es: " << priodadMax;
	return priodadMax;
}

Cola::~Cola()
/*
 * Destructor de la cola 
 */
{
    while(primero)
        eliminar();
}