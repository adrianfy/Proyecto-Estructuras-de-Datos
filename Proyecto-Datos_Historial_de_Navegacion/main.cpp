#include <iostream>
#include "GestorPestania.h"

int main() {
    // Crear una pestaña para pruebas
    Pestania pestania;

    // Crear un objeto Hora para las paginas
    Hora* hora = new Hora();
    std::cout << "Hora actual: " << hora->toString() << std::endl;

    // Crear algunas páginas de prueba
    Pagina* pagina1 = new Pagina("www.google.com");
    Pagina* pagina2 = new Pagina("www.openai.com");
    Pagina* pagina3 = new Pagina("www.github.com");

    // Navegar a algunas páginas
    pestania.navegar(pagina1);
    std::cout << "Página actual: " << pestania.getPaginaActual()->toString() << std::endl;

    pestania.navegar(pagina2);
    std::cout << "Página actual: " << pestania.getPaginaActual()->toString() << std::endl;

    pestania.navegar(pagina3);
    std::cout << "Página actual: " << pestania.getPaginaActual()->toString() << std::endl;

    // Retroceder en el historial
    pestania.retroceder();
    if (pestania.getPaginaActual() != nullptr) {
        std::cout << "Página actual después de retroceder: " << pestania.getPaginaActual()->toString() << std::endl;
    }
    else {
        std::cout << "No hay más páginas para retroceder.\n";
    }

    pestania.retroceder();
    if (pestania.getPaginaActual() != nullptr) {
        std::cout << "Página actual después de retroceder: " << pestania.getPaginaActual()->toString() << std::endl;
    }
    else {
        std::cout << "No hay más páginas para retroceder.\n";
    }

    // Avanzar en el historial
    pestania.avanzar();
    if (pestania.getPaginaActual() != nullptr) {
        std::cout << "Página actual después de avanzar: " << pestania.getPaginaActual()->toString() << std::endl;
    }
    else {
        std::cout << "No hay más páginas para avanzar.\n";
    }

    // Mostrar historial completo
    std::cout << "\nHistorial completo:\n" << pestania.mostrarHistorial() << std::endl;

    // Crear la lista de pestañas (tabs)
    GestorPestania listaDePestanias;

    // Crear algunas pestañas y navegar a las páginas previamente creadas
    Pestania* tab1 = new Pestania();
    tab1->navegar(pagina1);
    listaDePestanias.agregarPestania(tab1);

    Pestania* tab2 = new Pestania();
    tab2->navegar(pagina2);
    listaDePestanias.agregarPestania(tab2);

    Pestania* tab3 = new Pestania();
    tab3->navegar(pagina3);
    listaDePestanias.agregarPestania(tab3);

    // Mostrar las pestañas actuales
    std::cout << "Lista de pestañas:\n";
    std::cout << listaDePestanias.mostrarTabs() << std::endl;

    // Navegar entre pestañas
    listaDePestanias.proximaPestania();
    std::cout << "Pestaña actual después de avanzar:\n";
    std::cout << listaDePestanias.mostrarTabs() << std::endl;

    listaDePestanias.pestaniaAnterior();
    std::cout << "Pestaña actual después de retroceder:\n";
    std::cout << listaDePestanias.mostrarTabs() << std::endl;


    // Filtrado de palabras
    std::cout << "Filtrando palabra Goo... :\n";
    std::string palabra = "Goo";

    std::vector<Pagina*> resultados = pestania.getHistorial()->filtrarPorPalabra(palabra);
    for (Pagina* pagina : resultados) {
        std::cout << pagina->toString() << std::endl;
    }

    return 0;
}