#pragma once
#include <Windows.h>
#include <memory>
#include <iostream>
#include "GestorPestania.h"

class Navegador
{
private:
	GestorPestania* gestorPestania;
	//Historial* historial;

public:
	Navegador();

	void ejecutar();
	void mostrarMenu();
	
	void nuevaPestania();
	void cerrarPestania();	
	void cambiarPestania(int direccion);
	void navegarA(std::string& url);
	void cambiarModoIncognito(bool incognito);

	void agregarMarcador(std::string& url, std::string& etiqueta);
	void buscarMarcadores(std::string& etiqueta);
	void filtrarMarcadores(std::string& etiqueta);

	void importarHistorial(std::string& archivo);
	void exportarHistorial(std::string& archivo);

	void importarMarcadores(std::string& archivo);
	void exportarMarcadores(std::string& archivo);

	void mostrarHistorial();
	void mostrarMarcadores();
	void mostrarPestanias();

	void manejarInputUsuario();

	~Navegador();
};

