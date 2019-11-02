#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"

class Lista
{
public:
	Lista();
	~Lista();
	
	int getLongitud();
	void insertarIzq(Box* box);
	void insertarDerch(Box* box);
	void eliminarIzq();
	void eliminarDerch();
	void mostrar();
	bool hayBoxVacio();
	void borrarBoxesVacios();
	Box* getBoxMenosGente();
	Box* getBoxMasGente();
	lnodo getPrimerNodo();
	Box* getPrimero();

private:
	int longitud;
	lnodo primero;

};

#endif // LISTA_HPP
