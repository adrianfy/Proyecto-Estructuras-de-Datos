#pragma once
#include"Pagina.h"
#include<vector>

class Marcador
{
protected:
	Pagina* pagina;
	std::vector<std::string> etiquetas;
public: 
	Marcador();
	Marcador(Pagina* pagina, const std::vector<std::string>& etiquetas);
	Pagina* getPagina() const;
	std::vector<std::string> getEtiquetas() const;
};

