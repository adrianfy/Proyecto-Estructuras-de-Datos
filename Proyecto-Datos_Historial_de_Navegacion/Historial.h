#pragma once
#include <string>
#include <list>

class Historial
{
private:
	std::list<Pagina> historial;
	std::list<Pagina>::iterator iteradorActual;
	size_t limiteEntradas;

public:
	Historial();

	void agregarEntrada(Tab& url);
	std::string retroceder();
	std::string avanzar();
	void establecerlimiteEntradas(size_t limite);
	void limpiarEntradasAntiguas();
	bool hayEntradasAtras();
	bool hayEntradasAdelante();

	~Historial();
};

