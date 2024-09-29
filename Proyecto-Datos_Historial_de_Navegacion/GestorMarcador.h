#pragma once
#include"Marcador.h"	
#include <list>
#include <fstream>

class GestorMarcador
{
private:
	std::list<Marcador*> marcadores;
public:
	GestorMarcador();

	void agregarMarcador(Marcador* marca);
	void eliminarMarcador(std::string url);

	void serializar(std::ofstream& archivo);
	void deserializar(std::ifstream& archivo);

	std::list<Marcador*> buscarMarcador(std::string etiqueta);
	std::string toString();

	~GestorMarcador();

};

