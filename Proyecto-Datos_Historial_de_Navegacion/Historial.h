#pragma once
#include <string>
#include <list>
#include "Pagina.h"
#include "Tab.h"

class Historial
{
private:
	std::list<Pagina> historial;
	std::list<Pagina>::iterator iteradorActual;
	size_t limiteEntradas;

public:
	Historial();

	void agregarEntrada(Tab& url);
	std::string retroceder();
	std::string avanzar();
	void establecerlimiteEntradas(size_t limite);
	void limpiarEntradasAntiguas();
	bool hayEntradasAtras();
	bool hayEntradasAdelante();

	~Historial();
};

