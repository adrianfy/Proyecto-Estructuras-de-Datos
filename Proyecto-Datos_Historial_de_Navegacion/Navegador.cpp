#include "Navegador.h"
#include <iostream>

Navegador::Navegador() {
	this->gestorPestania = new GestorPestania();
	this->gestorMarcador = new GestorMarcador();
}

void Navegador::incializarDatos()
{
	// Crear una pesta�a para pruebas

	Pestania* pestania1 = new Pestania();
	Pestania* pestania2 = new Pestania();
	Pestania* pestania3 = new Pestania();
	Pestania* pestania4 = new Pestania();
	Pestania* pestania5 = new Pestania();
	pestania5->cambiarModoIncognito(true);

	// Crear un objeto Hora para las paginas
	Hora* hora = new Hora();

	// Crear algunas p�ginas de prueba
	Pagina* pagina1 = new Pagina("www.google.com");
	Pagina* pagina2 = new Pagina("www.youtube.com");
	Pagina* pagina3 = new Pagina("www.github.com");
	Pagina* pagina4 = new Pagina("www.crunchyroll.com");
	Pagina* pagina5 = new Pagina("www.crhoy.com");
	Pagina* pagina6 = new Pagina("www.aulavirtual.com");
	Pagina* pagina7 = new Pagina("www.onlyfans.com");
	Pagina* pagina8 = new Pagina("www.netflix.com");
	Pagina* pagina9 = new Pagina("www.instagram.com");
	Pagina* pagina10 = new Pagina("www.twitter.com");

	// Navegar a algunas p�ginas

	pestania1->navegar(pagina1);
	pestania1->navegar(pagina2);
	pestania1->navegar(pagina4);
	pestania1->navegar(pagina8);

	pestania2->navegar(pagina1);
	pestania2->navegar(pagina6);
	pestania2->navegar(pagina9);

	pestania3->navegar(pagina3);
	pestania3->navegar(pagina5);

	pestania4->navegar(pagina5);
	pestania4->navegar(pagina10);
	pestania4->navegar(pagina2);

	pestania5->navegar(pagina1);
	pestania5->navegar(pagina7);

	// Creacion de marcadores.
	Marcador* marcador1 = new Marcador(pagina2, "Entretenimiento");
	Marcador* marcador2 = new Marcador(pagina4, "Entretenimiento");
	Marcador* marcador3 = new Marcador(pagina3, "Educaci�n");
	Marcador* marcador4 = new Marcador(pagina6, "Educaci�n");

	// Guardar marcadores.

	gestorMarcador->agregarMarcador(marcador1);
	gestorMarcador->agregarMarcador(marcador2);
	gestorMarcador->agregarMarcador(marcador3);
	gestorMarcador->agregarMarcador(marcador4);

	// Guardar Pestanias
	gestorPestania->agregarPestania(pestania1);
	gestorPestania->agregarPestania(pestania2);
	gestorPestania->agregarPestania(pestania3);
	gestorPestania->agregarPestania(pestania4);
}

void Navegador::ejecutar()
{
	incializarDatos();

	bool enEjecucion = true; // Controla el ciclo principal del navegador

	while (enEjecucion)
	{
		int opcion = mostrarMenuPrincipal();

		switch (opcion)
		{
		case 1:
		{
			subMenuPestania();
			break;
		}
		case 2:
		{
			cambiarEntrePestanias();
			break;
		}
		case 3:
		{
			subMenuMarcador();
			break;
		}
		case 4:
		{
			mostrarHistorial();
			system("pause");
			break;

		}
		case 5:
		{
			// Importar o exportar historial
			std::string archivo;
			std::cout << "Ingrese el nombre del archivo: ";
			std::cin >> archivo;
			std::cout << "1. Importar\n2. Exportar\nSeleccione: ";
			int opcionArchivo;
			std::cin >> opcionArchivo;

			if (opcionArchivo == 1) {
				importarHistorial(archivo);
			}
			else if (opcionArchivo == 2) {
				exportarHistorial(archivo);
			}
			else {
				std::cout << "Opci�n no v�lida.\n";
			}
			break;
		}
		case 6:
		{
			// Salir
			enEjecucion = false;
			std::cout << "Saliendo del navegador...\n";
			break;
		}
		default:
			std::cout << "Opci�n no v�lida. Intente nuevamente.\n";
		}
	}
}

