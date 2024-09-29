#include "GestorPestania.h"

GestorPestania::GestorPestania()
{
	pestaniaActual = listaPestanias.end();
}

void GestorPestania::agregarPestania(Pestania* pestania)
{
	listaPestanias.push_back(pestania);
	if (pestaniaActual == listaPestanias.end()) {
		pestaniaActual = std::prev(listaPestanias.end());
	}
}

void GestorPestania::cerrarPestania()
{
	if (listaPestanias.empty()) return;

	auto it = pestaniaActual;
	if (it != listaPestanias.end()) {
		it = listaPestanias.erase(it);
		if (it == listaPestanias.end() && !listaPestanias.empty()) {
			pestaniaActual = std::prev(listaPestanias.end());
		}
	}
}

void GestorPestania::proximaPestania()
{
	if (pestaniaActual != listaPestanias.end() && std::next(pestaniaActual) != listaPestanias.end()) {
		++pestaniaActual;
	}
	else {
		std::cout << "No hay más pestañas abiertas." << std::endl;
	}
}

void GestorPestania::pestaniaAnterior()
{
	if (pestaniaActual != listaPestanias.begin()) {
		--pestaniaActual;
	}
	else {
		std::cout << "No hay pestañas anteriores." << std::endl;
	}
}

Pestania* GestorPestania::getPestaniaActual()
{
	return *pestaniaActual;
}

std::string GestorPestania::mostrarTabs()
{
	std::stringstream ss;
	int contador = 1;

	for (auto it = listaPestanias.begin(); it != listaPestanias.end(); ++it) {
		if (it == pestaniaActual) {
			ss << "-> Pestaña " << contador << " (Actual): " << (*it)->getPaginaActual()->toString() << std::endl;
		}
		else {
			ss << "Pestaña " << contador << ": " << (*it)->getPaginaActual()->toString() << std::endl;
		}
		++contador;
	}

	return ss.str();
}

void GestorPestania::serializar(std::ofstream& archivo)
{
	size_t cantidadPestanias = listaPestanias.size();
	archivo.write(reinterpret_cast<char*>(&cantidadPestanias), sizeof(cantidadPestanias));

	for (Pestania* p : listaPestanias) {
		p->serializar(archivo); // Llamar a la serialización de cada pestaña
	}
}

void GestorPestania::deserializar(std::ifstream& archivo)
{
	size_t cantidadPestanias;
	archivo.read(reinterpret_cast<char*>(&cantidadPestanias), sizeof(cantidadPestanias));

	for (size_t i = 0; i < cantidadPestanias; ++i) {
		Pestania* nuevaPestania = new Pestania();
		nuevaPestania->deserializar(archivo); // Llamar a la deserialización de cada pestaña
		listaPestanias.push_back(nuevaPestania);
	}
}

GestorPestania::~GestorPestania()
{
	for (Pestania* pestania : listaPestanias) {
		delete pestania;
	}
	listaPestanias.clear();
}
