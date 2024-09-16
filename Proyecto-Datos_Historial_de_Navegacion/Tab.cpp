#include "Tab.h"

Tab::Tab()
{
	this->historial = Historial();
	this->modoIncognito = false;
    this->paginaActual = nullptr;
}

Pagina* Tab::getPaginaActual()
{
    return paginaActual;
}

void Tab::navegar(Pagina* url)
{
    if (modoIncognito == false) {
        historial.agregarEntrada(url);
    }
    paginaActual = url;
}

void Tab::retroceder()
{
    urlActual = historial.retroceder();
}

void Tab::avanzar()
{
    urlActual = historial.avanzar();
}

void Tab::cambiarModoIncognito(bool incognito)
{
    modoIncognito = incognito;
}

bool Tab::esIncognito()
{
    return modoIncognito;
}

std::vector<Pagina*> Tab::getHistorial() const
{
    return historial;;
}

Pagina* Tab::getPaginaActual() const
{
    if (indiceActual >= 0 && indiceActual < historial.size()) {
        return historial[indiceActual];
    }
    return nullptr;
}

Tab::~Tab()
{
}
