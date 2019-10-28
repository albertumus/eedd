#ifndef BOX_HPP
#define BOX_HPP
#include "Cola.hpp"

class Box
{
public:
	Box( int id );
	~Box();
	
	bool getOcupado();
	void mostrarBox();
	int getIdentificador();
	Cola* getValor();
	void vaciarBox();
	void setPasajeroEnColaBox(Pasajero* pp);

private:
	Cola* valor = new Cola();
	int identificador;

};

#endif // BOX_HPP
