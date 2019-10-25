#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"

class Lista
{
public:
	Lista();
	~Lista();
	
	int getLongitud();
	void reducirLongitud(int reduc = 1);
	void insertarIzq(Box* box);
	void insertarDerch(Box* box);
	void eliminarIzq();
	void eliminarDerch();
	void mostrar();
	Box* getPrimero();

private:
	int longitud;
	lnodo primero;

};

#endif // LISTA_HPP
