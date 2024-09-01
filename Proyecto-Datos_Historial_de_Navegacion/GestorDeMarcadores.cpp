#include "GestorDeMarcadores.h"

void GestorDeMarcadores::agregarMarcador(Marcador* marc)
{
	marcadores.push_back(marc);
}

void GestorDeMarcadores::eliminarMarcador(const std::string& url)
{
	marcadores.erase(std::remove_if(marcadores.begin(), marcadores.end(),
		[&url](Marcador* marcador) { 
			return marcador->getPage()->getUrl() == url;  
		}), marcadores.end()); 
}

std::vector<Marcador*> GestorDeMarcadores::buscarMarcador(const std::string& tags)
{
	std::vector<Marcador*> resultado;

	for (Marcador* marcador : marcadores) {
		if (std::find(marcador->getTags().begin(), marcador->getTags().end(), tags) != marcador->getTags().end()) {
			resultado.push_back(marcador);
		}
	}
	return resultado;
}
