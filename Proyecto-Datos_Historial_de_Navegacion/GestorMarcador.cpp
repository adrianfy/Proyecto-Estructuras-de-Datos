#include "GestorMarcador.h"

GestorMarcador::GestorMarcador(){
	marcadores = std::list<Marcador*>();
}

void GestorMarcador::agregarMarcador(Marcador* marc)
{
	marcadores.push_back(marc);
}

void GestorMarcador::eliminarMarcador(std::string url){
	marcadores.remove_if([url](Marcador* marc) {
		return marc->getPagina()->getUrl() == url; 
		}
	);
}

std::list<Marcador*> GestorMarcador::buscarMarcador(std::string etiquetas){
	std::list<Marcador*> marcadoresEncontrados;
	for (auto marcador : marcadores) {
		if (std::find(marcador->getEtiqueta().begin(), marcador->getEtiqueta().end(), etiquetas) != marcador->getEtiqueta().end()) {
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

GestorMarcador::~GestorMarcador(){

}

