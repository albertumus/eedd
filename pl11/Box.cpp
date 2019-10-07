#include "Box.hpp"

Box::Box()
{
}

bool Box::getOcupado() 
/*
 * Devuelve el estado de la variable ocupado
 */
{
	return ocupado;
}

void Box::setOcupado(bool i)
/*
 * Setea el valor de la variable ocupado al valor pasado por parametro
 */
{
	ocupado = i;
}

Box::~Box()
{
}

