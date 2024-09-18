#include "GestorPestania.h"

GestorPestania::GestorPestania()
{
    pestaniaActual = listaPestanias.end();
}

void GestorPestania::agregarPestania(Pestania* pestania)
{
    listaPestanias.push_back(pestania);
    if (pestaniaActual == listaPestanias.end()) {
        pestaniaActual = std::prev(listaPestanias.end());
    }
}

void GestorPestania::cerrarPestania()
{
    if (listaPestanias.empty()) return;

    auto it = pestaniaActual;
    if (it != listaPestanias.end()) {
        it = listaPestanias.erase(it);
        if (it == listaPestanias.end() && !listaPestanias.empty()) {
            pestaniaActual = std::prev(listaPestanias.end());
        }
    }
}

void GestorPestania::proximaPestania()
{
    if (pestaniaActual != listaPestanias.end() && std::next(pestaniaActual) != listaPestanias.end()) {
        ++pestaniaActual;
    }
    else {
        std::cout << "No hay más pestañas abiertas." << std::endl;
    }
}

void GestorPestania::pestaniaAnterior()
{
    if (pestaniaActual != listaPestanias.begin()) {
        --pestaniaActual;
    }
    else {
        std::cout << "No hay pestañas anteriores." << std::endl;
    }
}

Pestania* GestorPestania::getPestaniaActual()
{
    return *pestaniaActual;
}

std::string GestorPestania::mostrarTabs()
{
    std::stringstream ss;
    int contador = 1;

    for (auto it = listaPestanias.begin(); it != listaPestanias.end(); ++it) {
        if (it == pestaniaActual) {
            ss << "-> Pestaña " << contador << " (Actual): " << (*it)->getPaginaActual()->toString() << std::endl;
        }
        else {
            ss << "Pestaña " << contador << ": " << (*it)->getPaginaActual()->toString() << std::endl;
        }
        ++contador;
    }

    return ss.str();
}

GestorPestania::~GestorPestania()
{
    for (Pestania* pestania : listaPestanias) {
        delete pestania;
    }
    listaPestanias.clear();
}
