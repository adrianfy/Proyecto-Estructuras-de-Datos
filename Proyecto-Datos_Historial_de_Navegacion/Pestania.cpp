#include "Pestania.h"

Pestania::Pestania() {
    this->historial = new Historial();
    this->modoIncognito = false;
    this->pagina = nullptr;
    this->gestorMarcadores = new GestorMarcador();
}

Pestania::Pestania(bool modoIncognito) {
    this->modoIncognito = modoIncognito;
    this->historial = new Historial();
    this->pagina = nullptr;
    this->gestorMarcadores = new GestorMarcador();
}

Pagina* Pestania::getPaginaActual() {
    return pagina;
}

void Pestania::navegar(Pagina* url) {
    if (!modoIncognito) {
        historial->agregarEntrada(url);
    }
    pagina = url;
}

void Pestania::retroceder() {
    Pagina* pag = historial->retroceder();
    if (pag != nullptr) {
        pagina = pag;
    }
}

void Pestania::avanzar() {
    Pagina* pag = historial->avanzar();
    if (pag != nullptr) {
        pagina = pag;
    }
}

//void Pestania::cambiarModoIncognito(bool incognito) {
//    modoIncognito = incognito;
//}

bool Pestania::esIncognito() {
    return modoIncognito;
}

std::string Pestania::mostrarHistorial() {
    return historial->toString();
}

std::string Pestania::mostrarMarcadores()
{
    return gestorMarcadores->toString();
}

Pestania::~Pestania() {
    delete this->historial;
}
