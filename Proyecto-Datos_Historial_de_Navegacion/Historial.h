#pragma once
#include <string>
#include <list>
#include <vector>
#include <algorithm>
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

	std::vector<Pagina*> filtrarPorPalabra(std::string& palabra);

	std::list<Pagina*>& getHistorial();

	std::string toString();

	~Historial();
};
