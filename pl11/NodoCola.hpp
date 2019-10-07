#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include <Pasajero.hpp>

#include <iostream>
using namespace std;

class NodoCola
{
public:
	NodoCola(Pasajero* valor, NodoCola* sig = NULL);
	~NodoCola();
	
private:
    Pasajero* valor;
    NodoCola* siguiente;
    
    friend class Cola;
};

typedef NodoCola* pnodo;

#endif // NODOCOLA_HPP
