#include "Navegador.h"
#include <iostream>

Navegador::Navegador() {
	this->gestorPestania = new GestorPestania();
	this->gestorMarcador = new GestorMarcador();
	this->sesion = new Sesion();
	this->interfaz = new Interfaz();
}

Navegador::Navegador(Interfaz* interfaz){
    this->gestorPestania = new GestorPestania();
	this->gestorMarcador = new GestorMarcador();
	this->sesion = new Sesion();
	this->interfaz = interfaz;
}

void Navegador::incializarDatos()
{
	// Crear una pestaña para pruebas

	Pestania* pestania1 = new Pestania();
	Pestania* pestania2 = new Pestania();
	Pestania* pestania3 = new Pestania();
	Pestania* pestania4 = new Pestania();
	Pestania* pestania5 = new Pestania();
	pestania5->cambiarModoIncognito(true);

	// Crear un objeto Hora para las paginas
	Hora* hora = new Hora();

	// Crear algunas páginas de prueba
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

	// Navegar a algunas páginas

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
	Marcador* marcador3 = new Marcador(pagina3, "Educación");
	Marcador* marcador4 = new Marcador(pagina6, "Educación");

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
	gestorPestania->agregarPestania(pestania5);
}

void Navegador::ejecutar()
{

	sesion->cargarSesion(gestorPestania, gestorMarcador);
	incializarDatos();

	bool enEjecucion = true; // Controla el ciclo principal del navegador

	while (enEjecucion)
	{
		int opcion = interfaz->mostrarMenuPrincipal();

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
			filtrarHistorial();
			system("pause");
			break;
		}
		case 6:
		{
			// Importar o exportar historial
			//std::string archivo;
			//std::cout << "Ingrese el nombre del archivo: ";
			//std::cin >> archivo;
			std::cout << "1. Importar\n2. Exportar\nSeleccione: ";
			int opcionArchivo;
			std::cin >> opcionArchivo;

			if (opcionArchivo == 1) {
				importarHistorial();
				std::cout << "Historial importado de: historialPestania.bin" << std::endl;
				system("pause");
			}
			else if (opcionArchivo == 2) {
				exportarHistorial();
				std::cout << "Historial exportado a: historialPestania.bin" << std::endl;
				system("pause");
			}
			else {
				interfaz->opcionNoValida();
			}
			break;
		}
		case 7:
		{
			// Salir
			enEjecucion = false;
			std::cout << "Saliendo del navegador...\n";
			break;
		}
		default:
			interfaz->opcionNoValida();
		}
	}
	sesion->guardarSesion(gestorPestania, gestorMarcador);
}

void Navegador::subMenuPestania()
{
	bool enPestania = true; // Controla el ciclo de la pestaña actual

	while (enPestania) {
		// Submenú de pestañas
		int opcionPestania = mostrarMenuPestania();

		switch (opcionPestania)
		{
		case 1:
		{
			// Ingresar dirección de sitio web
			if (gestorPestania->getPestaniaActual() == nullptr) {
				Pestania* pestania = new Pestania();
				gestorPestania->agregarPestania(pestania);
			}

			std::string url;
			std::cout << "Ingrese URL: ";
			std::cin >> url;

			navegarA(url);
			system("pause");
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
			Marcador* marcadorSeleccionado = seleccionarMarcador();
			Pagina* paginaFavorita = marcadorSeleccionado->getPagina();
			gestorPestania->getPestaniaActual()->navegar(paginaFavorita);

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
				if (gestorPestania->getPestaniaActual()->esIncognito() == false)
				{
					std::cout << "Normal" << std::endl;
					system("pause");
				}
				else if (gestorPestania->getPestaniaActual()->esIncognito() == true)
				{
					std::cout << "Incognito" << std::endl;
					system("pause");
				}
			}
			break;
		}
		case 5:
		{
			// Imprimir historial de la pestaña
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
			interfaz->opcionNoValida();
		}
		break;
	}
}

void Navegador::subMenuMarcador()
{
	bool enMarcador = true; // Controla el ciclo del menú de marcadores

	while (enMarcador) {
		// Submenú de marcadores
		int opcionMarcador = interfaz->mostrarMenuMarcador();

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
			 // Mostrar Marcadores
			mostrarMarcadores();
		}
		case 5:
		{
			// Regresar al menú principal
			enMarcador = false;
			break;
		}
		default:
			interfaz->opcionNoValida();
		}
	}
}



