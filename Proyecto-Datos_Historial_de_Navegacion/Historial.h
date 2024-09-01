#pragma once
#include <string>
#include <list>

class Historial
{
private:
	std::list<std::string> historial;
	std::list<std::string>::iterator iteradorActual;
	size_t limiteEntradas;

public:
	Historial();

	void agregarEntrada(std::string& url);
	std::string retroceder();
	std::string avanzar();
	void establecerlimiteEntradas(size_t limite);
	void limpiarEntradasAntiguas();
	bool hayEntradasAtras();
	bool hayEntradasAdelante();

	~Historial();
};

