#pragma once
#include"Pagina.h"
//#include <algorithm>
#include <sstream>

class Marcador
{
private:
	Pagina* pagina;
	std::string etiqueta;
public: 
	Marcador();
	Marcador(Pagina* pagina, std::string etiqueta);
	Pagina* getPagina();
	std::string getEtiqueta();
	std::string toString();
	~Marcador();
};

