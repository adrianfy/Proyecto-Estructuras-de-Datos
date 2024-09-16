#include "Tab.h"

Tab::Tab()
{
    this->iteradorActual = historial.end();
	this->modoIncognito = false;
	this->paginaActual = Pagina();
}

std::list<Pagina>& Tab::getHistorial()
{
    return historial;
}

Pagina Tab::getPaginaActual()
{
    return paginaActual;
}

void Tab::navegar(Pagina& url)
{
    if (modoIncognito == false) {
        historial.push_back(url);
		iteradorActual = std::prev(historial.end());
    }
    paginaActual = url;
}

void Tab::retroceder()
{
    if (iteradorActual != historial.begin()) {
		iteradorActual--;
        paginaActual = *iteradorActual;
    }
}

void Tab::avanzar()
{
    if (iteradorActual != std::prev(historial.end())) {
        iteradorActual++;
        paginaActual = *iteradorActual;
    }
}

void Tab::cambiarModoIncognito(bool incognito)
{
    modoIncognito = incognito;
}

bool Tab::esIncognito()
{
    return modoIncognito;
}

Tab::~Tab()
{
}
