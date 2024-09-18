#pragma once
#include <vector>
#include <memory>
#include "Pestania.h"
#include "Marcador.h"

class Navegador
{
private:


public:
	Navegador();
	void nuevoTab();
	void cerrarTab();
	void cambiarTab(int direccion);
	void navegarA(std::string& url);
	void cambiarModoIncognito(bool incognito);
	void agregarMarcador( std::string& url, std::string& etiqueta);
	void buscarMarcadores(const std::string& etiqueta);
	void importarHistorial(const std::string& archivo);
	void exportarHistorial(const std::string& archivo);
	void importarMarcadores(const std::string& archivo);
	void exportarMarcadores(const std::string& archivo);
	void mostrarMenu();
	void manejarInputUsuario();

	~Navegador();
};

