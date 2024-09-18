#pragma once
#include"Pagina.h"
#include<list>
#include <algorithm>

class Marcador
{
private:
	Pagina* pagina;
	std::list<std::string> etiquetas;
public: 
	Marcador();
	Marcador(Pagina* pagina, const std::list<std::string>& etiquetas);
	Pagina* getPagina() const;
	std::list<std::string> getEtiquetas() const;
};

