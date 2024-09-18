#pragma once
#include<Windows.h>
#include<vector>
#include"Pestania.h"

class Buscar
{
protected:
	std::vector<Pestania*> tabs;
	int tabActual;
	bool modoIncognito;
public:
	Buscar();
	~Buscar();
	void CambiarPestania(int pes);
	void CambiarModo();
	void GuardarEntradas();
	void Ejecutar();

	Pestania* obtenerPestaniaActual();
};

