#pragma once
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include <iostream>

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

	void serializar(std::ofstream& archivo);
	static Hora* deserializar(std::ifstream& archivo);

	std::string toString();
	~Hora();
};

