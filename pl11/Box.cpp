#include "Box.hpp"

Box::Box(int id)
{
	identificador = id;
	valor = 0;
}

bool Box::getOcupado() 
/*
 * Devuelve el estado de la variable ocupado
 */
{
	if ( valor )
	{
		return true;
	} else 
	{
		return false;
	}
}

void Box::vaciarBox()
{
	valor = false;
}

Pasajero* Box::getValor() 
{
	return valor;
}
void Box::setPasajeroEnBox(Pasajero* pp)
/*
 * Setea el valor de la variable ocupado al valor pasado por parametro
 */
{

	valor = pp;
}

Box::~Box()
{
}

