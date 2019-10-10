#include "Box.hpp"

Box::Box(int id)
{
	identificador = id;
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

void Box::setOcupado(Pasajero* pp)
/*
 * Setea el valor de la variable ocupado al valor pasado por parametro
 */
{
	valor = pp;
}

Box::~Box()
{
}

