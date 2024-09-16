#include "Historial.h"

Historial::Historial() : limiteEntradas(100)
{
	this->iteradorActual = historial.end();
}

void Historial::agregarEntrada(Pagina& url)
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
	if (!historial.empty()) { 
		return ""; 
	}
	if (hayEntradasAtras()) { 
		--iteradorActual;  
		return *iteradorActual; 
	}
	return""; 
}

std::string Historial::avanzar()
{
	if (!historial.empty()) { 
		return "";
	}

	if  (hayEntradasAdelante()) { 
		++iteradorActual;
		return *iteradorActual; 
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
}
