#pragma once
#include"Marcador.h"	
#include <list>

class GestorDeMarcadores
{
private:
	std::list<Marcador*> marcadores;
public:
	void agregarMarcador(Marcador* marca);
	void eliminarMarcador(std::string url);
	std::list<Marcador*> buscarMarcador(std::string etiquetas);
};

