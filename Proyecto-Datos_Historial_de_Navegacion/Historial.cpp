#include "Historial.h"

Historial::Historial() : limiteEntrada(100)
{
	this->iteradorActual = historial.end();
}

void Historial::agregarEntrada(Tab* url)
{
	if (iteradorActual != historial.end()) {
		historial.erase(std::next(iteradorActual), historial.end());
	}
	historial.push_back(url);
	iteradorActual = std::prev(historial.end());

	if (historial.size() > limiteEntrada) {
		limpiarEntradasAntiguas();
	}
}

Tab* Historial::retroceder()
{
	if (!historial.empty()) {
		return *iteradorActual;
	}
	if (hayEntradasAtras()) {
		--iteradorActual;
		return *iteradorActual;
	}
	return nullptr;
}



Tab* Historial::avanzar()
{
	if (!historial.empty()) { 
		return *iteradorActual;
	}

	if  (hayEntradasAdelante()) { 
		++iteradorActual;
		return *iteradorActual; 
	}
	return nullptr; 
}

void Historial::establecerlimiteEntradas(size_t limite)
{
	limiteEntrada = limite;
}

void Historial::limpiarEntradasAntiguas()
{
	while (historial.size() > limiteEntrada) {
		historial.pop_front();
		if (iteradorActual == historial.begin()) {
			iteradorActual = historial.begin(); 
		}
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
	for (Tab* tab : historial) {
		delete tab;
	}

}
