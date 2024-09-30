#include "Interfaz.h"

int Interfaz::mostrarMenuPrincipal(){
system("cls");  // Limpiar pantalla

std::cout << "[-------------------------------]\n";
std::cout << "|        Menu Principal         |\n";
std::cout << "|-------------------------------|\n";
std::cout << "|1. Abrir nueva pestaña         |\n";
std::cout << "|2. Moverse entre pestañas      |\n";
std::cout << "|3. Gestionar marcadores        |\n";
std::cout << "|4. Mostrar historial general   |\n";
std::cout << "|5. Importar/Exportar historial |\n";
std::cout << "|6. Salir                       |\n";
std::cout << "[-------------------------------]\n";

return EntradaUsuario::obtenerSeleccionInt();
}

int Interfaz::mostrarMenuPestania()
{
	system("cls");  // Limpiar pantalla

	std::cout << "[------------------------------------]\n";
	std::cout << "|            Nueva Pestaña           |\n";
	std::cout << "|------------------------------------|\n";
	std::cout << "|1. Ingresar dirección de sitio web. |\n";
	std::cout << "|2. Avanzar o Retroceder.            |\n";
	std::cout << "|3. Acceder a un marcador.           |\n";
	std::cout << "|4. Cambiar a modo incognito.        |\n";
	std::cout << "|5. Imprimir historial de la pestaña.|\n";
	std::cout << "|6. Regresar al menú principal       |\n";
	std::cout << "[------------------------------------]\n";


	return EntradaUsuario::obtenerSeleccionInt();
}

int Interfaz::mostrarMenuMarcador()
{
	system("cls");  // Limpiar pantalla

	std::cout << "[-----------------------------]\n";
	std::cout << "|        Menu Marcador        |\n";
	std::cout << "|-----------------------------|\n";
	std::cout << "|1. Agregar marcador          |\n";
	std::cout << "|2. Buscar marcador           |\n";
	std::cout << "|3. Eliminar marcador         |\n";
	std::cout << "|4. Regresar al menú principal|\n";
	std::cout << "[-----------------------------]\n";



	return EntradaUsuario::obtenerSeleccionInt();
}

void Interfaz::noMasPaginas(){
	std::cout << "No hay más páginas para avanzar." << std::endl;
}

void Interfaz::pagActual(){
	std::cout << "Página actual: " << std::endl;
}

void Interfaz::errorArchivo(){
	std::cout << "Error al abrir el archivo " << std::endl;
}

void Interfaz::noPestaniaAbierta(){
	std::cout << "No hay ninguna pestaña abierta actualmente." << std::endl;
}

void Interfaz::marcadorExp(){
	std::cout << "Marcadores exportados correctamente a ";
}

void Interfaz::marcadorImp()
{
	std::cout << "Marcadores importados correctamente desde ";
}

void Interfaz::historialExp()
{
	std::cout << "Historial exportado correctamente a ";
}

void Interfaz::historialImp()
{
	std::cout << "Historial importado correctamente a ";
}

Pagina* Interfaz::ingresarPagina()
{
	std::string URL;
	std::cout << "Ingrese la direccion de la pagina que desea guardar: " << std::endl;
	std::cin >> URL;
	Pagina* pagina = new Pagina(URL);
	return pagina;
}

std::string Interfaz::ingresarEtiqueta() {
	std::string etiqueta;
	std::cout << "Ingrese la etiqueta para el marcador: " << std::endl;
	std::cin >> etiqueta;
	return etiqueta;
}

