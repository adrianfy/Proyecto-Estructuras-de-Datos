#pragma once
#include <Windows.h>
#include <memory>
#include <iostream>
#include "GestorPestania.h"
#include "GestorMarcador.h"
#include "Sesion.h"
#include "Interfaz.h"

class Navegador
{
private:
	GestorPestania* gestorPestania;
	GestorMarcador* gestorMarcador;
	Sesion* sesion;
	Interfaz* interfaz;

public:
	Navegador();
	Navegador(Interfaz* interfaz);	

	void incializarDatos();

	void ejecutar();

	void subMenuPestania();
	void subMenuMarcador();

	int mostrarMenuPestania();
	
	void navegarEntrePaginas();
	void cambiarEntrePestanias();
	
	void nuevaPestania();
	void cerrarPestania();	
	void filtrarHistorial();
	void navegarA(std::string& url);
	void cambiarModoIncognito(bool incognito);

	void agregarMarcador(std::string& url, std::string& etiqueta);
	Marcador* seleccionarMarcador();
	void importarHistorial();
	void exportarHistorial();

	void importarMarcadores(std::string& archivo);
	void exportarMarcadores(std::string& archivo);

	void mostrarHistorial();
	void mostrarMarcadores();
	void mostrarPestanias();


	~Navegador();
};

