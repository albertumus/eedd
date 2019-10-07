#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include <iostream>
using namespace std;

class NodoCola
{
public:
	NodoCola(int v, NodoCola* sig = NULL);
	~NodoCola();
	
private:
    int valor;
    NodoCola* siguiente;
    
    friend class Cola;
};

typedef NodoCola* pnodo;

#endif // NODOCOLA_HPP
