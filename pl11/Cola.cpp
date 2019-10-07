#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
}

void Cola::insertar(Pasajero* v )
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
{
    pnodo aux = primero;
    cout << "Cola: ";
    while(aux) {
        cout << "Pasajero Numero -> " << aux->valor->getIdentificador();
        aux = aux->siguiente;
    }
    cout << endl;
}

Cola::~Cola()
{
    while(primero)
        eliminar();
}