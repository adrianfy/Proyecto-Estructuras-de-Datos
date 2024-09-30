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

Pagina* Historial::getUltimaPaginaVisitada()
{
	if (!historial.empty()) {
		return *paginaActual;
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

std::vector<std::string> Historial::getPaginas()
{
	std::vector<std::string> paginas;

	for (const auto& pagina : historial)
	{
		if (pagina != nullptr)
		{
			paginas.push_back(pagina->getUrl());
		}
	}

	return paginas;
}

void Historial::serializar(std::ofstream& archivo)
{
	size_t cantidadEntradas = historial.size();
	archivo.write(reinterpret_cast<char*>(&cantidadEntradas), sizeof(cantidadEntradas));

	for (auto& pagina : historial) {
		pagina->serializar(archivo);
	}

	int index = std::distance(historial.begin(), paginaActual);
	archivo.write(reinterpret_cast<char*>(&index), sizeof(index));
}

void Historial::deserializar(std::ifstream& archivo)
{
	size_t sitiosWeb;
	archivo.read(reinterpret_cast<char*>(&sitiosWeb), sizeof(sitiosWeb));

	historial.clear();
	for (size_t i = 0; i < sitiosWeb; ++i) {
		Pagina* sitioWeb = new Pagina();
		sitioWeb->deserializar(archivo); // Llamar a la deserialización de cada marcador
		historial.push_back(sitioWeb);
	}

	int index;
	archivo.read(reinterpret_cast<char*>(&index), sizeof(index));
	paginaActual = historial.begin();
	std::advance(paginaActual, index);
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