#include "Navegador.h"
#include <iostream>

Navegador::Navegador() {
    this->gestorPestania = new GestorPestania();
	this->gestorMarcador = new GestorMarcador();
}

void Navegador::ejecutar()
{
    bool enEjecucion = true; // Controla el ciclo principal del navegador

    while (enEjecucion)
    {
        int opcion = mostrarMenuPrincipal();

        switch (opcion)
        {
        case 1:
        {
            // Submenú de pestañas
            int opcionPestania = mostrarMenuPestania();

            switch (opcionPestania)
            {
            case 1:
            {
                // Navegar a una pagina web
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
                // Moverse entre paginas de la pestaña
				navegarEntrePaginas();
                break;
            }
            case 3:
            {
                // Imprimir historial de la pestaña
                mostrarHistorial();
                break;
            }
            case 4:
            {
                // Acceder a un marcador desde la pestaña
                std::string etiqueta;
                std::cout << "Ingrese etiqueta del marcador: ";
                std::cin >> etiqueta;
                buscarMarcadores(etiqueta);
                break;
            }
            case 5:
            {
                // Regresar al menú principal
                break;
            }
            default:
                std::cout << "Opción no válida. Regresando al menú principal.\n";
            }
            break;
        }
        case 2:
        {
            // Mostrar historial general
            mostrarHistorial();
            break;
        }
        case 3:
        {
            // Cambiar modo incógnito
            bool incognito;
            std::cout << "Ingrese 1 para activar/incógnito, 0 para desactivar: ";
            std::cin >> incognito;
            cambiarModoIncognito(incognito);
            break;
        }
        case 4:
        {
            // Gestionar marcadores: buscar, agregar, o mostrar marcadores
            std::string etiqueta;
            std::cout << "Ingrese etiqueta del marcador a buscar: ";
            std::cin >> etiqueta;
            buscarMarcadores(etiqueta);
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
                std::cout << "Opción no válida.\n";
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
            std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    }
}

int Navegador::mostrarMenuPrincipal()
{
	system("cls");  // Limpiar pantalla
    int opcion;
    std::cout << "\n--- Menu Principal ---\n";
    std::cout << "1. Ingresar a pestañas\n";
    std::cout << "2. Mostrar historial general\n";
    std::cout << "3. Cambiar modo incógnito\n";
    std::cout << "4. Gestionar marcadores\n";
    std::cout << "5. Importar/Exportar historial\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;

    return opcion;
}

int Navegador::mostrarMenuPestania()
{
	system("cls");  // Limpiar pantalla
    int opcion;
    std::cout << "\n--- Menu de Pestaña ---\n";
    std::cout << "1. Navegar a una página web\n";
    std::cout << "2. Moverse entre páginas de la pestaña\n";
    std::cout << "3. Imprimir historial de la pestaña\n";
    std::cout << "4. Acceder a un marcador\n";
    std::cout << "5. Regresar al menú principal\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;

    return opcion;
}

void Navegador::navegarEntrePaginas()
{
    // Obtener la pestaña actual desde el gestor de pestañas
    Pestania* pestaniaActual = gestorPestania->getPestaniaActual();

    if (pestaniaActual == nullptr) {
        std::cout << "No hay ninguna pestaña abierta actualmente." << std::endl;
        return;
    }

    while (true) {
        // Detección de la tecla flecha izquierda para retroceder
        if (GetAsyncKeyState(VK_LEFT)) {
            pestaniaActual->retroceder();
            system("cls");  // Limpiar pantalla
            std::cout << "Retrocediendo..." << std::endl;
            if (pestaniaActual->getPaginaActual() != nullptr) {
                std::cout << "Página actual: " << pestaniaActual->getPaginaActual()->toString() << std::endl;
            }
            else {
                std::cout << "No hay más páginas para retroceder." << std::endl;
            }
            Sleep(200);
        }

        // Detección de la tecla flecha derecha para avanzar
        if (GetAsyncKeyState(VK_RIGHT)) {
            pestaniaActual->avanzar();
            system("cls");
            std::cout << "Avanzando..." << std::endl;
            if (pestaniaActual->getPaginaActual() != nullptr) {
                std::cout << "Página actual: " << pestaniaActual->getPaginaActual()->toString() << std::endl;
            }
            else {
                std::cout << "No hay más páginas para avanzar." << std::endl;
            }
            Sleep(200);
        }

        // Salir si se presiona ESC
        if (GetAsyncKeyState(VK_ESCAPE)) {
            std::cout << "Saliendo de la navegación..." << std::endl;
            break;
        }

        Sleep(100);
    }
}

void Navegador::cambiarEntrePestanias()
{
    while (true) {
        if (GetAsyncKeyState(VK_UP)) {
            gestorPestania->pestaniaAnterior();
            std::cout << "Pestaña anterior seleccionada." << std::endl;
            Sleep(200);
        }

        if (GetAsyncKeyState(VK_DOWN)) {
            gestorPestania->proximaPestania();
            std::cout << "Pestaña siguiente seleccionada." << std::endl;
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

void Navegador::navegarA(std::string& url)
{
	Pestania* pestaniaActual = gestorPestania->getPestaniaActual();
	if (pestaniaActual == nullptr) {
		std::cout << "No hay ninguna pestaña abierta actualmente." << std::endl;
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
		std::cout << "No hay ninguna pestaña abierta actualmente." << std::endl;
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

void Navegador::buscarMarcadores(std::string& etiqueta)
{

}

void Navegador::filtrarMarcadores(std::string& etiqueta)
{
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

void Navegador::mostrarHistorial()
{
	gestorPestania->mostrarTabs();
}

void Navegador::mostrarMarcadores()
{
}

void Navegador::mostrarPestanias()
{
}

void Navegador::manejarInputUsuario()
{
}



Navegador::~Navegador()
{
    delete this->gestorPestania;
	delete this->gestorMarcador;
}