int Navegador::mostrarMenuPestania()
{
	system("cls");  // Limpiar pantalla

	std::cout << "[------------------------------------------------]\n";
	if (gestorPestania && gestorPestania->getPestaniaActual()) {
		std::cout << "\033[1;32m    Actualmente en la pagina:\033[0m " << gestorPestania->getPestaniaActual()->getPaginaActual()->getUrl() << "   \n";
	}
	else {
		std::cerr << "               Buscando una pagina...\n";
	}

	
	std::cout << "|------------------------------------------------|\n";
	std::cout << "|      1. Ingresar dirección de sitio web.       |\n";
	std::cout << "|      2. Avanzar o Retroceder.                  |\n";
	std::cout << "|      3. Acceder a un marcador.                 |\n";
	std::cout << "|      4. Cambiar a modo incognito.              |\n";
	std::cout << "|      5. Imprimir historial de la pestaña.      |\n";
	std::cout << "|      6. Regresar al menú principal             |\n";
	std::cout << "[------------------------------------------------]\n";


	return EntradaUsuario::obtenerSeleccionInt();
}


void Navegador::navegarEntrePaginas()
{
	// Obtener la pestaña actual desde el gestor de pestañas
	Pestania* pestaniaActual = gestorPestania->getPestaniaActual();

	interfaz->asistentePaginas();

	if (pestaniaActual == nullptr) {
		interfaz->noPestaniaAbierta();
		return;
	}

	while (true) {
		// Detección de la tecla flecha izquierda para retroceder
		if (GetAsyncKeyState(VK_LEFT)) {
			pestaniaActual->retroceder();

			interfaz->asistentePaginas();

			std::cout << "Retrocediendo..." << std::endl;
			if (pestaniaActual->getPaginaActual() != nullptr) {
				std::cout << "Página actual: " << pestaniaActual->getPaginaActual()->toString() << std::endl;
			}
			else {
				interfaz->error404();
			}
			Sleep(200);
		}

		// Detección de la tecla flecha derecha para avanzar
		if (GetAsyncKeyState(VK_RIGHT)) {
			pestaniaActual->avanzar();

			interfaz->asistentePaginas();

			std::cout << "Avanzando..." << std::endl;
			if (pestaniaActual->getPaginaActual() != nullptr) {
				std::cout << "Página actual: " << pestaniaActual->getPaginaActual()->toString() << std::endl;
			}
			else {
				interfaz->error404();
			}
			Sleep(200);
		}

		// Salir si se presiona ESC
		if (GetAsyncKeyState(VK_ESCAPE)) {
			std::cout << "Saliendo de la navegación..." << std::endl;
			return;
		}

		Sleep(100);
	}
}

void Navegador::cambiarEntrePestanias()
{
	interfaz->asistentePestanias();

	while (true) {
		if (GetAsyncKeyState(VK_UP)) {
			gestorPestania->pestaniaAnterior();

			interfaz->asistentePestanias();

			std::cout << "Pestaña anterior seleccionada." << std::endl;
			std::cout << "Pestaña actual:" << gestorPestania->getPestaniaActual()->getPaginaActual()->getUrl() << std::endl;
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			gestorPestania->proximaPestania();

			interfaz->asistentePestanias();

			std::cout << "Pestaña siguiente seleccionada." << std::endl;
			std::cout << "Pestaña actual:" << gestorPestania->getPestaniaActual()->getPaginaActual()->getUrl() << std::endl;
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			std::cout << "Saliendo de la gestión de pestañas..." << std::endl;
			break;
		}

		Sleep(100);
	}
}


void Navegador::nuevaPestania()
{
	Pestania* nuevaPestania = new Pestania();
	gestorPestania->agregarPestania(nuevaPestania);
	std::cout << "Nueva pestaña abierta." << std::endl;
}

void Navegador::cerrarPestania()
{
	gestorPestania->cerrarPestania();
	std::cout << "Pestaña cerrada." << std::endl;
}

void Navegador::filtrarHistorial()
{
	std::string palabra;  // La palabra clave que quieres filtrar
	std::cout << "Ingrese la palabra clave que desea buscar: " << std::endl;
	std::cin >> palabra;
	
	std::list<Pestania*> listaPestanias = gestorPestania->getPestanias();

	if (listaPestanias.empty()) {
		interfaz->noPestaniaAbierta();
		return;
	}

	std::cout << "Resultados de la búsqueda: " << std::endl;

	for (Pestania* pestania : listaPestanias) {
		Historial* historialPestania = pestania->getHistorial();

		if (historialPestania != nullptr) {
			std::vector<Pagina*> resultados = historialPestania->filtrarPorPalabra(palabra);

			if (!resultados.empty()) {
				for (Pagina* pagina : resultados) {
					std::cout << pagina->mostrarEnHistorial() << std::endl;
				}
			}
		}
		else {
			std::cout << "No hay historial disponible" << std::endl;
		}
	}

}

