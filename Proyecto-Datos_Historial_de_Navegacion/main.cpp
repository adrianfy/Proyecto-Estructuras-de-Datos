#include <iostream>
#include "Navegador.h"

//Esto tambien nos lo dio la IA
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


int main() {

    setlocale(LC_ALL, "spanish");

	Navegador* navegador = new Navegador();
	navegador->ejecutar();


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  //Usamos esto para comprobar si existen memory leaks, codigo sacado por IA.


	//Sesion* sesion = new Sesion();

	//// Crear la lista de pestañas (tabs) y el gestor de marcadores
 //   GestorPestania* listaDePestanias = new GestorPestania();

 //   GestorMarcador* gestorMarcadores = new GestorMarcador();

	//sesion->cargarSesion(listaDePestanias, gestorMarcadores);

 //   // Crear una pestaña para pruebas
 //   Pestania* pestania = new Pestania();

 //   // Crear un objeto Hora para las paginas
 //   Hora* hora = new Hora();
 //   std::cout << "Hora actual: " << hora->toString() << std::endl;

 //   // Crear algunas páginas de prueba
 //   Pagina* pagina1 = new Pagina("www.google.com");
 //   Pagina* pagina2 = new Pagina("www.youtube.com");
 //   Pagina* pagina3 = new Pagina("www.github.com");
 //   Pagina* pagina4 = new Pagina("www.crunchyroll.com");
 //   Pagina* pagina5 = new Pagina("www.crhoy.com");
 //   Pagina* pagina6 = new Pagina("www.aulavirtual.com");
	//Pagina* pagina7 = new Pagina("www.onlyfans.com");

 //   // Navegar a algunas páginas
 //   pestania->navegar(pagina1);
 //   std::cout << "Página actual: " << pestania->getPaginaActual()->toString() << std::endl;

 //   pestania->navegar(pagina2);
 //   std::cout << "Página actual: " << pestania->getPaginaActual()->toString() << std::endl;

 //   pestania->navegar(pagina3);
 //   std::cout << "Página actual: " << pestania->getPaginaActual()->toString() << std::endl;

 //   pestania->navegar(pagina4);
 //   std::cout << "Página actual: " << pestania->getPaginaActual()->toString() << std::endl;

 //   pestania->navegar(pagina5);
 //   std::cout << "Página actual: " << pestania->getPaginaActual()->toString() << std::endl;

 //   pestania->navegar(pagina6);
 //   std::cout << "Página actual: " << pestania->getPaginaActual()->toString() << std::endl;

 //   // Retroceder en el historial
 //   pestania->retroceder();
 //   if (pestania->getPaginaActual() != nullptr) {
 //       std::cout << "Página actual después de retroceder: " << pestania->getPaginaActual()->toString() << std::endl;
 //   }
 //   else {
 //       std::cout << "No hay más páginas para retroceder.\n";
 //   }

 //   pestania->retroceder();
 //   if (pestania->getPaginaActual() != nullptr) {
 //       std::cout << "Página actual después de retroceder: " << pestania->getPaginaActual()->toString() << std::endl;
 //   }
 //   else {
 //       std::cout << "No hay más páginas para retroceder.\n";
 //   }

 //   // Avanzar en el historial
 //   pestania->avanzar();
 //   if (pestania->getPaginaActual() != nullptr) {
 //       std::cout << "Página actual después de avanzar: " << pestania->getPaginaActual()->toString() << std::endl;
 //   }
 //   else {
 //       std::cout << "No hay más páginas para avanzar.\n";
 //   }

 //   // Mostrar historial completo
 //   std::cout << "\nHistorial completo:\n" << pestania->mostrarHistorial() << std::endl;



 //   std::cout << "Creacion de marcadores:" << std::endl;
	//Marcador* marcador1 = new Marcador(pagina2, "Entretenimiento");
	//Marcador* marcador2 = new Marcador(pagina4, "Entretenimiento");
	//Marcador* marcador3 = new Marcador(pagina3, "Educación");
	//Marcador* marcador4 = new Marcador(pagina6, "Educación");

	//gestorMarcadores->agregarMarcador(marcador1);
	//gestorMarcadores->agregarMarcador(marcador2);
	//gestorMarcadores->agregarMarcador(marcador3);
	//gestorMarcadores->agregarMarcador(marcador4);

 //   std::cout << gestorMarcadores->toString();
 //   
 //   std::cout << "Filtrar marcadores de Entretenimiento:\n";
	//std::string etiqueta = "Entretenimiento";
	//std::list<Marcador*> marcadoresFiltrados = gestorMarcadores->buscarMarcador(etiqueta);
	//for (auto marcador : marcadoresFiltrados) {
	//	std::cout << marcador->toString() << std::endl;
	//}

 //   // Crear algunas pestañas y navegar a las páginas previamente creadas
 //   Pestania* tab1 = new Pestania();
 //   tab1->navegar(pagina1);
 //   listaDePestanias->agregarPestania(tab1);

 //   Pestania* tab2 = new Pestania();
 //   tab2->navegar(pagina2);
 //   listaDePestanias->agregarPestania(tab2);

 //   Pestania* tab3 = new Pestania();
 //   tab3->navegar(pagina3);
 //   listaDePestanias->agregarPestania(tab3);

	//Pestania* tab4 = new Pestania();
 //   tab4->cambiarModoIncognito(true);
	//tab4->navegar(pagina7);
	//listaDePestanias->agregarPestania(tab4);

 //   // Mostrar las pestañas actuales
 //   std::cout << "Lista de pestañas:\n";
 //   std::cout << listaDePestanias->mostrarTabs() << std::endl;

 //   // Navegar entre pestañas
 //   listaDePestanias->proximaPestania();
 //   std::cout << "Pestaña actual después de avanzar:\n";
 //   std::cout << listaDePestanias->mostrarTabs() << std::endl;

 //   listaDePestanias->pestaniaAnterior();
 //   std::cout << "Pestaña actual después de retroceder:\n";
 //   std::cout << listaDePestanias->mostrarTabs() << std::endl;


 //   // Filtrado de palabras
 //   std::cout << "Filtrando palabra cr... :\n";
 //   std::string palabra = "cr";

 //   std::vector<Pagina*> resultados = pestania->getHistorial()->filtrarPorPalabra(palabra);
 //   for (Pagina* pagina : resultados) {
 //       std::cout << pagina->mostrarEnHistorial() << std::endl;
 //   }

 //   std::cout << "\nHistorial completo:\n" << tab4->mostrarHistorial() << std::endl;

	//sesion->guardarSesion(listaDePestanias, gestorMarcadores);

	//// Eliminar objetos
	//delete pestania;
	//delete pagina1;
	//delete pagina2;
	//delete pagina3;
	//delete pagina4;
	//delete pagina5;
	//delete pagina6;
	//delete pagina7;
	//delete hora;
	//delete marcador1;
	//delete marcador2;
	//delete marcador3;
	//delete marcador4;
	//delete tab1;
	//delete tab2;
	//delete tab3;
	//delete tab4;
	//delete sesion;

    return 0;
}