#include "Historial.h"

Historial::Historial() : limiteEntradas(100)
{
	this->iteradorActual = historial.end();
}

void Historial::agregarEntrada(std::string& url)
{
	if (iteradorActual != historial.end()) {
		historial.erase(std::next(iteradorActual), historial.end());
	}
	historial.push_back(url);
	iteradorActual = std::prev(historial.end());

	if (historial.size() > limiteEntradas) {
		limpiarEntradasAntiguas();
	}
}

std::string Historial::retroceder()
{
	if (hayEntradasAtras()) {
		--iteradorActual;
	}
	return *iteradorActual;
}

std::string Historial::avanzar()
{
	if (hayEntradasAdelante()) {
		++iteradorActual;
	}
	return *iteradorActual;
}

void Historial::establecerlimiteEntradas(size_t limite)
{
	limiteEntradas = limite;
}

void Historial::limpiarEntradasAntiguas()
{
	while (historial.size() > limiteEntradas) {
		historial.pop_front();
	}
}

bool Historial::hayEntradasAtras()
{
	return iteradorActual != historial.begin();
}

bool Historial::hayEntradasAdelante()
{
	return iteradorActual != std::prev(historial.end());
}

Historial::~Historial()
{
}
