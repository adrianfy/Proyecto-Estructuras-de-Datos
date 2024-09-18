#pragma once
#include"Pagina.h"

#include <algorithm>

class Marcador
{
private:
	Pagina* pagina;
	std::string etiquetas;
public: 
	Marcador();
	Marcador(Pagina* pagina, const std::string etiquetas);
	Pagina* getPagina() const;
	std::string getEtiquetas() const;
};

