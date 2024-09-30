#pragma once
#include <iostream>
#include <string>
#include"EntradaUsuario.h"
#include "Pagina.h"


class Interfaz {
public:
	int mostrarMenuPrincipal();
	int mostrarMenuPestania();
	int mostrarMenuMarcador();
	void noMasPaginas();
	void pagActual();
	void errorArchivo();
	void noPestaniaAbierta();
	void marcadorExp();
	void marcadorImp();
	void historialExp();
	void historialImp();
	Pagina* ingresarPagina();
	std::string ingresarEtiqueta();

	void asistentePaginas();

	void asistentePestanias();

};

