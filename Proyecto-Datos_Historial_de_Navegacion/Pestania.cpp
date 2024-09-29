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
    size_t urlLength = pagina->getUrl().size();
    archivo.write(reinterpret_cast<char*>(&urlLength), sizeof(urlLength)); // Escribir tamaño de la URL
    archivo.write(pagina->getUrl().c_str(), urlLength); // Escribir contenido de la URL

    archivo.write(reinterpret_cast<char*>(&modoIncognito), sizeof(modoIncognito)); // Escribir modo incógnito
}

void Pestania::deserializar(std::ifstream& archivo)
{
    size_t urlLength;
    archivo.read(reinterpret_cast<char*>(&urlLength), sizeof(urlLength)); // Leer tamaño de la URL

    char* buffer = new char[urlLength + 1]; // Crear buffer para almacenar la URL
    archivo.read(buffer, urlLength); // Leer contenido de la URL
    buffer[urlLength] = '\0'; // Añadir terminador nulo
    pagina = new Pagina(buffer); // Asignar la URL
    delete[] buffer;

    archivo.read(reinterpret_cast<char*>(&modoIncognito), sizeof(modoIncognito)); // Leer modo incógnito
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
