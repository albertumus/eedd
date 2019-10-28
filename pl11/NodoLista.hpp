#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Box.hpp"

class NodoLista
{
public:
	NodoLista(Box* box, NodoLista* sig = NULL);
	~NodoLista();
	
private:
    Box* valor;
    NodoLista* siguiente;
    
    friend class Lista;
	friend class Airport;

};

typedef NodoLista* lnodo;

#endif // NODOLISTA_HPP