void Navegador::subMenuPestania()
{
	bool enPestania = true; // Controla el ciclo de la pesta�a actual

	while (enPestania) {
		// Submen� de pesta�as
		int opcionPestania = mostrarMenuPestania();

		switch (opcionPestania)
		{
		case 1:
		{
			// Ingresar direcci�n de sitio web
			Pestania* pestania = new Pestania();
			gestorPestania->agregarPestania(pestania);

			std::string url;
			std::cout << "Ingrese URL: ";
			std::cin >> url;
			navegarA(url);
			break;
		}
		case 2:
		{
			// Avanzar o Retroceder
			navegarEntrePaginas();
			break;
		}
		case 3:
		{
			// Acceder a un marcador
			std::cout << "Lista de marcadores: " << std::endl;
			std::cout << gestorMarcador->toString();

			break;
		}
		case 4:
		{
			// Cambiar a modo incognito
			char opcion;

			std::cout << "Desea cambiar el modo incognito?  (y/n)" << std::endl;
			std::cin >> opcion;

			if (opcion == 'y') {
				gestorPestania->getPestaniaActual()->cambiarModoIncognito(true);
				std::cout << "Se ha cambiado el modo incognito" << std::endl;
				system("pause");
			}
			if (opcion == 'n') {
				std::cout << "Modo actual: ";
				if (gestorPestania->getPestaniaActual()->esIncognito() == true)
				{
					std::cout << "Normal" << std::endl;
					system("pause");
				}
				else if (gestorPestania->getPestaniaActual()->esIncognito() == false)
				{
					std::cout << "Incognito" << std::endl;
					system("pause");
				}
			}
			break;
		}
		case 5:
		{
			// Imprimir historial de la pesta�a
			std::cout << gestorPestania->getPestaniaActual()->mostrarHistorial();
			system("pause");
			break;
		}
		case 6:
		{
			enPestania = false;
			break;
		}
		default:
			std::cout << "Opci�n no v�lida. Regresando al men� principal.\n";
		}
		break;
	}
}

void Navegador::subMenuMarcador()
{
	bool enMarcador = true; // Controla el ciclo del men� de marcadores

	while (enMarcador) {
		// Submen� de marcadores
		int opcionMarcador = mostrarMenuMarcador();

		switch (opcionMarcador)
		{
		case 1:
		{
			// Agregar marcador
			std::string url;
			std::string etiqueta;
			agregarMarcador(url, etiqueta);
			break;
		}
		case 2:
		{
			// Buscar marcador
			std::string etiqueta;
			std::cout << "Ingrese etiqueta del marcador a buscar: ";
			std::cin >> etiqueta;

			std::list<Marcador*> marcadoresFiltrados = gestorMarcador->buscarMarcador(etiqueta);
			for (auto marcador : marcadoresFiltrados) {
				std::cout << marcador->toString() << std::endl;
			}
			system("pause");
			break;
		}
		case 3:
		{
			// Eliminar marcador
			std::string url;
			std::cout << "Ingrese la direccion que desea eliminar de favoritos: ";
			std::cin >> url;
			gestorMarcador->eliminarMarcador(url);
			break;
		}
		case 4:
		{
			// Regresar al men� principal
			enMarcador = false;
			break;
		}
		default:
			std::cout << "Opci�n no v�lida. Regresando al men� principal.\n";
		}
	}
}

int Navegador::mostrarMenuPrincipal()
{
	system("cls");  // Limpiar pantalla

	std::cout << "\n--- Menu Principal ---\n";
	std::cout << "1. Abrir nueva pesta�a\n";
	std::cout << "2. Moverse entre pesta�as\n";
	std::cout << "3. Gestionar marcadores\n";
	std::cout << "4. Mostrar historial general\n";
	std::cout << "5. Importar/Exportar historial\n";
	std::cout << "6. Salir\n";
	

	return EntradaUsuario::obtenerSeleccionInt();
}

int Navegador::mostrarMenuPestania()
{
	system("cls");  // Limpiar pantalla
	
	std::cout << "\n--- Nueva Pesta�a ---\n";
	std::cout << "1. Ingresar direcci�n de sitio web.\n";
	std::cout << "2. Avanzar o Retroceder.\n";
	std::cout << "3. Acceder a un marcador.\n";
	std::cout << "4. Cambiar a modo incognito.\n";
	std::cout << "5. Imprimir historial de la pesta�a.\n";
	std::cout << "6. Regresar al men� principal\n";


	return EntradaUsuario::obtenerSeleccionInt();
}

int Navegador::mostrarMenuMarcador()
{
	system("cls");  // Limpiar pantalla
	
	std::cout << "\n--- Menu Marcador ---\n";
	std::cout << "1. Agregar marcador\n";
	std::cout << "2. Buscar marcador\n";
	std::cout << "3. Eliminar marcador\n";
	std::cout << "4. Regresar al men� principal\n";



	return EntradaUsuario::obtenerSeleccionInt();
}

