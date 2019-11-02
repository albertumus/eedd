#include "NodoLista.hpp"

NodoLista::NodoLista(Box* box, NodoLista* sig)
{
	valor = box;
    siguiente = sig; 
}

NodoLista::~NodoLista()
{
}

