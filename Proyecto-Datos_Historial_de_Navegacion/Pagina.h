#pragma once
#include <sstream>
#include "Hora.h"

class Pagina
{
private:
	std::string url;
	Hora* marcaDeTiempo;

public:
	Pagina();
	Pagina(std::string url);

	std::string getUrl();

	std::string toString();
	std::string mostrarEnHistorial();

	~Pagina();
};