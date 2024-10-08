#include "Pestania.h"

Pestania::Pestania() {
    this->historial = new Historial();
    this->modoIncognito = false;
    this->pagina = nullptr;
}

Pestania::Pestania(bool modoIncognito) {
    this->modoIncognito = modoIncognito;
    this->historial = new Historial();
    this->pagina = nullptr;
}

Pagina* Pestania::getPaginaActual() {

    return pagina;
}

Historial* Pestania::getHistorial()
{
    return historial;
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

void Pestania::cambiarModoIncognito(bool incognito) {
    this->modoIncognito = incognito;
}

bool Pestania::esIncognito() {
    return modoIncognito;
}

void Pestania::serializar(std::ofstream& archivo)
{
    historial->serializar(archivo);
    archivo.write(reinterpret_cast<char*>(&modoIncognito), sizeof(modoIncognito));
}

void Pestania::deserializar(std::ifstream& archivo)
{
    historial->deserializar(archivo);
    archivo.read(reinterpret_cast<char*>(&modoIncognito), sizeof(modoIncognito));

    pagina = historial->getUltimaPaginaVisitada();

}

std::string Pestania::mostrarHistorial() {
    return historial->toString();
}

std::string Pestania::toString()
{
    std::stringstream s;
	s << "Visitando: " << pagina->toString() << std::endl;
    return std::string();
}

Pestania::~Pestania() {
    delete this->historial;
}