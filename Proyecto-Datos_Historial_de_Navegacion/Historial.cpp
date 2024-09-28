#include "Historial.h"

Historial::Historial() : limiteEntrada(100)
{
	this->paginaActual = historial.end();
}

void Historial::agregarEntrada(Pagina* url)
{
	if (paginaActual != historial.end()) {
		historial.erase(std::next(paginaActual), historial.end());
	}
	historial.push_back(url);
	paginaActual = std::prev(historial.end());

	if (historial.size() > limiteEntrada) {
		limpiarEntradasAntiguas();
	}
}

Pagina* Historial::retroceder()
{
	if (!historial.empty()) {
		if (hayEntradasAtras()) {
			--paginaActual;
			return *paginaActual;
		}
	}

	return nullptr;
}

Pagina* Historial::avanzar()
{
	if (!historial.empty()) {
		if (hayEntradasAdelante()) {
			++paginaActual;
			return *paginaActual;
		}
	}

	return nullptr;
}

void Historial::inicio()
{
	paginaActual = historial.begin();
}

void Historial::fin()
{
	paginaActual = std::prev(historial.end());
}

bool Historial::estaVacio()
{
	return historial.empty();
}


void Historial::establecerlimiteEntradas(size_t limite)
{
	limiteEntrada = limite;
}

void Historial::limpiarEntradasAntiguas()
{
	while (historial.size() > limiteEntrada) {
		historial.pop_front();
		if (paginaActual == historial.begin()) {
			paginaActual = historial.begin();
		}
	}
}

std::vector<Pagina*> Historial::filtrarPorPalabra(std::string& palabra) {
	std::vector<Pagina*> resultado;

	for (Pagina* pagina : historial) {
		if (pagina->getUrl().find(palabra) != std::string::npos) {
			resultado.push_back(pagina);
		}
	}

	return resultado;
}

bool Historial::hayEntradasAtras()
{
	return paginaActual != historial.begin();
}

bool Historial::hayEntradasAdelante()
{
	return paginaActual != std::prev(historial.end());
}

std::list<Pagina*>& Historial::getHistorial()
{
	return historial;
}

std::string Historial::toString()
{
	if (historial.empty()) {
		return "Historial vacío.";
	}

	std::string historialStr;
	for (const auto& pagina : historial) {
		if (pagina != nullptr) {
			historialStr += pagina->mostrarEnHistorial() + "\n";
		}
	}
	return historialStr;
}

Historial::~Historial()
{
	historial.clear();
}