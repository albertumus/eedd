#ifndef PASAJERO_HPP
#define PASAJERO_HPP

class Pasajero
{
public:
	Pasajero(int id, int prior, int horalleg, int dur);
	~Pasajero();
	
	int getIdentificador();
	int getPrioridad();
	int getHoraLlegada();
	int getDuracion();
	void cambiarTiempo(int *t);
	
private:
	int identificador, prioridad, horaLlegada, duracion;
};

#endif // PASAJERO_HPP