void Navegador::navegarEntrePaginas()
{
	// Obtener la pesta�a actual desde el gestor de pesta�as
	Pestania* pestaniaActual = gestorPestania->getPestaniaActual();

	if (pestaniaActual == nullptr) {
		std::cout << "No hay ninguna pesta�a abierta actualmente." << std::endl;
		return;
	}

	while (true) {
		// Detecci�n de la tecla flecha izquierda para retroceder
		if (GetAsyncKeyState(VK_LEFT)) {
			pestaniaActual->retroceder();
			system("cls");  // Limpiar pantalla
			std::cout << "Retrocediendo..." << std::endl;
			if (pestaniaActual->getPaginaActual() != nullptr) {
				std::cout << "P�gina actual: " << pestaniaActual->getPaginaActual()->toString() << std::endl;
			}
			else {
				std::cout << "No hay m�s p�ginas para retroceder." << std::endl;
			}
			Sleep(200);
		}

		// Detecci�n de la tecla flecha derecha para avanzar
		if (GetAsyncKeyState(VK_RIGHT)) {
			pestaniaActual->avanzar();
			system("cls");
			std::cout << "Avanzando..." << std::endl;
			if (pestaniaActual->getPaginaActual() != nullptr) {
				std::cout << "P�gina actual: " << pestaniaActual->getPaginaActual()->toString() << std::endl;
			}
			else {
				std::cout << "No hay m�s p�ginas para avanzar." << std::endl;
			}
			Sleep(200);
		}

		// Salir si se presiona ESC
		if (GetAsyncKeyState(VK_ESCAPE)) {
			std::cout << "Saliendo de la navegaci�n..." << std::endl;
			return;
		}

		Sleep(100);
	}
}

void Navegador::cambiarEntrePestanias()
{
	while (true) {
		if (GetAsyncKeyState(VK_UP)) {
			gestorPestania->pestaniaAnterior();
			system("cls");
			std::cout << "Pesta�a anterior seleccionada." << std::endl;
			std::cout << "Pesta�a actual:" << gestorPestania->getPestaniaActual()->getPaginaActual()->getUrl() << std::endl;
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			gestorPestania->proximaPestania();
			system("cls");
			std::cout << "Pesta�a siguiente seleccionada." << std::endl;
			std::cout << "Pesta�a actual:" << gestorPestania->getPestaniaActual()->getPaginaActual()->getUrl() << std::endl;
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			std::cout << "Saliendo de la gesti�n de pesta�as..." << std::endl;
			break;
		}

		Sleep(100);
	}
}


void Navegador::nuevaPestania()
{
	Pestania* nuevaPestania = new Pestania();
	gestorPestania->agregarPestania(nuevaPestania);
	std::cout << "Nueva pesta�a abierta." << std::endl;
}

void Navegador::cerrarPestania()
{
	gestorPestania->cerrarPestania();
	std::cout << "Pesta�a cerrada." << std::endl;
}

void Navegador::navegarA(std::string& url)
{
	Pestania* pestaniaActual = gestorPestania->getPestaniaActual();
	if (pestaniaActual == nullptr) {
		std::cout << "No hay ninguna pesta�a abierta actualmente." << std::endl;
		return;
	}

	Pagina* nuevaPagina = new Pagina(url);
	pestaniaActual->navegar(nuevaPagina);
	std::cout << "Navegando a: " << url << std::endl;
}

void Navegador::cambiarModoIncognito(bool incognito)
{
	Pestania* pestaniaActual = gestorPestania->getPestaniaActual();
	if (pestaniaActual == nullptr) {
		std::cout << "No hay ninguna pesta�a abierta actualmente." << std::endl;
		return;
	}

	pestaniaActual->cambiarModoIncognito(incognito);
	std::cout << "Modo inc�gnito: " << (incognito ? "Activado" : "Desactivado") << std::endl;
}

void Navegador::agregarMarcador(std::string& url, std::string& etiqueta)
{
	std::cout << "Ingrese la direccion de la pagina que desea guardar: " << std::endl;
	std::cin >> url;
	Pagina* paginaMarcador = new Pagina(url);

	std::cout << "Ingrese la etiqueta para el marcador: " << std::endl;
	std::cin >> etiqueta;

	Marcador* marcador = new Marcador(paginaMarcador, etiqueta);

	gestorMarcador->agregarMarcador(marcador);
	std::cout << "Marcador agregado: [" << etiqueta << "] " << url << std::endl;
}

void Navegador::importarHistorial(std::string& archivo)
{

}

void Navegador::exportarHistorial(std::string& archivo)
{
}

void Navegador::importarMarcadores(std::string& archivo)
{
}

void Navegador::exportarMarcadores(std::string& archivo)
{
}

void Navegador::mostrarHistorial() {
	std::list<Pestania*> listaPestanias = gestorPestania->getPestanias();

	if (listaPestanias.empty()) {
		std::cout << "No hay pesta�as abiertas actualmente." << std::endl;
		return;
	}

	std::cout << "Historial: " << std::endl;

	for (Pestania* pestania : listaPestanias) {
		Historial* historialPestania = pestania->getHistorial();

		if (historialPestania != nullptr) {

			std::cout << historialPestania->toString();
		}
		else {
			std::cout << "No hay historial disponible" << std::endl;
		}
	}
}

void Navegador::mostrarMarcadores()
{
	gestorMarcador->toString();
}

void Navegador::mostrarPestanias()
{
}


Navegador::~Navegador()
{
	delete this->gestorPestania;
	delete this->gestorMarcador;
}
