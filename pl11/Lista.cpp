#include "Lista.hpp"


Lista::Lista()
{
	longitud = 0;
}

int Lista::getLongitud()
{
	return longitud;
}

bool Lista::hayBoxVacio()
{
	lnodo aux = primero;
	bool vacio = false;
	
	for ( int i=1; i<longitud; i++)
	{
		vacio = primero->valor->getValor()->longitudCola() == 0 ? true : false; 
		aux = aux->siguiente;
	}
	
	return vacio;
	
}

Box* Lista::getPrimero()
{
	return primero->valor;
}

void Lista::reducirLongitud(int reduc) 
{
	longitud = longitud - reduc;
}

void Lista::insertarIzq(Box* box)
{
	lnodo nuevo_nodo;
	nuevo_nodo = new NodoLista(box);
	
	if ( !primero )
	{
		primero = nuevo_nodo;
		longitud = 1;
	} else 
	{
		nuevo_nodo->siguiente = primero;
		primero = nuevo_nodo;
		longitud = longitud + 1;
	}
	
}

void Lista::insertarDerch(Box* box)
{
	lnodo nuevo_nodo;
	nuevo_nodo = new NodoLista(box);
	
	if ( this->getLongitud() < 1 )
	{
		primero = nuevo_nodo;
		longitud = 1;
	} else
	{
		lnodo aux = primero;
		for(int i=1; i<longitud; i++)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;
		longitud = longitud + 1;
	}

}

void Lista::mostrar()
{
	lnodo aux = primero;
	
	for ( int i=0; i<longitud; i++)
	{
		aux->valor->mostrarBox();
		aux = aux->siguiente;
	}
	
	cout << endl;
}

void Lista::eliminarIzq()
{
	if ( primero->siguiente ) 
	{
		lnodo aux = primero;
		primero = aux->siguiente;
		aux->siguiente = NULL;
		delete(aux);
		longitud = longitud - 1;
	} else {
		lnodo aux = primero;
		primero = NULL;
		longitud = 0;
		delete(aux);
	}
}

void Lista::eliminarDerch()
{	
	if ( primero->siguiente )
	{
		lnodo aux = primero;
		lnodo aux_2;
		for(int i=1; i<longitud; i++)
		{
			aux = aux->siguiente;
		}
		aux_2 = aux->siguiente;
		aux->siguiente = NULL;
		delete(aux_2);
		longitud = longitud - 1;
	} else
	{
		lnodo aux = primero;
		primero = NULL;
		delete(aux);
		longitud = 0;
	}
	
}

Lista::~Lista()
{
}

