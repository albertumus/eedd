#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"

class Cola
{
public:
	Cola();
	~Cola();
	
	void insertar(int v);
    int eliminar();
    void mostrar();

private:
    pnodo primero, ultimo;
};


#endif // COLA_HPP
