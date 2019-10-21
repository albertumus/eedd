#include <stdio.h>
#include <Airport.hpp>

int main(int argc, char **argv)
{
	Airport* a1 = new Airport();
	a1->gestionarAeropuerto();
	
}

Box* cogerboxLibre(Box *box1, Box *box2, Box *box3)
/*
 * Devuelve un box libre, para usar esta función, aconsejable comprobar siempre antes si hay boxLibre,
 * ya que si no devuelve un NULL y habría que tener en cuenta este retorno
 */ 
{
	return (boxLibre(*box1, *box2, *box3) ? (!box1->getOcupado() ? box1 : ((!box2->getOcupado()) ? box2 : box3)) : NULL);
}


float calcularTiempoMedioAeropuerto(Cola colaFinalizados)
/*
 * Calcula el tiempo medio de estancia en el aeropuerto
 */ 
{
	float k = colaFinalizados.calcularTiempoTotalEnAeropuero();
	float l = colaFinalizados.longitudCola();
	float resp = k / l;
	return resp;
}
