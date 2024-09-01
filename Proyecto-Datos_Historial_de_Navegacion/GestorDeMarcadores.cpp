#include "GestorDeMarcadores.h"

void GestorDeMarcadores::agregarMarcador(Marcador* marc)
{
	marcadores.push_back(marc);
}

void GestorDeMarcadores::eliminarMarcador(const std::string& url)
{
	marcadores.erase(std::remove_if(marcadores.begin(), marcadores.end(),
		[&url](Marcador* marcador) { 
			return marcador->getPagina()->getUrl() == url;
		}), marcadores.end()); 
}

std::vector<Marcador*> GestorDeMarcadores::buscarMarcador(const std::string& tags)
{
	std::vector<Marcador*> resultado;

	for (Marcador* marcador : marcadores) {
		if (std::find(marcador->getEtiquetas().begin(), marcador->getEtiquetas().end(), tags) != marcador->getEtiquetas().end()) {
			resultado.push_back(marcador);
		}
	}
	return resultado;
}
