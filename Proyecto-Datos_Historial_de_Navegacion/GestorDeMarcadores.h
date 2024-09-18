#pragma once
#include"Marcador.h"	
#include <list>

class GestorDeMarcadores
{
private:
	std::list<Marcador*> marcadores;
public:
	GestorDeMarcadores();
	void agregarMarcador(Marcador* marca);
	void eliminarMarcador(std::string url);
	std::list<Marcador*> buscarMarcador(std::string etiquetas);
	std::string toString();
	~GestorDeMarcadores();

};

