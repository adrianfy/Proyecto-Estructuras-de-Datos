#include "GestorPestania.h"

GestorPestania::GestorPestania()
{
	this->pestaniaActual = listaPestanias.end();
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
	else if(pestaniaActual == listaPestanias.end()){
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
	if (pestaniaActual != listaPestanias.end()) {
		return *pestaniaActual;
	}
	else {
		return nullptr; 
	}
}

std::list<Pestania*>& GestorPestania::getPestanias()
{
	return listaPestanias;
}

std::string GestorPestania::mostrarTabs()
{
	std::stringstream ss;
	int contador = 1;

	if (listaPestanias.empty()) {
		ss << "No hay pestañas abiertas." << std::endl;
		return ss.str();
	}

	for (auto it = listaPestanias.begin(); it != listaPestanias.end(); ++it) {
		if (*it == nullptr) {
			ss << "Pestaña " << contador << ": (Pestaña inválida)" << std::endl;
		}
		else if (it == pestaniaActual) {
			Pagina* paginaActual = (*it)->getPaginaActual();
			if (paginaActual != nullptr) {
				ss << "-> Pestaña " << contador << " (Actual): " << paginaActual->toString() << std::endl;
			}
			else {
				ss << "-> Pestaña " << contador << " (Actual): Página actual no disponible" << std::endl;
			}
		}
		else {
			Pagina* paginaActual = (*it)->getPaginaActual();
			if (paginaActual != nullptr) {
				ss << "Pestaña " << contador << ": " << paginaActual->toString() << std::endl;
			}
			else {
				ss << "Pestaña " << contador << ": Página actual no disponible" << std::endl;
			}
		}
		++contador;
	}

	return ss.str();
}

void GestorPestania::serializar(std::ofstream& archivo)
{
	size_t cantidadPestanias = listaPestanias.size();
	archivo.write(reinterpret_cast<char*>(&cantidadPestanias), sizeof(cantidadPestanias));

	for (Pestania* pestania : listaPestanias) {
		pestania->serializar(archivo);
	}
	int index = std::distance(listaPestanias.begin(), pestaniaActual);
	archivo.write(reinterpret_cast<char*>(&index), sizeof(index));
}

void GestorPestania::deserializar(std::ifstream& archivo)
{
	size_t cantidadPestanias;
	archivo.read(reinterpret_cast<char*>(&cantidadPestanias), sizeof(cantidadPestanias));

	listaPestanias.clear();
	for (size_t i = 0; i < cantidadPestanias; ++i) {
		Pestania* nuevaPestania = new Pestania();
		nuevaPestania->deserializar(archivo); // Llamar a la deserialización de cada marcador
		listaPestanias.push_back(nuevaPestania);
	}
	int index;
	archivo.read(reinterpret_cast<char*>(&index), sizeof(index));
	pestaniaActual = std::next(listaPestanias.begin(), index);
	std::advance(pestaniaActual, index);
	
}

GestorPestania::~GestorPestania()
{
	for (Pestania* pestania : listaPestanias) {
		delete pestania;
	}
	listaPestanias.clear();
}