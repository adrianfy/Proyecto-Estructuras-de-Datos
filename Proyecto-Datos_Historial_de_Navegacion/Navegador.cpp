#include "Navegador.h"
#include <iostream>

Navegador::Navegador() : indicePestaniaActual(0), modoIncognito(false) {
    nuevaPestania(); // Inicia con una pestaña abierta
}

void Navegador::nuevaPestania() {
    pestanias.push_back(std::make_shared<Pestania>());
    indicePestaniaActual = static_cast<int>(pestanias.size()) - 1;
    std::cout << "Nueva pestaña creada. Total de pestañas: " << pestanias.size() << std::endl;
}

void Navegador::cerrarPestania() {
    if (pestanias.size() > 1) {
        pestanias.erase(pestanias.begin() + indicePestaniaActual);
        if (indicePestaniaActual >= static_cast<int>(pestanias.size())) {
            indicePestaniaActual = static_cast<int>(pestanias.size()) - 1;
        }
        std::cout << "Pestaña cerrada. Total de pestañas: " << pestanias.size() << std::endl;
    }
    else {
        std::cout << "No se puede cerrar la única pestaña abierta." << std::endl;
    }
}

void Navegador::cambiarPestania(int direccion) {
    if (direccion > 0 && indicePestaniaActual < static_cast<int>(pestanias.size()) - 1) {
        ++indicePestaniaActual;
    }
    else if (direccion < 0 && indicePestaniaActual > 0) {
        --indicePestaniaActual;
    }
    std::cout << "Cambiado a pestaña " << indicePestaniaActual + 1 << std::endl;
}

void Navegador::navegarA(const std::string& url) {
    pestanias[indicePestaniaActual]->navegar(url);
    std::cout << "Navegando a " << url << " en pestaña " << indicePestaniaActual + 1 << std::endl;
}

void Navegador::cambiarModoIncognito(bool incognito) {
    modoIncognito = incognito;
    for (auto& pestania : pestanias) {
        pestania->cambiarModoIncognito(incognito);
    }
    std::cout << "Modo incógnito " << (modoIncognito ? "activado." : "desactivado.") << std::endl;
}

void Navegador::agregarMarcador(const std::string& url, const std::string& etiqueta) {
    marcador.agregarMarcador(url, etiqueta);
    std::cout << "Marcador agregado para " << url << " con etiqueta '" << etiqueta << "'." << std::endl;
}

void Navegador::buscarMarcadores(const std::string& etiqueta) {
    marcador.buscarMarcadores(etiqueta);
}

void Navegador::importarHistorial(const std::string& archivo) {
    // Falta implementar
}

void Navegador::exportarHistorial(const std::string& archivo) {
    // Falta implementar
}

void Navegador::importarMarcadores(const std::string& archivo) {
    // Falta implementar
}

void Navegador::exportarMarcadores(const std::string& archivo) {
    // Falta implementar
}

void Navegador::mostrarMenu() {
    // Falta implementar
}

void Navegador::manejarInputUsuario() {
    // Falta implementar
}
