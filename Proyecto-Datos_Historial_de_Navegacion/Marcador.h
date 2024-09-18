#pragma once
#include"Pagina.h"
#include <algorithm>
#include <sstream>

class Marcador
{
private:
	Pagina* pagina;
	std::string etiquetas;
public: 
	Marcador();
	Marcador(Pagina* pagina, std::string etiquetas);
	Pagina* getPagina();
	std::string getEtiquetas();
	std::string toString();
	~Marcador();
};

