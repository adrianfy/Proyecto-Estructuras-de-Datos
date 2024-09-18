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


std::list<Marcador*> GestorMarcador::buscarMarcador(std::string etiqueta) {
	std::list<Marcador*> marcadoresEncontrados;
	for (auto marcador : marcadores) {
		// Usa find() en lugar de std::find
		if (marcador->getEtiqueta().find(etiqueta) != std::string::npos) {
			marcadoresEncontrados.push_back(marcador);
		}
	}
	return marcadoresEncontrados;
}



std::string GestorMarcador::toString(){
	std::stringstream s;
	for (auto marcador : marcadores) {
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


