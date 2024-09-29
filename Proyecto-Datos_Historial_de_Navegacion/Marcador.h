#pragma once
#include"Pagina.h"
#include <fstream>
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

    // M�todo para serializar el marcador
    void serializar(std::ofstream& archivo);

    // M�todo para deserializar el marcador
	void deserializar(std::ifstream& archivo);

	std::string toString();
	~Marcador();
};

