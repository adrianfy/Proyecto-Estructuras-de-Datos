#pragma once
#include <string>
#include <list>
#include "Tab.h"

class Historial
{
private:
	std::list<Tab*> historial;
	std::list<Tab*>::iterator iteradorActual;
	size_t limiteEntrada;

	

public:
	Historial();

	void agregarEntrada(Tab* url);
	Tab* retroceder();
	Tab* avanzar();
	void establecerlimiteEntradas(size_t limite);
	void limpiarEntradasAntiguas();
	bool hayEntradasAtras();
	bool hayEntradasAdelante();

	~Historial();
};