void Navegador::navegarA(std::string& url)
{
	Pestania* pestaniaActual = gestorPestania->getPestaniaActual();
	if (pestaniaActual == nullptr) {
		interfaz->noPestaniaAbierta();
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
		interfaz->noPestaniaAbierta();
		return;
	}

	pestaniaActual->cambiarModoIncognito(incognito);
	std::cout << "Modo incógnito: " << (incognito ? "Activado" : "Desactivado") << std::endl;
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

Marcador* Navegador::seleccionarMarcador()
{
	// Obtener la referencia a la lista de marcadores
	auto& marcadores = gestorMarcador->getMarcadores();

	if (marcadores.empty()) {
		std::cout << "No hay marcadores disponibles." << std::endl;
		return nullptr;
	}

	// Mostrar los marcadores con índices
	int indice = 0;
	for (auto marcador : marcadores) {
		std::cout << indice << ": " << marcador->toString() << std::endl;
		++indice;
	}

	// Solicitar selección al usuario
	std::cout << "Seleccione el número del marcador que desea abrir: ";
	int seleccion = EntradaUsuario::obtenerSeleccionInt();

	// Validar la selección
	if (seleccion < 0 || seleccion >= static_cast<int>(marcadores.size())) {
		interfaz->opcionNoValida();
		return nullptr;
	}

	// Avanzar el iterador hasta la posición seleccionada
	auto it = marcadores.begin();
	std::advance(it, seleccion);

	return *it;
}


void Navegador::importarHistorial()
{
	std::ifstream file("historialPestania.bin");

	if (!file.is_open()) {
		interfaz->errorArchivo();
		return;
	}

	std::string url;
	while (getline(file, url)) {
		if (!url.empty()) {
			Pagina* pagina = new Pagina(url);
			if (gestorPestania->getPestaniaActual() == nullptr)
			{
				Pestania* pestania = new Pestania();
				gestorPestania->agregarPestania(pestania);
			}
			Pestania* pestaniaActual = gestorPestania->getPestaniaActual();
			if (pestaniaActual) {
				pestaniaActual->navegar(pagina);
			}
			else {
				std::cout << "No hay pestaña activa para importar el historial." << std::endl;
			}
		}
	}

	file.close();
	interfaz->historialImp();	
}

void Navegador::exportarHistorial()
{
	std::ofstream outputFile("historialPestania.bin");

	if (!outputFile.is_open()) {
		interfaz->errorArchivo();
		return;
	}

	std::list<Pestania*> listaPestanias = gestorPestania->getPestanias();
	for (Pestania* pestania : listaPestanias) {
		Historial* historial = pestania->getHistorial();
		if (historial) {
			std::vector<std::string> paginas = historial->getPaginas();
			for (const std::string& pagina : paginas) {
				outputFile << pagina << std::endl;
			}
		}
	}

	outputFile.close();
	interfaz->historialExp();
}

void Navegador::importarMarcadores(std::string& archivo)
{
	std::ifstream file(archivo);

	if (!file.is_open()) {
		interfaz->errorArchivo();
		return;
	}

	std::string linea;
	while (getline(file, linea)) {
		std::stringstream ss(linea);
		std::string url, etiqueta;

		ss >> url >> etiqueta;

		Pagina* pagina = new Pagina(url);
		Marcador* marcador = new Marcador(pagina, etiqueta);
		gestorMarcador->agregarMarcador(marcador);
	}

	file.close();
	interfaz->marcadorImp();
}

void Navegador::exportarMarcadores(std::string& archivo)
{
	std::ofstream file(archivo);

	if (!file.is_open()) {
		interfaz->errorArchivo();
		return;
	}

	std::list<Marcador*> listaMarcadores = gestorMarcador->getMarcadores();
	for (Marcador* marcador : listaMarcadores) {
		file << marcador->getPagina()->getUrl() << " " << marcador->getEtiqueta() << std::endl;
	}

	file.close();
	interfaz->marcadorExp();
}

void Navegador::mostrarHistorial() {
	std::list<Pestania*> listaPestanias = gestorPestania->getPestanias();

	if (listaPestanias.empty()) {
		interfaz->noPestaniaAbierta();
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
	std::cout << gestorMarcador->toString();
}

void Navegador::mostrarPestanias()
{
	std::cout << gestorPestania->mostrarTabs();
}


Navegador::~Navegador()
{
	delete this->gestorPestania;
	delete this->gestorMarcador;
}
