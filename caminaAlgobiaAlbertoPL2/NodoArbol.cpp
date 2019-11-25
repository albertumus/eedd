#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Pasajero* psj, NodoArbol* i, NodoArbol* d)
{
	valor = psj;
	izq = i;
	der = d;
}

NodoArbol::~NodoArbol()
{
}

