#include "Box.hpp"

Box::Box(int id)
{
	identificador = id;
}

void Box::mostrarBox()
{
	cout << "Box numero " << identificador << " con gente en cola " << getValor()->longitudCola() << endl;
	cout << "La gente del box es ";
	valor->mostrar();
}

bool Box::getOcupado() 
/*
 * Devuelve el estado de la variable ocupado
 */
{
	if ( valor->getPrimero()->estaSiendoAtendido() )
	{
		return true;
	} else 
	{
		return false;
	}
}

int Box::getIdentificador()
{
	return identificador;
}

void Box::vaciarBox()
{
	valor = false;
}

Cola* Box::getValor() 
{
	return valor;
}
void Box::setPasajeroEnColaBox(Pasajero* pp)
/*
 * Setea el valor de la variable ocupado al valor pasado por parametro
 */
{
	pp->setIdentificadorBox(identificador);
	valor->insertar(pp);
}

Box::~Box()
{
}

