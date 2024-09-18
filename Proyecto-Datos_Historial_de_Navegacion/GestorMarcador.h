#pragma once
#include"Marcador.h"	
#include <list>

class GestorMarcador
{
private:
	std::list<Marcador*> marcadores;
public:
	GestorMarcador();

	void agregarMarcador(Marcador* marca);
	void eliminarMarcador(std::string url);

	std::list<Marcador*> buscarMarcador(std::string etiqueta);
	std::string toString();

	~GestorMarcador();

};

