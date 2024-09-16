#pragma once
#include <string>
#include <vector>
#include "Pagina.h"
#include "Historial.h"

class Tab
{
private:
	Historial historial;
	bool modoIncognito;
	Pagina paginaActual;

public:
	Tab();
	Historial getHistorial();
	Pagina getPaginaActual();

	void navegar(Pagina url);
	void retroceder();
	void avanzar();
	void cambiarModoIncognito(bool incognito);
	bool esIncognito();

	std::vector<Pagina*> getHistorial() const;
	Pagina* getPaginaActual() const;

	~Tab();

};

