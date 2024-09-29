#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Pagina.h"
#include <fstream>

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

	void serializar(std::ofstream& archivo);
	void deserializar(std::ifstream& archivo);

	std::vector<Pagina*> filtrarPorPalabra(std::string& palabra);

	std::list<Pagina*>& getHistorial();

	std::string toString();

	~Historial();
};
