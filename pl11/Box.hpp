#ifndef BOX_HPP
#define BOX_HPP
#include "Pasajero.hpp"

class Box
{
public:
	Box( int id );
	~Box();
	
	bool getOcupado();
	void setOcupado(Pasajero* pp);

private:
	Pasajero* valor;
	int identificador;

};

#endif // BOX_HPP
