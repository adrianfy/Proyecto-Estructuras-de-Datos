#pragma once
#include <list>
#include "Pagina.h"

class Tab
{
private:
	std::list<Pagina> historial;
	std::list<Pagina>::iterator iteradorActual;
	bool modoIncognito;
	Pagina paginaActual;

public:
	Tab();
	std::list<Pagina>& getHistorial();
	Pagina getPaginaActual();

	void navegar(Pagina& url);
	void retroceder();
	void avanzar();
	void cambiarModoIncognito(bool incognito);
	bool esIncognito();

	~Tab();
};

