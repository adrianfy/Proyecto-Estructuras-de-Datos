#pragma once
#include<Windows.h>
#include<vector>
#include"Tab.h"

class Buscar
{
protected:
	std::vector<Tab*> tabs;
	int tabActual;
	bool modoIncognito;
public:
	Buscar();
	~Buscar();
	void CambiarPestania(int pes);
	void CambiarModo();
	void GuardarEntradas();
	void Ejecutar();

	Tab* obtenerPestaniaActual();	
};

