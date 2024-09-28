#include <iostream>
#include "GestorPestania.h"

int main() {
    // Crear una pesta�a para pruebas
    Pestania pestania;

    // Crear un objeto Hora para las paginas
    Hora* hora = new Hora();
    std::cout << "Hora actual: " << hora->toString() << std::endl;

    // Crear algunas p�ginas de prueba
    Pagina* pagina1 = new Pagina("www.google.com");
    Pagina* pagina2 = new Pagina("www.openai.com");
    Pagina* pagina3 = new Pagina("www.github.com");

    // Navegar a algunas p�ginas
    pestania.navegar(pagina1);
    std::cout << "P�gina actual: " << pestania.getPaginaActual()->toString() << std::endl;

    pestania.navegar(pagina2);
    std::cout << "P�gina actual: " << pestania.getPaginaActual()->toString() << std::endl;

    pestania.navegar(pagina3);
    std::cout << "P�gina actual: " << pestania.getPaginaActual()->toString() << std::endl;

    // Retroceder en el historial
    pestania.retroceder();
    if (pestania.getPaginaActual() != nullptr) {
        std::cout << "P�gina actual despu�s de retroceder: " << pestania.getPaginaActual()->toString() << std::endl;
    }
    else {
        std::cout << "No hay m�s p�ginas para retroceder.\n";
    }

    pestania.retroceder();
    if (pestania.getPaginaActual() != nullptr) {
        std::cout << "P�gina actual despu�s de retroceder: " << pestania.getPaginaActual()->toString() << std::endl;
    }
    else {
        std::cout << "No hay m�s p�ginas para retroceder.\n";
    }

    // Avanzar en el historial
    pestania.avanzar();
    if (pestania.getPaginaActual() != nullptr) {
        std::cout << "P�gina actual despu�s de avanzar: " << pestania.getPaginaActual()->toString() << std::endl;
    }
    else {
        std::cout << "No hay m�s p�ginas para avanzar.\n";
    }

    // Mostrar historial completo
    std::cout << "\nHistorial completo:\n" << pestania.mostrarHistorial() << std::endl;

    // Crear la lista de pesta�as (tabs)
    GestorPestania listaDePestanias;

    // Crear algunas pesta�as y navegar a las p�ginas previamente creadas
    Pestania* tab1 = new Pestania();
    tab1->navegar(pagina1);
    listaDePestanias.agregarPestania(tab1);

    Pestania* tab2 = new Pestania();
    tab2->navegar(pagina2);
    listaDePestanias.agregarPestania(tab2);

    Pestania* tab3 = new Pestania();
    tab3->navegar(pagina3);
    listaDePestanias.agregarPestania(tab3);

    // Mostrar las pesta�as actuales
    std::cout << "Lista de pesta�as:\n";
    std::cout << listaDePestanias.mostrarTabs() << std::endl;

    // Navegar entre pesta�as
    listaDePestanias.proximaPestania();
    std::cout << "Pesta�a actual despu�s de avanzar:\n";
    std::cout << listaDePestanias.mostrarTabs() << std::endl;

    listaDePestanias.pestaniaAnterior();
    std::cout << "Pesta�a actual despu�s de retroceder:\n";
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