#include "GestorDeMarcadores.h"

void GestorDeMarcadores::agregarMarcador(Marcador* marc)
{
	marcadores.push_back(marc);
}

void GestorDeMarcadores::eliminarMarcador(std::string url){
	marcadores.remove_if([url](Marcador* marc) {
		return marc->getPagina()->getUrl() == url; 
		}
	);
}

std::list<Marcador*> GestorDeMarcadores::buscarMarcador(std::string etiquetas){
	std::list<Marcador*> marcadoresEncontrados;
	for (auto marcador : marcadores) {
		if (std::find(marcador->getEtiquetas().begin(), marcador->getEtiquetas().end(), etiquetas) != marcador->getEtiquetas().end()) {
			marcadoresEncontrados.push_back(marcador);
		}
	}
	return marcadoresEncontrados;
}

