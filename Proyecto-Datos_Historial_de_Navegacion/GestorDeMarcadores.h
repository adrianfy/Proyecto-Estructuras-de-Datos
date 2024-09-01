#pragma once
#include"Marcador.h"	
#include<algorithm>

class GestorDeMarcadores
{
protected:
	std::vector<Marcador*> marcadores;
public:
	/*GestorDeMarcadores(Marcador* marc);*/
	void agregarMarcador(Marcador* marc);
	void eliminarMarcador(const std::string& url);
	std::vector<Marcador*> buscarMarcador(const std::string& tags);
};

