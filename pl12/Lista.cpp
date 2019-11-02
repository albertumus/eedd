#include "Lista.hpp"


Lista::Lista()
{
	longitud = 0;
}

int Lista::getLongitud()
{
	return longitud;
}

lnodo Lista::getPrimerNodo()
{
	return primero;
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

Box* Lista::getBoxMenosGente()
{
	lnodo aux = primero;
	Box* auxBox;
	int boxMasLleno = 999;
	
	while (aux){
		if ( aux->valor->getValor()->longitudCola() < boxMasLleno )
		{
			auxBox = aux->valor;
		}
		aux = aux->siguiente;
	}
	
	return auxBox;
}

Box* Lista::getBoxMasGente()
{
	lnodo aux = primero;
	Box* auxBox;
	int boxMasLleno = 0;
	
	while (aux){
		if ( aux->valor->getValor()->longitudCola() > boxMasLleno )
		{
			auxBox = aux->valor;
		}
		aux = aux->siguiente;
	}
	return auxBox;
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

void Lista::borrarBoxesVacios()
{	
	lnodo aux = primero;
	bool hayVacio = false;
	int lon = longitud;

	for ( int i=0; i<lon; i++)
	{
		if( aux->valor->getValor()->longitudCola() == 0)
		{
			if ( hayVacio)
			{
				
			} else
			{
				insertarDerch(aux->valor);
				hayVacio = true;
			}

		}
		else{
			insertarDerch(aux->valor);
		}
		aux = aux->siguiente;
		eliminarIzq();
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

