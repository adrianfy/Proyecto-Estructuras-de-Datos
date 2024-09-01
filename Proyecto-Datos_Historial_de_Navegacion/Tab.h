#pragma once
#include <string>
#include "Historial.h"

class Tab
{
private:
	Historial historial;
	bool modoIncognito;
	std::string urlActual;

public:
	Tab();

	std::string getUrlActual();

	void navegar(std::string& url);
	void retroceder();
	void avanzar();
	void cambiarModoIncognito(bool incognito);
	bool esIncognito();

	~Tab();

};

