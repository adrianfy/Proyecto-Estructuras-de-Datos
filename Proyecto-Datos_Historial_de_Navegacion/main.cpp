#include <iostream>
#include <string>
#include <vector>
#include "Tab.h"
#include "Buscar.h"
#include "Marcador.h"
#include "GestorDeMarcadores.h"
#include "Pagina.h"

int main() {
    Buscar buscador;
    GestorDeMarcadores gestorDeMarcadores;

    std::string opcion;
    std::string url;
    std::string titulo;
    std::string dominio;
    bool salir = false;

    while (!salir) {
        std::cout << "------ Menu del Navegador ------\n";
        std::cout << "1. Navegar a un sitio web\n";
        std::cout << "2. Retroceder\n";
        std::cout << "3. Avanzar\n";
        std::cout << "4. Cambiar modo de navegacion (Normal/Incognito)\n";
        std::cout << "5. Agregar marcador\n";
        std::cout << "6. Buscar marcador\n";
        std::cout << "7. Cambiar pestaña\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        Tab* pestañaActual = buscador.obtenerPestaniaActual();  // Obtener la pestaña actual

        if (opcion == "1") {
            std::cout << "Ingrese URL del sitio web: ";
            std::cin >> url;
            std::cout << "Ingrese el titulo de la pagina: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Ingrese el dominio del sitio web: ";
            std::cin >> dominio;

            Pagina nuevaPagina(url, dominio);
            if (pestañaActual) {
                pestañaActual->navegar(url);
                std::cout << "Navegando a: " << url << " (" << titulo << ")\n";
            }
            else {
                std::cout << "Error: No se puede navegar, pestaña invalida.\n";
            }
        }
        else if (opcion == "2") {
            if (pestañaActual) {
                pestañaActual->retroceder();
                std::cout << "Retrocediendo a: " << pestañaActual->getUrlActual() << "\n";
            }
        }
        else if (opcion == "3") {
            if (pestañaActual) {
                pestañaActual->avanzar();
                std::cout << "Avanzando a: " << pestañaActual->getUrlActual() << "\n";
            }
        }
        else if (opcion == "4") {
            buscador.CambiarModo();
            std::cout << "Modo de navegacion cambiado.\n";
        }
        else if (opcion == "5") {
            std::vector<std::string> etiquetas;
            std::string etiqueta;
            std::cout << "Ingrese una etiqueta para el marcador (Ingrese 'fin' para terminar): ";
            while (etiqueta != "fin") {
                std::cin >> etiqueta;
                if (etiqueta != "fin")
                    etiquetas.push_back(etiqueta);
            }
            Pagina paginaMarcada(url, dominio);
            Marcador* nuevoMarcador = new Marcador(&paginaMarcada, etiquetas);
            gestorDeMarcadores.agregarMarcador(nuevoMarcador);
            std::cout << "Marcador agregado: " << url << "\n";
        }
        else if (opcion == "6") {
            std::string etiquetaBusqueda;
            std::cout << "Ingrese la etiqueta que desea buscar: ";
            std::cin >> etiquetaBusqueda;
            std::vector<Marcador*> resultados = gestorDeMarcadores.buscarMarcador(etiquetaBusqueda);
            if (!resultados.empty()) {
                std::cout << "Marcadores encontrados:\n";
                for (Marcador* marcador : resultados) {
                    std::cout << marcador->getPagina()->getUrl() << " - " << marcador->getPagina()->getDominio() << "\n";
                }
            }
            else {
                std::cout << "No se encontraron marcadores con esa etiqueta.\n";
            }
        }
        else if (opcion == "7") {
            int nuevaPestania;
            std::cout << "Ingrese el numero de pestaña: ";
            std::cin >> nuevaPestania;
            buscador.CambiarPestania(nuevaPestania);
        }
        else if (opcion == "8") {
            salir = true;
        }
        else {
            std::cout << "Opcion no valida, intente de nuevo.\n";
        }
    }

    return 0;
}
