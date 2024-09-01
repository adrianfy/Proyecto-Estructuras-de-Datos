#include "Navegador.h"
#include <iostream>

Navegador::Navegador() : indicePestaniaActual(0), modoIncognito(false) {
    nuevaPestania(); // Inicia con una pesta�a abierta
}

void Navegador::nuevaPestania() {
    pestanias.push_back(std::make_shared<Pestania>());
    indicePestaniaActual = static_cast<int>(pestanias.size()) - 1;
    std::cout << "Nueva pesta�a creada. Total de pesta�as: " << pestanias.size() << std::endl;
}

void Navegador::cerrarPestania() {
    if (pestanias.size() > 1) {
        pestanias.erase(pestanias.begin() + indicePestaniaActual);
        if (indicePestaniaActual >= static_cast<int>(pestanias.size())) {
            indicePestaniaActual = static_cast<int>(pestanias.size()) - 1;
        }
        std::cout << "Pesta�a cerrada. Total de pesta�as: " << pestanias.size() << std::endl;
    }
    else {
        std::cout << "No se puede cerrar la �nica pesta�a abierta." << std::endl;
    }
}

void Navegador::cambiarPestania(int direccion) {
    if (direccion > 0 && indicePestaniaActual < static_cast<int>(pestanias.size()) - 1) {
        ++indicePestaniaActual;
    }
    else if (direccion < 0 && indicePestaniaActual > 0) {
        --indicePestaniaActual;
    }
    std::cout << "Cambiado a pesta�a " << indicePestaniaActual + 1 << std::endl;
}

void Navegador::navegarA(const std::string& url) {
    pestanias[indicePestaniaActual]->navegar(url);
    std::cout << "Navegando a " << url << " en pesta�a " << indicePestaniaActual + 1 << std::endl;
}

void Navegador::cambiarModoIncognito(bool incognito) {
    modoIncognito = incognito;
    for (auto& pestania : pestanias) {
        pestania->cambiarModoIncognito(incognito);
    }
    std::cout << "Modo inc�gnito " << (modoIncognito ? "activado." : "desactivado.") << std::endl;
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
