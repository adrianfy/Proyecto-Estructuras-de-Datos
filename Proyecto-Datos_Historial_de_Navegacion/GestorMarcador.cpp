#include "GestorMarcador.h"

GestorMarcador::GestorMarcador(){
	marcadores = std::list<Marcador*>();
}

void GestorMarcador::agregarMarcador(Marcador* marc)
{
	marcadores.push_back(marc);
}

void GestorMarcador::eliminarMarcador(std::string url) {
	marcadores.remove_if([url](Marcador* marc) {
		if (marc->getPagina()->getUrl() == url) {
			delete marc;  // Libera la memoria
			return true;
		}
		return false;
		});
}

void GestorMarcador::serializar(std::ofstream& archivo)
{
	size_t cantidadMarcadores = marcadores.size();
	archivo.write(reinterpret_cast<char*>(&cantidadMarcadores), sizeof(cantidadMarcadores));

	for (Marcador* m : marcadores) {
		m->serializar(archivo); // Llamar a la serialización de cada marcador
	}
}

void GestorMarcador::deserializar(std::ifstream& archivo)
{
	size_t cantidadMarcadores;
	archivo.read(reinterpret_cast<char*>(&cantidadMarcadores), sizeof(cantidadMarcadores));

	for (size_t i = 0; i < cantidadMarcadores; ++i) {
		Marcador* nuevoMarcador = new Marcador();
		nuevoMarcador->deserializar(archivo); // Llamar a la deserialización de cada marcador
		marcadores.push_back(nuevoMarcador);
	}
}

std::list<Marcador*>& GestorMarcador::getMarcadores()
{
	return marcadores; 
}

std::list<Marcador*> GestorMarcador::buscarMarcador(std::string etiqueta) {
	std::list<Marcador*> marcadoresEncontrados;
	for (auto marcador : marcadores) {

		if (marcador->getEtiqueta().find(etiqueta) != std::string::npos) {
			marcadoresEncontrados.push_back(marcador);
		}
	}
	return marcadoresEncontrados;
}



std::string GestorMarcador::toString(){
	std::stringstream s;
	if (marcadores.empty()) {
		s << "No hay marcadores" << std::endl;
		return s.str();
	}

	for (auto marcador : marcadores) {
		s << "Lista de Marcadores: " << std::endl;
		s << marcador->toString() << std::endl;
	}
	return s.str();

}

GestorMarcador::~GestorMarcador() {
	for (auto marcador : marcadores) {
		delete marcador;  // Libera la memoria de cada puntero
	}
	marcadores.clear();  // Limpia la lista
}


