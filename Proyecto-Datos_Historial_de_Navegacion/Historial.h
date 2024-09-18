#pragma once
#include <string>
#include <list>
#include "Pagina.h"

class Historial
{
private:
	std::list<Pagina*> historial;
	std::list<Pagina*>::iterator paginaActual;
	size_t limiteEntrada;

public:
	Historial();

	void agregarEntrada(Pagina* url);
	void inicio();
	void fin();
	bool estaVacio();
	bool hayEntradasAtras();
	bool hayEntradasAdelante();

	Pagina* retroceder();
	Pagina* avanzar();
	void establecerlimiteEntradas(size_t limite);
	void limpiarEntradasAntiguas();

	std::list<Pagina*>& getHistorial();

	std::string toString();

	~Historial();
};

