#include "Navegador.h"
#include <iostream>

Navegador::Navegador() {
    this->modoIncognito = false;
    this->indiceTabActual = 0;
    nuevoTab();
}

void Navegador::nuevoTab() {
    tab.push_back(std::make_shared<Tab>());
    indiceTabActual = static_cast<int>(tab.size()) - 1;
    std::cout << "Nueva pestaña creada. Total de pestañas: " << tab.size() << std::endl;
}

void Navegador::cerrarTab() {
    if (tab.size() > 1) {
        tab.erase(tab.begin() + indiceTabActual);
        if (indiceTabActual >= static_cast<int>(tab.size())) {
            indiceTabActual = static_cast<int>(tab.size()) - 1;
        }
        std::cout << "Pestaña cerrada. Total de pestañas: " << tab.size() << std::endl;
    }
    else {
        std::cout << "No se puede cerrar la única pestaña abierta." << std::endl;
    }
}

void Navegador::cambiarTab(int direccion) {
    if (direccion > 0 && indiceTabActual < static_cast<int>(tab.size()) - 1) {
        ++indiceTabActual;
    }
    else if (direccion < 0 && indiceTabActual > 0) {
        --indiceTabActual;
    }
    std::cout << "Cambiado a pestaña " << indiceTabActual + 1 << std::endl;
}

void Navegador::navegarA(std::string& url) {
   tab[indiceTabActual]->navegar(url);
    std::cout << "Navegando a " << url << " en pestaña " << indiceTabActual + 1 << std::endl;
}

void Navegador::cambiarModoIncognito(bool incognito) {
    modoIncognito = incognito;
    for (auto& pestania : tab) {
        pestania->cambiarModoIncognito(incognito);
    }
    std::cout << "Modo incógnito " << (modoIncognito ? "activado." : "desactivado.") << std::endl;
}

/*void Navegador::agregarMarcador(std::string& url, std::string& etiqueta) {
    marcador.agregarMarcador(url, etiqueta);
    std::cout << "Marcador agregado para " << url << " con etiqueta '" << etiqueta << "'." << std::endl;
}

void Navegador::buscarMarcadores(const std::string& etiqueta) {
    marcador.buscarMarcadores(etiqueta);
}*/

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

Navegador::~Navegador()
{
}
