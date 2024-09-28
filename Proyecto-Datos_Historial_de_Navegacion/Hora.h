#pragma once
#include <string>
#include <sstream>
#include <ctime>

class Hora
{
private:
	int hora;
	int minuto;
public:
	Hora();
	Hora(int hora, int minuto);

	int getHora();
	int getMinuto();

	std::string toString();
	~Hora();
};

